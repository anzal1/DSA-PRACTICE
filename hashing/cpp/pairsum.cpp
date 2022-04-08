#include <bits/stdc++.h>
using namespace std;

bool pair(int a[], int n,int sum)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.find(sum - a[i]) != s.end())
        {
            return true;
        }
        s.insert(a[i]);
    }
    return false;
}