#include <iostream>

using namespace std;

template <typename T>
class CircularLinkedList
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
    CircularLinkedList() : head(nullptr), tail(nullptr) {}

    void push(T value)
    {
        Node *newNode = new Node(value, head);

        // If list is empty
        if (!head && !tail)
        {
            newNode->next = newNode;
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }

    void push_before(T key, T value)
    {
    }

    void push_after()
    {
    }

    void remove()
    {
    }

    bool exists()
    {
        return false;
    }

    void display()
    {
        if (!head)
            // Empty list
            return;

        Node *current = head;

        do
        {
            cout << current->value << "->";
            current = current->next;
        } while (current != head);

        cout << "END";
    }
};