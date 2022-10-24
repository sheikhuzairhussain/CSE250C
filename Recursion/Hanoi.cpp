#include <iostream>
using namespace std;

void hanoi(int n, char beginning, char mid, char end)
{
    if (n == 1)
    {
        cout << beginning << " -> " << end << endl;
        return;
    }

    hanoi(n - 1, beginning, end, mid);
    cout << beginning << " -> " << end << endl;
    hanoi(n - 1, mid, beginning, end);
}

int main()
{
    hanoi(4, 'A', 'B', 'C');
}