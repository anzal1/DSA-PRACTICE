#include<bits/stdc++.h>
using namespace std;


//kosa raju algo
void kosaraju(vector<vector<int>>& graph, int src, vector<int>& visited, vector<int>& order)
{
    visited[src] = true;
    for(int i = 0; i < graph[src].size(); i++)
    {
        int v = graph[src][i];
        if(!visited[v])
            kosaraju(graph, v, visited, order);
    }
    order.push_back(src);
}
