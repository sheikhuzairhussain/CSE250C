#include <iostream>
#include <unordered_map>

using namespace std;

long long fibonacci(int n)
{
    if (n <= 2)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "The nth Fibonacci number is: " << fibonacci(n);
}