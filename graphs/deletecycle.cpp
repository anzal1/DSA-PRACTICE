#include<bits/stdc++.h>
using namespace std;

void detectCycle(vector<int> adj[], int n)
{
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i] = false;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(detectCycleUtil(adj,i,visited,-1))
                cout<<"Graph contains cycle";
            else
                cout<<"Graph doesn't contain cycle";
        }
    }
}

bool detectCycleUtil(vector<int> adj[], int u, bool *visited, int parent)
{
    visited[u] = true;
    for(int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];
        if(!visited[v])
        {
            if(detectCycleUtil(adj,v,visited,u))
                return true;
        }
        else if(v!=parent)
            return true;
    }
    return false;
}


void detecundirectedCycle(vector<int> adj[], int n)
{
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i] = false;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(detectCycleUtil(adj,i,visited,-1))
                cout<<"Graph contains cycle";
            else
                cout<<"Graph doesn't contain cycle";
        }
    }
}


void detectdirectedCycle(vector<int> adj[], int n)
{
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i] = false;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(detectdirectedCycleUtil(adj,i,visited,-1))
                cout<<"Graph contains cycle";
            else
                cout<<"Graph doesn't contain cycle";
        }
    }
}

bool detectdirectedCycleUtil(vector<int> adj[], int u, bool *visited, int parent)
{
    visited[u] = true;
    for(int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];
        if(!visited[v])
        {
            if(detectCycleUtil(adj,v,visited,u))
                return true;
        }
        else if(v!=parent)
            return true;
    }
    return false;
}


//dfs traversal and back edge detection in the recursionn stack;