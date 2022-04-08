#include <bits/stdc++.h>
using namespace std;

void selection(int a[], int n)
{
    // int tmp[n];
    for (int i = 0; i < n - 1; i++)
    {
        int min_ind = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_ind])
            {
                min_ind = a[j];
            }
        }
        int ab = a[i];
        a[i] = a[i + 1];
        a[i + 1] = ab;
    }
}