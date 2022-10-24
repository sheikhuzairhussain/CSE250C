#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int to_decimal(string source, int source_base)
{
    int number = 0;

    for (int i = 0; i < source.size(); i++)
    {
        int face_value;

        if (source[i] >= 'A' && source[i] <= 'F')
            face_value = source[i] - 'A' + 10;
        else if (source[i] >= '0' && source[i] <= '9')
            face_value = source[i] - '0';

        number += face_value * pow(source_base, source.size() - 1 - i);
    }

    return number;
}

void print_in_base(string source, int source_base, int destination_base)
{
    int number = to_decimal(source, source_base);

    if (source == "0")
        return;

    print_in_base(to_string(number / destination_base), 10, destination_base);

    int remainder = number % destination_base;

    if (remainder > 9)
        cout << static_cast<char>('A' + remainder - 10);
    else
        cout << remainder;
}

int main()
{
    print_in_base("FF", 16, 10);
}