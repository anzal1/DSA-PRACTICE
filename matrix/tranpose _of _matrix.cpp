#include<bits/stdc++.h>
using namespace std;

const int r=10;
const int c=10;


void transpose(int a[r][c])
{
    for(int i=0;i<r;i++)
    {
    for(int j=i+1;j<c;j++)
    {
        int x=a[i][j];
        a[i][j]=a[j][i];
        a[j][i]=x;

    }
    }
}
