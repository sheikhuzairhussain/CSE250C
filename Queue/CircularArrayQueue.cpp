#include <iostream>
#include <optional>

using namespace std;

template <typename T, int max_size>
class CircularArrayQueue
{
    int first;  // Position for next dequeue
    int cursor; // Position for next enqueue (empty)
    int size;

    T queue[];

public:
    CircularArrayQueue() : first(0), cursor(0), size(0) {}

    void enqueue(T value)
    {
        if (size == max_size)
        {
            cout << "Error: Queue full" << endl;
            return;
        }

        cout << "Inserting at " << (cursor) % max_size << endl;
        queue[(cursor++) % max_size] = value;
        size++;
    }

    optional<T> dequeue()
    {
        if (size == 0)
        {
            cout << "Error: Queue empty" << endl;
            return nullopt;
        }

        cout << "Removing from " << (first) % max_size << endl;
        size--;
        return queue[(first++) % max_size];
    }

    void display()
    {
        for (int i = 0; i < max_size; i++)
        {
            cout << queue[i] << " ";
        }
    }
};