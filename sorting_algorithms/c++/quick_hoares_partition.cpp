#include <bits/stdc++.h>
using namespace std;

//Calculates the pivot as the first element and drops its index after positioning it at the right place 

int hoares(int a[], int l, int h)
{
    int pi = a[l];
    int l = 0;
    int i = l - 1, j = h - 1;
    while (true)
    {
        do
        {
            i++;
        } while (a[i] < pi);
        do
        {
            j--;
        } while (a[j] > pi);
        if (i >= j)
        {
            return j;
        }
        int x = a[j];
        a[j] = a[i];
        a[i] = x;
    }
    return;
}

void quick_hoares(int a[], int l, int h)
{
    if (l < h)
    {
        int p = hoares(a, l, h);
        quick_hoares(a, l, p);
        quick_hoares(a, p + 1, h);
    }
}