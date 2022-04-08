#include<bits/stdc++.h>
using namespace std;


//given a array pick m packets such that there is min difference beteween the given packets


int distri(int a[],int m,int n)
{
    if(m>n)return n;
    sort(a,a+n);
    int res=a[m-1]-a[0];
    for(int i=1;i+m-1<n;i++)
    {
    res =min(res,a[i+m-1]-a[i]);
    }
    return res;

}