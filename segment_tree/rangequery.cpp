#include <bits/stdc++.h>
using namespace std;

int st[40];

int getSum(int qs, int qe, int ss, int se, int si)
{
    if (qs <= ss && qe >= se)
        return st[si];
    if (se < qs || ss > qe)
        return 0;
    int mid = (ss + se) / 2;
    return getSum(qs, qe, ss, mid, si * 2 + 1) + getSum(qs, qe, mid + 1, se, si * 2 + 2);
}