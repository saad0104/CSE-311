// Counting Sort

// Counting sort is a sorting algorithm that sorts the elements of an array 
// by counting the number of occurrences of each unique element in the array.


// O(n+k)  
//  n -> length of array, k = highest element value

// Stable
// When values of the array are very small.

// ***Algorithm ***

// countingSort(array, size)
//   max <- find largest element in array
//   initialize count array with all zeros
//   for j <- 0 to size
//     find the total count of each unique element and
//     store the count at jth index in count array
//   for i <- 1 to max
//     find the cumulative sum and store it in count array itself
//   for j <- size down to 1
//     restore the elements to array
//     decrease count of each element restored by 1


#include <bits/stdc++.h>
using namespace std;

void CountingSort(int arr[], int size)
{
    int max = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int freq[max + 1] = {0};
    int sorted[size];

    for (int i = 0; i < size; i++)
    {
        freq[arr[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        freq[i] += freq[i - 1];
    }
    int s = size - 1;
    while (s >= 0)
    {
        sorted[freq[arr[s]] - 1] = arr[s];
        freq[arr[s]]--;
        s--;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = sorted[i];
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
    int arr[]{10, 34, 6, 1, 23, 45, 6, 12, 6, 5, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    // cout << size << endl;
    CountingSort(arr, size);
    cout << "sorted Array: " << endl;
    printArray(arr, size);
}