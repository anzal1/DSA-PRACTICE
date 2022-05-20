#include <bits/stdc++.h>
using namespace std;

int longestCommonSub(int a[], int n)
{
    int dp[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

// solving in nlogn
int longestCommonSubtwo(int a[], int n)
{
    int tail[n], len = 1;
    tail[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] == tail[len - 1])
        {
            tail[len++] = a[i];
        }
        else if (a[i] < tail[len - 1])
        {
            tail[len++] = a[i];
        }
        else
        {
            int l = 0, r = len - 1;
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (a[i] < tail[mid])
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            tail[l] = a[i];
        }
    }
    return len;
}

