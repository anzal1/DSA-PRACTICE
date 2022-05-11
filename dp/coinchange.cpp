#include <bits/stdc++.h>
using namespace std;

int coinchange(int coins[], int n, int amount)
{
    int dp[amount + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 0; i <= amount; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i >= coins[j - 1])
            {
                dp[i][j] = dp[i][j - 1] + dp[i - coins[j - 1]][j];
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }

        return dp[amount][n];
    }
}