#include <iostream>

using namespace std;

template <typename T>
class LinkedList
{
    class Node
    {
    public:
        T value;
        Node *next;
        Node(T value, Node *next) : value(value), next(next) {}
    };

    Node *head;
    Node *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr){};

    void push_front(T value)
    {
        Node *newNode = new Node(value, this->head);
        this->head = newNode;

        if (!this->tail)
            this->tail = newNode;
    }

    void push_back(T value)
    {
        Node *newNode = new Node(value, nullptr);

        if (!tail)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void push_before(T key, T value)
    {
        Node *previous = nullptr;
        Node *current = head;

        while (current && current->value != key)
        {
            previous = current;
            current = current->next;
        }

        if (!current)
        {
            cout << "Error: Value not found." << endl;
            return;
        }

        Node *newNode = new Node(value, current);

        // Inserting before head
        if (current == head)
        {
            head = newNode;
            return;
        }

        // General case
        previous->next = newNode;
    }

    void push_after(T key, T value)
    {
        Node *current = head;

        while (current && current->value != key)
            current = current->next;

        if (!current)
        {
            cout << "Error: Value not found.";
            return;
        }

        Node *newNode = new Node(value, current->next);
        current->next = newNode;

        if (current == tail)
            tail = newNode;
    }

    void remove(T key)
    {
        Node *previous = nullptr;
        Node *current = head;

        while (current && current->value != key)
        {
            previous = current;
            current = current->next;
        }

        if (!current)
        {
            cout << "Error: Value not found.";
            return;
        }

        // Singleton list
        if (current == head && current == tail)
        {
            head = tail = nullptr;
            delete current;
            return;
        }

        // If we are deleting the head
        if (current == head)
        {
            head = head->next;
            delete current;
            return;
        }

        // If we are deleting the tail
        if (current == tail)
        {
            previous->next = nullptr;
            tail = previous;
            delete current;
            return;
        }

        // General case
        previous->next = current->next;
        delete current;
    }

    void display()
    {
        cout << "Head: " << head->value << ", Tail: " << tail->value << endl;

        Node *current = head;

        while (current)
        {
            cout << current->value << "->";
            current = current->next;
        }

        cout << "END";
    }
};