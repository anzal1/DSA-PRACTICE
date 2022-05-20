#include <bits/stdc++.h>
using namespace std;

int eggdrop(int e, int f)
{
    int dp[f + 1][e + 1];
    for (int i = 0; i <= f; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = i;
    }
    for (int i = 0; i <= e; i++)
    {
        dp[0][i] = 0;
        dp[1][i] = i;
    }
    for (int i = 2; i <= f; i++)
    {
        for (int j = 2; j <= e; j++)
        {
            dp[i][j] = INT_MAX;
            for (int k = 1; k <= j; k++)
            {
                dp[i][j] = min(dp[i][j], max(dp[i - 1][k - 1], dp[i - 1][j - k]) + 1);
            }
        }
    }
}