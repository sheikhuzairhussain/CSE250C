#include <iostream>
#include "LinkedList.cpp"

int main()
{
    LinkedList<int> list;

    list.push_front(20);
    list.push_front(10);

    list.push_back(30);

    list.push_after(20, 25);
    list.push_after(30, 40);

    list.remove(40);
    list.remove(10);

    list.push_before(20, 10);

    list.display();
}