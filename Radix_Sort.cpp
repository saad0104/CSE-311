// Radix sort is a sorting algorithm that sorts the elements by first grouping 
// the individual digits of the same place value. Then, sort the elements 
// according to their increasing/decreasing order.


// O(k(n + b)), 
//      k is the number of digits, n is the number of elements, and b is the base.
// places where there are numbers in large ranges.



//  *** Algorithm ***

// radixSort(array)
//   d <- maximum number of digits in the largest element
//   create d buckets of size 0-9
//   for i <- 0 to d
//     sort the elements according to ith place digits using countingSort

// countingSort(array, d)
//   max <- find largest element among dth place elements
//   initialize count array with all zeros
//   for j <- 0 to size
//     find the total count of each unique digit in dth place of elements and
//     store the count at jth index in count array
//   for i <- 1 to max
//     find the cumulative sum and store it in count array itself
//   for j <- size down to 1
//     restore the elements to array
//     decrease count of each element restored by 1




#include <bits/stdc++.h>
using namespace std;

int getMax(int array[], int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}


// has to be a stable sorting algo
void CountingSort(int arr[], int size, int place)
{
    const int max = 10;

    int freq[max] = {0};
    int sorted[size];

    for (int i = 0; i < size; i++)
    {
        freq[(arr[i]/place) % 10]++;
    }

    for (int i = 1; i < max; i++)
    {
        freq[i] += freq[i - 1];
    }
    int s = size - 1;
    while (s >= 0)
    {
        sorted[freq[(arr[s]/place) % 10] - 1] = arr[s];
        freq[(arr[s]/place) % 10]--;
        s--;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = sorted[i];
    }
}


void RadixSort(int arr[], int size)
{
    int max = getMax(arr, size);

    for (int place = 1; max / place > 0; place *= 10)
    {
        CountingSort(arr, size, place);

    }
}

void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main()
{
    int arr[] = {121, 432, 456, 345, 432, 123, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    RadixSort(arr, size);
    cout << "Sorted Array:" << endl;
    printArray(arr, size);

    return 0;
}