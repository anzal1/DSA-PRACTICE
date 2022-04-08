#include<bits/stdc++.h>
using namespace std;


void dfstoposort(vector<int> &v, int n)
{
    stack<int> s;
    vector<int> vis(n, 0);
    for(int i=0; i<n; i++)
    {
        if(vis[i]==0)
        {
            dfs(v, i, vis, s);
        }
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}


void dfs(vector<int> &v, int i, vector<int> &vis, stack<int> &s)
{
    vis[i]=1;
    for(int j=0; j<v.size(); j++)
    {
        if(v[i]==v[j] && vis[j]==0)
        {
            dfs(v, j, vis, s);
        }
    }
    s.push(v[i]);
}