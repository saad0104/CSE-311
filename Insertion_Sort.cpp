// Insertion Sort

// Insertion sort is a sorting algorithm that places an unsorted
//      element at its suitable place in each iteration.


// O(n^2)
// Use Case - Small Array, few elements left to be sorted



//  *** Algorithm ***

// insertionSort(array)
//   mark first element as sorted
//   for each unsorted element X
//     'extract' the element X
//     for j <- lastSortedIndex down to 0
//       if current element j > X
//         move sorted element to the right by 1
//     break loop and insert X here
// end insertionSort




#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int arr[], int size)
{

    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {9, 5, 1, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    InsertionSort(arr, size);
    cout << "Sorted Array:" << endl;
    printArray(arr, size);

    return 0;
}