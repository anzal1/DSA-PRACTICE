#include <bits/stdc++.h>
using namespace std;

// uses count sort as a subroutine
// is a linear range sorter
void count_sorter(int a[], int n, int k)
{
    int count[k];
    for (int i = 0; i < k; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }
    for (int i = 1; i < k; i++)
    {
        count[i] = count[i - 1] + count[i];
    }
    int output[n];
    for (int i = n - 1; i > 0; i--)
    {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}

void radix_sorter(int a[], in n)
{
    int mx = a[0];
    for (int i = 1; i < n; ++)
    {
        if (a[i] > mx)
        {
            nx = a[i];
        }
    }
    for (int exp = 1; mx / exp > 0; exp++)
    {
        counting_sorter(a, n, exp);
    }
}
