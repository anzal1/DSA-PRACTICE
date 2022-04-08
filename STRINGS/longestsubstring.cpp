#include<bits/stdc++.h>
using namespace std;


int longestDist(string &str)
{
    int n=str.length(),res=0;
    vector<int>prev(256,-1);
    int i=0;
    for(int j=0;j<n;j++)
    {
        i=max(i,prev[j]+1);
        int maxend=j-i+1;
        res=max(res,maxend);
        prev[str[j]]=j;

    }
return res;
}