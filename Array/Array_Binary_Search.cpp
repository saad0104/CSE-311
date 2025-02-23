// Time complexity --> O(log n)
// Array have to be sorted

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int size, int item)
{
    int loc = 0;
    int beg = 0;
    int end = size;
    int mid = (beg + end) / 2;

    while (beg <= end && arr[mid] != item)
    {
        if (item < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
        mid = (beg + end) / 2;
    }

    if (arr[mid] == item)

    {
        loc = mid;
    }
    else
    {
        loc = -1;
    }
    return loc;
}

int main()
{
    int size = 10;
    int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int item = 6;

    cout << "Item found at: " << binarySearch(arr, size, item) << endl;

    return 0;
}