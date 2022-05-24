// minimum weight spanning tree

// 1. sort all edges inc order
// 2. initialize mst =[],res;
// 3. do for v-1(edges)
// ignore if it causes cycle
// accept if it doesnot
#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, dest, wt;
    Edge(int s, int d, int w)
    {
        src = s;
        dest = d;
        wt = w;
    }
};
bool mycmp(Edge e1, Edge e2)
{
    return e1.wt < e2.wt;
}
const int v = 100;
int parent[v], ranks[v];

int find(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    else
    {
        return find(parent[x]);
    }
}

void union_by_rank(int x, int y)
{
    int x_rep = find(x), y_rep = find(y);
    if (x_rep == y_rep)
        return;
    if (ranks[x_rep] < ranks[y_rep])
        parent[x_rep] = y_rep;
    else if (ranks[y_rep] < ranks[x_rep])
        parent[y_rep] = x_rep;
    else
    {
        parent[y_rep] = x_rep;
        ranks[x_rep]++;
    }
}

int kruskal(Edge a[])
{
    sort(a, a + v, mycmp);

    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
    }
    int res = 0;

    for (int i = 0, s = 0; s, v - 1; i++)
    {
        Edge e = a[i];
        int x = find(e.src);
        int y = find(e.dest);
        if (x != y)
        {
            res += e.wt;
            union_by_rank(x, y);
            s++;
        }
    }
    return res;
}
