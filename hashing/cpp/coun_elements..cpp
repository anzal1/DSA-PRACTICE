#include<bits/stdc++.h>
using namespace std;


int counDist(int a[],int n)
{
    unordered_set<int>s;
    while(n--)
    {
        s.insert(a[n]);
        
    }
    return s.size();
}


//efficient 


int Countdist(int a[],int n)
{
    unordered_set<int>s(a,a+n);
    return s.size();
}