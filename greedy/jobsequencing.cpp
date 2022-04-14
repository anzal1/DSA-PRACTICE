#include<bits/stdc++.h>
using namespace std;


vector<int> jobsequencing(vector<int> &arrival, vector<int> &duration)
{
    int n = arrival.size();
    vector<int> ans;
    vector<int> finish(n, 0);
    vector<int> start(n, 0);
    vector<int> job(n, 0);
    for(int i = 0; i < n; i++)
    {
        job[i] = i;
    }
    sort(job.begin(), job.end(), [&](int i, int j) {
        return arrival[i] < arrival[j];
    });
    int time = 0;
    for(int i = 0; i < n; i++)
    {
        int j = job[i];
        if(time < arrival[j])
        {
            time = arrival[j];
        }
        start[j] = time;
        time += duration[j];
        finish[j] = time;
    }
    for(int i = 0; i < n; i++)
    {
        ans.push_back(start[i]);
    }
    return ans;
}