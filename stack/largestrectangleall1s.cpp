#include<bits/stdc++.h>
using namespace std;

const int x=10;
const int y=10;

int  largestRectangleMatrix(int a[x][y])
{
  int res=largest(a[0],y);
  for(int i=0;i<x;i++)
  {
  for(int j=0;j<y;j++)
  {
      if(a[i][j]==1)
      {
          a[i][j]+=a[i-1][j];
      }
      res=max(res,largest(a[i],y));
  } 
  return res;
  }
}




int largest(int ar[],int n)
{
//this finds largest histogram as discussed before 
}