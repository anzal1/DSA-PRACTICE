#include <bits/stdc++.h>
using namespace std;

int minjumps(int a[], int n)
{
    int dp[n];
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (i - a[j] >= 0)
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[n - 1];
}