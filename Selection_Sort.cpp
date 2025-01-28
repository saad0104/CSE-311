// Selection Sort

// Selection sort is a sorting algorithm that selects the smallest element 
// from an unsorted list in each iteration and places that 
// element at the beginning of the unsorted list.

// O(n^2)
//  can be applied when list is small, checking of all the elements is compulsory


// *** Algorithm ***

// selectionSort(array, size)
//   for i from 0 to size - 1 do
//     set i as the index of the current minimum
//     for j from i + 1 to size - 1 do
//       if array[j] < array[current minimum]
//         set j as the new current minimum index
//     if current minimum is not i
//       swap array[i] with array[current minimum]
// end selectionSort




#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int arr[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {20, 12, 10, 15, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    SelectionSort(arr, size);

    cout << "Sorted Array : " << endl;
    printArray(arr, size);

    return 0;
}