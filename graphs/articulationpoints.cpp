#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>>& graph, int src, vector<int>& dist, vector<bool>& visited)
{
    visited[src] = true;
    for(int i = 0; i < graph[src].size(); i++)
    {
        int v = graph[src][i];
        if(!visited[v])
        {
            dist[v] = dist[src] + 1;
            dfs(graph, v, dist, visited);
        }
    }
}

vector<int> articulationPoints(vector<vector<int>>& graph, int src)
{
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    dist[src] = 0;
    dfs(graph, src, dist, visited);
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        if(dist[i] == INT_MAX)
            continue;
        int children = 0;
        for(int j = 0; j < graph[i].size(); j++)
        {
            int v = graph[i][j];
            if(dist[v] < dist[i])
                children++;
        }
        if(children > 1)
            ans.push_back(i);
    }
    return ans;
}