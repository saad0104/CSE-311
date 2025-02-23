// Deletion of a directed index
// Index given

#include <bits/stdc++.h>
using namespace std;

void Deletion(int arr[], int n, int k)
{
    int j = k;

    for (int j = k; j < n - 1; j++)
    {
        arr[j] = arr[j + 1];
    }
    // n = n - 1;
}

int main()
{
    int n = 10;
    int k = 4;
    int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int item = arr[k];

    Deletion(arr, n, k);
    n = n - 1;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}