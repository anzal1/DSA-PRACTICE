#include <bits/stdc++.h>
using namespace std;

int maxwithoutconsec(int a[], int n)
{
    if (n == 1)
    {
        return a[0];
    }
    int prev_prev = a[0];
    int prev = max(a[1], a[0]);
    int res = prev;
    for (int i = 2; i < n; i++)
    {
        int temp = prev;
        prev = max(prev_prev + a[i], prev);
        prev_prev = temp;
        res = max(res, prev);
    }
    return res;
}