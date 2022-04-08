#include <bits/stdc++.h>
using namespace std;

// sort according to given theory
// 0s,1s.2s
// three way partioning
// partition around the range

// dutch national flag algorithm

void condi_sorter(int a[], int n)
{
    int l = 0, h = n - 1, mid = 0, x = 0;
    while (mid <= h)
    {
        if (a[mid] == 0)
        {
            x = a[mid];
            a[mid] = a[l];
            a[l] = x;
            l++;
            mid++;
        }
        else if (a[mid] == 1)
        {
            mid++;
        }
        else
        {
            x = a[mid];
            a[mid] = a[h];
            a[h] = x;
            h--;
        }
    }
}