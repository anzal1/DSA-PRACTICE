#include<bits/stdc++.h>
using namespace std;

void minspanTree(vector<vector<int>>& graph, int n)
{
    vector<int> parent(n, -1);
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    dist[0] = 0;
    parent[0] = -1;
    for(int i = 0; i < n; i++)
    {
        int u = -1;
        for(int j = 0; j < n; j++)
        {
            if(!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }
        visited[u] = true;
        for(int v = 0; v < n; v++)
        {
            if(!visited[v] && graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(parent[i] != -1)
            cout << parent[i] << " " << i << endl;
    }
}