#include <bits/stdc++.h>
using namespace std;

int hoares(int a[], int l, int h)
{
    int pi = a[l];
    int l = 0;
    int i = l - 1, j = h - 1;
    while (true)
    {
        do
        {
            i++;
        } while (a[i] < pi);
        do
        {
            j--;
        } while (a[j] > pi);
        if(i>=j)
        {return j;
        }
            int x=a[j];
            a[j]=a[i];
            a[i]=x;
    }
    return;
}