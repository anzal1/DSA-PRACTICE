#include <bits/stdc++.h>
using namespace std;

// minimum weight spanning tree using kruskal's algorithm

struct Edge
{
    int src, dest, weight;
    Edge(int src, int dest, int weight)
    {
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }
};

bool myCmp(Edge a, Edge b)
{
    return a.weight < b.weight;
}
int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

int kruskals(Edge a[])
{
    int v, e;
    int parent[100];
    int rank[100];
    int i, j, u, v, w, count = 0;
    for (i = 0; i < v; i++)
    {
        parent[i] = -1;
        rank[i] = 0;
    }
    sort(a, a + e, myCmp);
    for (i = 0; i < e; i++)
    {
        u = find(parent, a[i].src);
        v = find(parent, a[i].dest);
        if (u != v)
        {
            parent[u] = v;
            count += a[i].weight;
        }
    }
    return count;
}
