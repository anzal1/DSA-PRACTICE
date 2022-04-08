#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int h)
{
    int pivot = a[h];
    int i = l - 1;
    for (int j = l; j <= h - 1; j++)
    {
        if (a[i] < pivot)
        {
            i++;
            int x = 0;
            x = a[j];
            a[j] = a[i];
            a[i] = x;
        }
        int x = a[i + 1];
        a[i + 1] = a[h];
        a[h] = x;
    }
}

int k_small(int a[], int n, int k)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int p = partition(a, l, r);
        if (p == k - 1)
        {
            return p;
        }
        else if (p > k - 1)
        {
            r = p - 1;
        }
        else
        {
            l = p + 1;
        }
    }
    return -1;
}