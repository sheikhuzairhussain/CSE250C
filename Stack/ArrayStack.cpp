#include <iostream>
#include <optional>

using namespace std;

template <typename T, int size>
class ArrayStack
{
    T stack[size];
    int cursor;

public:
    ArrayStack() : cursor(0) {}

    bool push(T value)
    {
        if (cursor == size)
        {
            cout << "Error: Stack is full.";
            return false;
        }

        stack[cursor++] = value;
        return true;
    }

    optional<T> pop()
    {
        if (cursor == 0)
        {
            cout << "Error: Stack is empty." << endl;
            return nullopt;
        }

        return stack[--cursor];
    }

    optional<T> peek()
    {
        if (cursor == 0)
        {
            cout << "Error: Stack is empty" << endl;
            return nullopt;
        }

        return stack[cursor - 1];
    }

    void display()
    {
        cout << "(Bottom) ";

        for (int i = 0; i < cursor; i++)
            cout << stack[i] << " ";

        cout << "(Top)";
    }
};