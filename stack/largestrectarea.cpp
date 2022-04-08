#include <bits/stdc++.h>
using namespace std;

void largestareahistogram(int a[], int n)
{
    int res = 0;

    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        int tp;
        int curr;
        while (s.empty() == false && a[s.top()] >= a[i])
        {
            int tp = s.top();
            s.pop();
            curr = a[tp] * (s.empty() ?: (i - s.top() - 1));
            res = max(res,curr);
        }
        s.push(i);
        while (s.empty() == false)
        {
            int tp = s.top();
            s.pop();
            curr = a[tp] * (s.empty() ?: (n - s.top() - 1));
            res = max(res,curr);
        }
        s.push(i);
    }
}