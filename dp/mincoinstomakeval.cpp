#include <bits/stdc++.h>
using namespace std;

int mincoinsval(int a[], int n, int val)
{
    int dp[val + 1];
    dp[0] = 0;
    for (int i = 1; i <= val; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (i - a[j] >= 0)
            {
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }
    return dp[val];
}