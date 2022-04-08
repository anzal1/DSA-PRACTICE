#include <bits/stdc++.h>
using namespace std;

bool summer(int a[], int n, int sum)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        int presum = 0;
        for (int i = 0; i < n; i++)
        {
            if (presum == sum)
            {
                return true;
            }
            if (s.find(presum - sum) != s.end())
            {
                return true;
            }
            s.insert(presum);
        }
        return false;
    }
}