#include <bits/stdc++.h>
using namespace std;

int maxcut(int n, int a, int b, int c)
{
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1;
        if (i - a >= 0)
        {
            dp[i] = max(dp[i - a] + 1, dp[i]);
        }
        if (i - b >= 0)
        {
            dp[i] = max(dp[i - b] + 1, dp[i]);
        }
        if (i - c >= 0)
        {
            dp[i] = max(dp[i - c] + 1, dp[i]);
        }
        if (dp[i] != -1)
        {
            dp[i] = dp[i] + 1;
        }
    }
    return dp[n];
}