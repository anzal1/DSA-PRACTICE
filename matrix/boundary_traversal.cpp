#include<bits/stdc++.h>
using namespace std;


const int r=10;
const int c=10;

void boundary(int a[r][c])
{
    if(r==1)
    {
        for(int i=0;i<c;i++)
        {
        cout<<a[0][i]<<" ";
        }
    }
    else if(c==1)
    {
        for(int i=0;i<c;i++)
        {
        cout<<a[i][0]<<" ";
        }
    }
     for(int i=0;i<c;i++)
        {
        cout<<a[0][i]<<" ";
        }
     for(int i=1;i<r;i++)
        {
        cout<<a[i][c-1]<<" ";
        }
     for(int i=c-2;i>=0;i--)
        {
        cout<<a[c-1][i]<<" ";
        }
     for(int i=r-2;i>=0;i--)
        {
        cout<<a[r-2][0]<<" ";
        }
}