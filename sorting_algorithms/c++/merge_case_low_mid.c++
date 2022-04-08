#include <bits/stdc++.h>
using namespace std;


//algo to sort an arrya with haf sorted arrays

void merge_sorter(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] <= b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else
        {
            cout << b[i] << " ";
        }
    }
    while (i < m)
    {
        cout << a[i] << " ";
        i++;
    }
    while (j < m)
    {
        cout << b[j] << " ";
        j++;
    }
}

void sorter(int a[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1];
    int right[n2];
    for (int i = 0; i < n1; i++)
    {
        left[i] = a[low + i];
    };
    for (int i = 0; i < n2; i++)
    {
        right[i] = a[n1 + i];
    };

    merge_sorter(left, right, n1, n2);
}
