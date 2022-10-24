#include <iostream>
#include "CircularArrayQueue.cpp"

using namespace std;

int main()
{
    CircularArrayQueue<int, 5> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    queue.enqueue(6);
    queue.dequeue();
    // queue.enqueue(7);

    queue.display();
}