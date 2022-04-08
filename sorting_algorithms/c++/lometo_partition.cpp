#include <bits/stdc++.h>
using namespace std;

void partition(int a[], int l, int h)
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

// partition the given array along the given array

//----> LOMETO PARTITION


//it assumes that the array has a pivot at end
//if yoou want to parttion the array at another just swap the element with the last element 

