#include <bits/stdc++.h>
using namespace std;

// Find the min diff between the pairs

int mindiff(int a[], int n)
{
    sort(a, a + n);
    int res = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        res = min(res, abs(a[i] - a[i - 1]));
    }
    return res;
}