#include <bits/stdc++.h>
using namespace std;
//two arrays oof arrival and departure is given
int max_guests(int ar[], int dep[], int n, int m)
{

    sort(ar, ar + n);
    sort(dep, dep + m);
    int i = 1, j = 0, res = 1, curr = 1;
    while (i < n && j < n)
    {
        if (ar[i] <= dep[j])
        {
            curr++;
            i++;
        }
        else
        {
            curr--;
            j++;
        }
        res = max(res, curr);
    }
    return res;
}