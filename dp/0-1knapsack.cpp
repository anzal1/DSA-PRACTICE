#include <bits/stdc++.h>
using namespace std;

int knapsack(int v[], int w[], int n, int W)
{
    int i, j;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (w[i - 1] <= j)
                K[i][j] = max(v[i - 1] + K[i - 1][j - w[i - 1]], K[i - 1][j]);
            else
                K[i][j] = K[i - 1][j];
        }
    }
    return K[n][W];
}