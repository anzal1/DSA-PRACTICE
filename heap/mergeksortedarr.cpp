#include <bits/stdc++.h>
using namespace std;

struct triplet
{
    int val, apos, vpos;
    triplet(int v, int ap, int vp)
    {
        val = v;
        apos = ap;
        vpos = vp;
    }
};

struct Mycmp
{
    bool operator()(triplet st1, triplet st2)
    {
        return st1.val < st2.val;
    }
};

vector<int> ksorted(vector<vector<int>> &h)
{
    vector<int> res;
    priority_queue<triplet, vector<triplet>, Mycmp> pq;
    for (int i = 0; i < h.size(); i++)
    {
        triplet t(h[i][0], i, 0);
        pq.push(t);
    }
    while (pq.empty() == false)
    {
        triplet curr = pq.top();
        pq.pop();
        res.push_back(curr.val);
        int ap = curr.apos, vp = curr.vpos;
        if (vp + 1 < h[ap].size())
        {
            triplet t(h[ap][vp + 1], ap, vp + 1);
            pq.push(t);
        }
    }
}