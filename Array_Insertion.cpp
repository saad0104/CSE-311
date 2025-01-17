#include <bits/stdc++.h>
using namespace std;

void Insertion(int arr[], int n, int k, int item)
{

    int j = n;
    while (j >= k)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[k] = item;
    n = n + 1;
}

int main()
{
    int n = 10;
    int k = 5;
    int item = 15;
    int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Insertion(arr, n, k, item);
    for (int i = 0; i < n + 1; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}