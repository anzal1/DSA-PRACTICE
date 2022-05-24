#include <bits/stdc++.h>
using namespace std;

int st[40];
int diff;
void updateQuery(int ss, int se, int i, int diff)
{
    if (i < ss || i > se)
    {

        return;
    }
    st[i] += diff;
    if (se > ss)
    {
        int mid = (ss + se) / 2;
        updateQuery(ss, mid, i * 2 + 1, diff);
        updateQuery(mid + 1, se, i * 2 + 2, diff);
   }
}