#include<bits/stdc++.h>
using namespace std;

//calls lometo partition an puts it in the correct place and the array on the left is sorted 
int partition(int a[], int l, int h)
{
    int pivot = a[h];
    int i = l - 1;
    for (int j = l; j <= h - 1; j++)
    {
        if (a[i] < pivot)
        {
            i++;
            int x = 0;
            x = a[j];
            a[j] = a[i];
            a[i] = x;
        }
        int x = a[i + 1];
        a[i + 1] = a[h];
        a[h] = x;
    }
}

void quicksort(int a[],int l,int h)
{
    if(l<h)
    {
        int p=partition(a,l,h);
        quicksort(a,l,p-1);
        quicksort(a,p+1,h);

    }
}