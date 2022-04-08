#include<bits/stdc++.h>
using namespace std;


int unin(int a[],int b[],int n,int m)
{
unordered_set<int>s;
for(int i=0;i<n;i++)
{
    s.insert(a[i]);
}
for(int i=0;i<m;i++)
{
    s.insert(b[i]);

}
return s.size();
}
