#include<bits/stdc++.h>
using namespace std;


bool com( pair<int,int> a,pair<int,int>b)
{
    return a.second<b.second;
}

int activity(pair<int,int>a[],int n)
{
    sort(a,a+n,com);
    int prev=0;
    int res=1;
    for(int curr=1;curr<n;curr++)
    {
        if(a[curr].first>=a[prev].second)
        {
            res++;
            prev=curr;
        }
    }
    return res;
    
}