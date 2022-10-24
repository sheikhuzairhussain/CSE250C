#include <iostream>
#include "DoublyLinkedList.cpp"

int main()
{
    DoublyLinkedList<int> list;

    list.push_front(20);
    list.push_front(10);

    list.push_back(30);

    list.push_after(20, 25);
    list.push_after(30, 40);

    list.remove(40);
    list.remove(10);
    list.remove(25);

    list.display();
}