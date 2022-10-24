#include <iostream>

using namespace std;

bool is_prime(unsigned n, int i = 2)
{
    if (n <= 2)
        return true;

    if (n % i == 0)
        return false;

    if (i * i > n)
        return true;

    return is_prime(n, i + 1);
}

int main()
{
    cout << (is_prime(7) ? "Y" : "N");
}