#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void printGraph(vector<vector<int>> &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(graph, u, v);
    }
    return 0;
}

void bfs(vector<vector<int>> &graph, int s)
{
    queue<int> q;
    q.push(s);
    vector<bool> visited(graph.size(), false);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int i = 0; i < graph[u].size(); i++)
        {
            if (!visited[graph[u][i]])
            {
                q.push(graph[u][i]);
                visited[graph[u][i]] = true;
            }
        }
    }
}

void bfsv2(vector<vector<int>> &graph, vector<bool> visited, int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int i = 0; i < graph[u].size(); i++)
        {
            if (!visited[graph[u][i]])
            {
                q.push(graph[u][i]);
                visited[graph[u][i]] = true;
            }
        }
    }
}

// count no of connected components
int countComponents(vector<vector<int>> &graph)
{
    int count = 0;
    vector<bool> visited(graph.size(), false);
    for (int i = 0; i < graph.size(); i++)
    {
        if (!visited[i])
        {
            bfsv2(graph, visited, i);
            count++;
        }
    }
    return count;
}

// bfs for disconnected graph
void bfsDisconnected(vector<vector<int>> &graph, int s)
{
    queue<int> q;
    q.push(s);
    vector<bool> visited(graph.size(), false);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int i = 0; i < graph[u].size(); i++)
        {
            if (!visited[graph[u][i]])
            {
                q.push(graph[u][i]);
                visited[graph[u][i]] = true;
            }
        }
    }
}

// depth first search
void dfsrec(vector<vector<int>> &graph, int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (int u : graph[s])
    if(visited[u]==false)
    {
        dfsrec(graph,u,visited);
    }
}


void dfs(vector<vector<int>>&graph,int v,int s)
{
    bool visited[v];
    for(int i=0;i<v;i++)
    {
        visited[i]==false;
    }
    dfsrec(graph,s,visited);
}

int dfsdisconn(vector<vector<int>>&graph,int v,int s)
{
    bool visited[v];
     for(int i=0;i<v;i++)
    {
        visited[i]==false;
    }
    int count=0;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            dfsrec(graph,i,visited);
            count++;
        }
    }
    return count;
}