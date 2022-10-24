#include <iostream>
#include <vector>
#include <cmath>
#include "ArrayStack.cpp"

using namespace std;

bool is_number(char c)
{
    return (c >= '0' && c <= '9');
}

int main()
{
    vector<char> postfix = {'5', '3', '+', '8', '2', '-', '*'}; // 48
    ArrayStack<int, 10> stack;

    for (char c : postfix)
    {
        if (is_number(c))
            stack.push(c - '0');
        else
        {
            int b = stack.pop().value();
            int a = stack.pop().value();

            switch (c)
            {
            case '+':
                stack.push(a + b);
                break;

            case '-':
                stack.push(a - b);
                break;

            case '*':
                stack.push(a * b);
                break;

            case '/':
                stack.push(a / b);
                break;

            case '^':
                stack.push(pow(a, b));
                break;

            default:
                cout << "Error: Invalid expression." << endl;
                return 1;
            }
        }
    }

    cout << "Value: " << stack.peek().value();
}