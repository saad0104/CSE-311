// done

#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end)
{

    int pivot = arr[end];
    int p_index = start;

    for (int i = start; i <= end - 1; i++)
    {

        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[p_index]);
            p_index++;
        }
        // swap(arr[p_index], pivot);
        // return p_index;
    }
    swap(arr[p_index], arr[end]);
    return p_index;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int p_index = partition(arr, start, end);
        quickSort(arr, start, p_index - 1);
        quickSort(arr, p_index + 1, end);
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
    int n = 8;
    // cin >> n;
    // int arr[8] = {2, 4, 1, 6, 3, 8, 5, 7};
    int arr[8] = {102, 45, 23, 57, 890, 87, 98, 0};
    // int arr[8] = {9, 8, 7, 6, 5, 4, 3, 2};

    quickSort(arr, 0, n - 1);

    cout << "After sorting : ";
    printArray(arr, n);

    return 0;
}