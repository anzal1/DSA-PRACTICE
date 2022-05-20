#include <bits/stdc++.h>
using namespace std;

int maxsumincreasing(int arr[], int n)
{
    int msis[n];
    for (int i = 0; i < n; i++)
    {
        msis[i] = arr[i];
        for (int j = 0; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                msis[i] = max(msis[i], arr[j] + arr[i]);
            }
        }
    }
    int res = msis[0];
    for (int i = 1; i < n; i++)
    {
        res = max(res, msis[i]);
    }
    return res;
}

int maximumlengthbitonic(int arr[], int n)
{
    int lis[n];
    for (int i = 0; i < n; i++)
    {
        lis[i] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                lis[i] = max(lis[i], arr[j] + arr[i]);
            }
        }
    }
    int res = lis[0];
    for (int i = 1; i < n; i++)
    {
        res = max(res, lis[i]);
    }
    return res;
}
// find lis and then reverse the taraversal and find the max


int bridges( int a[],int n)
{
    //three changes
    //sort 1,2
    //then lis according to 2
}