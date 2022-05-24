#include <bits/stdc++.h>
using namespace std;

int st[40];

int constructSt(int ss, int se, int si)
{
    if (ss == se)
    {
        st[si] = ss;
        return ss;
    }
    int mid = (ss + se) / 2;
    st[si] = constructSt(ss, mid, si * 2 + 1);
    st[si] = constructSt(mid + 1, se, si * 2 + 2);
    return st[si];
}