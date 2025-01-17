#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int item)
{
    int loc = 0;

    arr[n + 1] = item;

    while (arr[loc] != item)
    {
        loc++;
    }
    if (loc == n + 1)
    {
        return -1;
    }
    else
    {
        return loc;
    }
}

int main()
{
    int size = 10;
    int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int item = 6;

    cout << "Item found at: " << linearSearch(arr, size, item) << endl;

    return 0;
}