#include <bits/stdc++.h>
using namespace std;

// merge sort
// void merge(int arr[], int l, int mid, int h)
void merge(vector<int> &arr, int l, int mid, int h)
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

// bubble sort

void Bubblesort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int ptr = 0;
        while (ptr < n - i)
        {

            // Ascending Order
            if (arr[ptr] > arr[ptr + 1])
            {
                int temp;
                temp = arr[ptr + 1];
                arr[ptr + 1] = arr[ptr];
                arr[ptr] = temp;
            }

            // Descending Order
            // if (arr[ptr] < arr[ptr + 1])
            // {
            //     int temp;
            //     temp = arr[ptr];
            //     arr[ptr] = arr[ptr + 1];
            //     arr[ptr + 1] = temp;
            // }
            ptr++;
        }
    }
}

// Selection Sort

void SelectionSort(vector<int> &arr)
{
    int size = arr.size();
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
