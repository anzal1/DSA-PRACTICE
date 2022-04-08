#include <bits/stdc++.h>
using namespace std;

int longestsybseqconsex(int a[], int n)
{
    int res=0;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }
    int curr=0;
    for (int i = 0; i < n; i++)
    {
        if(s.find(a[i]-1)==s.end())
        {
         curr =1;
         while(s.find(a[i]+curr)!=s.end())
{
    curr++;
}
res=max(res,curr);
        }

    }
    return res;
}