#include <bits/stdc++.h>
using namespace std;

void merge_sort(int a[], int low, int mid, int high)
{
    int left[mid - 1 + low];
    int right[high - mid];
    int n1 = mid - low + 1;
    int n2 = high - mid;
    for (int i = 0; i < n1; i++)
    {
        left[i] = a[low + i];
    }
    for (int j = 0; j < n2; j++)
    {
        left[j] = a[n1 + j];
    }
    int i=0,j=0;
    while (i < n1 && j < n2)
    {
        // if.....
    }
}