#include <iostream>
#include "CircularLinkedList.cpp"

int main()
{
    CircularLinkedList<int> list;

    list.push(10);
    list.push(20);
    list.push(30);
    list.push(40);

    // list.push_after(20, 25);
    // list.push_after(30, 40);

    // list.remove(40);
    // list.remove(10);

    // list.push_before(20, 10);

    list.display();
}