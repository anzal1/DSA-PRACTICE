#include<bits/stdc++.h>
using namespace std;

//djikstras algo

vector<int> dijkstra(vector<vector<int>>& graph, int src)
{
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(visited[u])
            continue;
        visited[u] = true;
        for(int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            if(dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}