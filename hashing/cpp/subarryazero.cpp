#include <bits/stdc++.h>
using namespace std;

bool sumfind(int a[], int n)
{
    unordered_set<int> s; //hashset
    int presum = 0;
    for (int i = 0; i < n; i++)
    {
        presum += a[i];
        if (s.find(presum) != s.end())//contains
        {
            return true;
        }
        if (presum == 0)
        {
            return true;
        }
        s.insert(presum);// add
    }
    return false;
}