#include <bits/stdc++.h>
using namespace std;

void closest(int a[], int n, int k, int x)
{
    bool visited[n] = {false};
    for (int i = 0; i < k; i++)
    {
        int min_diff = INT_MIN;
        int min_diff_ind;
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == false && (abs(a[j] - x) <= min_diff))
            {
                min_diff = abs(a[j] - x);
                min_diff_ind = j;
            }
        }
        print(a[min_diff_ind] + " ")
            visited[min_diff_ind] = true;
    }
}


// create a max Heap ,pq and give them differences
// loop insert diff and index 
//check the diff and pop and add again and again
//print the final priority q