#include <iostream>

using namespace std;

template <typename T>
class DoublyLinkedList
{
    class Node
    {
    public:
        T value;
        Node *previous;
        Node *next;
        Node(T value, Node *previous, Node *next) : value(value), previous(previous), next(next) {}
    };

    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_front(T value)
    {
        Node *newNode = new Node(value, nullptr, head);

        // Empty list
        if (!head && !tail)
        {
            head = tail = newNode;
            return;
        }

        // General case
        head->previous = newNode;
        head = newNode;
    }

    void push_back(T value)
    {
        Node *newNode = new Node(value, tail, nullptr);

        // Empty list
        if (!head && !tail)
        {
            head = tail = newNode;
            return;
        }

        // General case
        tail->next = newNode;
        tail = newNode;
    }

    void push_after(T key, T value)
    {
        Node *current = head;

        while (current && current->value != key)
            current = current->next;

        if (!current)
        {
            cout << "Error: Key not found.";
            return;
        }

        Node *newNode = new Node(value, current, current->next);

        // Inserting after tail
        if (current == tail)
        {
            tail->next = newNode;
            tail = newNode;
            return;
        }

        // General case
        current->next->previous = newNode;
        current->next = newNode;
    }

    void remove(T key)
    {
        Node *current = head;

        while (current && current->value != key)
            current = current->next;

        if (!current)
        {
            cout << "Error: Key not found.";
            return;
        }

        // Singleton list
        if (current == head && current == tail)
        {
            head = tail = nullptr;
            delete current;
            return;
        }

        // Removing head
        if (current == head)
        {
            head->next->previous = nullptr;
            head = head->next;
            delete current;
            return;
        }

        // Removing tail
        if (current == tail)
        {
            tail->previous->next = nullptr;
            tail = tail->previous;
            delete current;
            return;
        }

        // General case
        current->previous->next = current->next;
        current->next->previous = current->previous;
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