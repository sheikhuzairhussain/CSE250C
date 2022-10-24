#include <iostream>
#include "ArrayStack.cpp"

using namespace std;

int main()
{
    ArrayStack<int, 10> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();
}