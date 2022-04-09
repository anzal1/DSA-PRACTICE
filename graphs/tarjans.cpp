#include<bits/stdc++.h>
using namespace std;


//implement tarjans algorithm
int timer=0;
int tarjan(int u, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low, vector<bool>& instack, vector<int>& stack, vector<bool>& onstack, vector<int>& ans)
{  
    int children = 0;
    disc[u] = low[u] = ++timer;
    instack[u] = true;
    stack.push_back(u);
    onstack[u] = true;
    for(int v : adj[u])
    {
        if(!disc[v])
        {
            children++;
            low[u] = min(low[u], tarjan(v, adj, disc, low, instack, stack, onstack, ans));
        }
        else if(onstack[v])
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    if(disc[u] == low[u])
    {
        int v;
        do
        {
            v = stack.back();
            stack.pop_back();
            onstack[v] = false;
            ans[v] = u;
        }while(v != u);
    }
    return low[u];
}