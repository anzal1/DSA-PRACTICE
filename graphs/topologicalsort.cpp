#include <bits/stdc++.h>
using namespace std;

void topoSort(vector<int> adj[], int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            topoSortUtil(adj, i, visited);
    }
}

void topoSortUtil(vector<int> adj[], int u, bool *visited)
{
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (!visited[v])
            topoSortUtil(adj, v, visited);
    }
    cout << u << " ";

}

void BFSTopoSort(vector<int> adj[], int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            BFSTopoSortUtil(adj, i, visited);
    }
}    

void BFSTopoSortUtil(vector<int> adj[], int u, bool *visited)
{
    visited[u] = true;
    cout << u << " ";
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (!visited[v])
            BFSTopoSortUtil(adj, v, visited);
    }
}