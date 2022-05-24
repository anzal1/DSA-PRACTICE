#include <bits/stdc++.h>
using namespace std;

int bitree[1001];

int getSum(int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += bitree[i];
        i -= i & (-i);
    }
    return sum;
}

int update(int i, int val)
{
    while (i <= 1000)
    {
        bitree[i] += val;
        i += i & (-i);
    }
}