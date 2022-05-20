#include<bits/stdc++.h>
using namespace std;


int validbst(int n)
{
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=INT_MAX;
        for(int j=1;j<=i;j++)
        {
            dp[i]=min(dp[i],max(dp[i-j],dp[i-j-1])+1);
        }
    }
    return dp[n];
}


//catalan numbers res(n) = 1/(n+1) 2nCn

