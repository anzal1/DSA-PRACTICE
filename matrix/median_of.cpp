#include<bits/stdc++.h>
using namespace std;


const int r=10;
const int c =10;

int median(int a[r][c])
{
     int min=a[0][0],max=a[0][c-1];
     for(int i=1;i<r;i++)
     {
         if(a[i][0]<min){min=a[i][0]}
         if(a[i][c-1]>min){max=a[i][c-1]}
     }
     int medpos=(r*c+1)/2;

while(min<max)
{
    int mid =(min+max)/2;
    int midpos=0;
    for(int i=0;i<r;i++)
    {
        midpos+=upper_bound(a[i],a[i]+c,mid)-a[i];

    }
    if(midpos<medpos)
        {
            min=mid+1;
        }
    else{
        max=mid;
    }
}
return min;
}
