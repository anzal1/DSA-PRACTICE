#include <bits/stdc++.h>
using namespace std;

const int n = 10;
int parent[n];
int main()
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
}

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

void uniona(int x, int y)
{
    int x_rep = find(x);
    int y_rep = find(y);
    if (x_rep == y_rep)
    {
        return;
    }
    parent[y_rep] = x_rep;
}

int ranks[n];

void intialize_by_rank()
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        ranks[i] = 0;
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