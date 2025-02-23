// Time Complexity -->> O(n^2)

#include <bits/stdc++.h>
using namespace std;

void Bubblesort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int ptr = 0;
        while (ptr < n - i)
        {

            // Ascending Order
            // if (arr[ptr] > arr[ptr + 1])
            // {
            //     int temp;
            //     temp = arr[ptr + 1];
            //     arr[ptr + 1] = arr[ptr];
            //     arr[ptr] = temp;
            // }

            // Descending Order
            if (arr[ptr] < arr[ptr + 1])
            {
                int temp;
                temp = arr[ptr];
                arr[ptr] = arr[ptr + 1];
                arr[ptr + 1] = temp;
            }
            ptr++;
        }
    }
}

int main()
{
    int size = 10;
    int arr[size] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

    Bubblesort(arr, size);

    for (int i = 0; i <= size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}