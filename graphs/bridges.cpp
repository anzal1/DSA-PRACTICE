#include<bits/stdc++.h>
using namespace std;

//give the bridge elements in 
void bridgesUtil(int u, bool visited[], int disc[], int low[], int parent[], int ap[], int &time, int n, vector<int> adj[])
{
    static int time = 0;
    static int root = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    int children = 0;
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(!visited[v])
        {
            children++;
            parent[v] = u;
            bridgesUtil(v, visited, disc, low, parent, ap, time, n, adj);
            low[u] = min(low[u], low[v]);
            if(parent[u] == -1 && children > 1)
                ap[u] = 1;
            if(parent[u] != -1 && low[v] >= disc[u])
                ap[u] = 1;
        }
        else if(v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}


vector<int> bridges(int n, vector<int> adj[])
{
    bool *visited = new bool[n];
    int *disc = new int[n];
    int *low = new int[n];
    int *parent = new int[n];
    int *ap = new int[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
        parent[i] = -1;
    }
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            bridgesUtil(i, visited, disc, low, parent, ap, i, n, adj);
        }
    }
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        if(ap[i] == 1)
            ans.push_back(i);
    }
    return ans;
}