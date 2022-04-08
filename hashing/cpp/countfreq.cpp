#include<bits/stdc++.h>
using namespace std;

void freq(int a[],int n)
{
    unordered_map<int,int>h;
    for(int x:a)
    {
        h[x]++;
    }
    for(auto e:h)
    {
        cout<<e.first()<<" "<<e.second()<<endl;
    }
}