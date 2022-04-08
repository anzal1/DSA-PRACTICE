#include <bits/stdc++.h>
using namespace std;

void sortk(int a[], int k, int n)
{
    priority_queue<int, vector<int>, greater<int>> p1;
    for (int i = 0; i <= k; i++)
    {
        p1.push(a[i]);
    }
    int ind = 0;
    for (int i = k + 1; i < n; i++)
    {
        a[ind++] = p1.top();
        p1.pop();
        p1.push(a[i]);
    }
    while (p1.empty() == false)
    {
        a[ind++] = p1.top();
        p1.pop();
    }
}