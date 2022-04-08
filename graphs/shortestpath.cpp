#include<bits/stdc++.h>
using namespace std;


void shortestPath(vector<vector<int>>& graph, int src, int dest, int n)
{
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
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
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    cout << dist[dest] << endl;
    int u = dest;
    while(u != -1)
    {
        cout << u << " ";
        u = parent[u];
    }
    cout << endl;
}