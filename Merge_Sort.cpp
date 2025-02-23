// Merge Sort

// In simple terms, we can say that the process of merge sort is to
//            divide the array into two halves,
//           sort each half, and then merge the sorted halves back together.

// O(nlogn)
// preferred algorithm for sorting Linked lists.

// *** Algorithm ***

// MergeSort(A, p, r):
//     if p > r
//         return
//     q = (p+r)/2
//     mergeSort(A, p, q)
//     mergeSort(A, q+1, r)
//     merge(A, p, q, r)

#include <bits/stdc++.h>
using namespace std;

// void merge(int arr[], int l, int mid, int h)
void merge(vector<int>&arr, int l, int mid, int h)
{
    int n1 = mid - l + 1;
    int n2 = h - mid;

    vector<int> vc1(n1);
    vector<int> vc2(n2);

    for (int i = 0; i < n1; i++)
    {
        vc1[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        vc2[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (vc1[i] <= vc2[j])
        {
            arr[k] = vc1[i];
            i++;
        }
        else
        {
            arr[k] = vc2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = vc1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = vc2[j];
        j++;
        k++;
    }
}

// void mergesort(int arr[], int l, int h)
void mergesort(vector<int> &arr, int l, int h)
{
    if (l < h)
    {
        int mid = l + (h - l) / 2;

        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, h);

        merge(arr, l, mid, h);
    }
}
// void printArray(int arr[], int size)
void printArray(vector<int> &arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // int arr[] = {6, 5, 12, 10, 9, 1};
    // int size = sizeof(arr) / sizeof(arr[0]);

    // mergesort(arr, 0, size - 1);
    // printArray(arr, size);

    vector<int> arr = {6, 5, 12, 10, 9, 1};
    int size = arr.size();

    mergesort(arr, 0, size - 1);
    cout << "Sorted Array : " << endl;

    printArray(arr);

    return 0;
}