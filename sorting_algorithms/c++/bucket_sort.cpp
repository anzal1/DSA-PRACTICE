#include <bits/stdc++.h>
using namespace std;

// bucket sorting technique

// consider decimal and normal numbers

void bucket_sorter(int a[], int n, int k)
{
    int max_val = a[0];
    for (int i = 0; i < n ; i++)
    {
        max_val = max(max_val, a[i]);
    }
    max_val++;
    vector<int> buck[k];
    for (int i = 0; i < n; i++)
    {
        int bi = (k * a[i]) / max_val;
        buck->push_back(a[i]);
    }
    for (int i = 0; i < k; i++)
    {
        sort(buck[i].begin(), buck[i].end());
    }
    int index = 0;
    for (int i = 0; i < k; i++)

    {
        for (int j = 0; j < buck[i].size(); j++)
        {
            a[index++] = buck[i][j];
        }
    }
}