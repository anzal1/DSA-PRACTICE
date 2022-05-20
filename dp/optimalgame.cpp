#include <bits/stdc++.h>
using namespace std;

int optimalstrategy(int a[], int n)
{
    int dp[n][n];
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = max(a[i], a[i + 1]);
    }
    for (int gap = 3; gap < n; gap += 2)
    {
        int j = 0;
        for (int i = 0; i < n - gap; i++)
        {
            j = i + gap;
            dp[i][i + gap] = max(dp[i][i + gap - 2] + a[i + gap], dp[i + 1][i + gap] + a[i]);
        }
    }
    return dp[0][n - 1];
}

// 21