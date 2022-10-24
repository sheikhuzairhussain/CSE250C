#include <iostream>

using namespace std;

template <typename T>
class Sort
{
    int size;
    T *array;

public:
    Sort(T array[], int size) : array(array), size(size) {}

    void bubble()
    {
        bool swap;
        do
        {
            swap = false;
            for (int j = 0; j < size - 1; j++)
            {
                if (array[j] > array[j + 1])
                {
                    swap = true;
                    T temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        } while (swap);
    }

    void insertion()
    {
        int key, i, j;
        for (i = 1; i < size; i++)
        {
            key = array[i];
            j = i - i;
            while (j >= 0 && array[j] > key)
            {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
    }

    void selection()
    {
        for (int i = 0; i < size; i++)
        {
            int smallestIndex = i;

            for (int j = i + 1; j < size; j++)
                if (array[j] < array[smallestIndex])
                    smallestIndex = j;

            int temp = array[i];
            array[i] = array[smallestIndex];
            array[smallestIndex] = temp;
        }
    }
};

void print(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    int size = 8;
    int array[] = {3, 10, 12, -1, 2, 0, 2, 4};

    print(array, size);
    Sort(array, size).bubble();
    print(array, size);
}
