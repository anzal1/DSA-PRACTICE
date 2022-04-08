#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int start;
    int end;
};
// in  java create a class named interval
// can alaso be represented as a structure
void merge(Interval a[], int n)
{
    sort(a, a + n, myComp);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[res].end >= a[i].start)
        {
            a[res].end = max(a[res].end, a[i].end);
            a[res].start = min(a[res].start, a[i].start);
        }
        else
        {
            res++;
            a[res] = a[i];
        }
    }
    for (int i = 0; i <= res; i++)
    {
        cout << a[i].start << " " << a[i].end << endl;
    }
}

void myComp(Interval a[], int n)
{
}
// effecient solutiom is to sort it accoriding to start to start time