#include <bits/stdc++.h>
using namespace std;

// optimisation in find function

int path_compression(int x, int parent[], int n)
{
    if (x == parent[x])
    {
        return x;
    }
    parent[x] = path_compression(parent[x], parent, n);
    return parent[x];
}
//time complexity is O(m{alpha}n)
// alpha(n) is invers ackermann function