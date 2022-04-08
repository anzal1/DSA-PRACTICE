#include<bits/stdc++.h>
using namespace std;

int inter(int a[],int b[],int m,int n)
{
    unordered_set<int>s;
    for(int i=0;i<m;i++)
    {
        s.insert(a[i]);
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
   if(s.find(b[i])!=s.end())
   {
       res++;
       s.erase(b[i]);//s.remove() is java
   }
    }
    return res;

    }