#include<bits/stdc++.h>
using namespace std;

//shortest path from src to dest

vector<int> bellmanFord(vector<vector<int>>& graph, int src, int dest)
{
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    for(int i = 0; i < n-1; i++)
    {
        for(int u = 0; u < n; u++)
        {
            for(int v = 0; v < graph[u].size(); v++)
            {
                int w = graph[u][v];
                if(dist[u] != INT_MAX && dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }
    }
    return dist;
}