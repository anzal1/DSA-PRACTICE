#include<bits/stdc++.h>
using namespace std;


//merge sort technique

void merge_sorter(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] <= b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else
        {
            cout << b[i] << " ";
        }
    }
    while (i < m)
    {
        cout << a[i] << " ";
        i++;
    }
    while (j < m)
    {
        cout << b[j] << " ";
        j++;
    }
}

void sorter(int a[],int l,int r)
{
    if(r>l)
    {
        int m=l+ (r-l)/2;
        sorter(a,l,m);
        sorter(a,m+1,r);
        merge_sorter(a,l,m,r);
    }
}   

