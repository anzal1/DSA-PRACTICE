#include<bits/stdc++.h>
using namespace std;

//sort the arrays as given in the conditions

void segreagte(int a[],int n )
{
    int i=-1,j=n;
    while(true)
    {
        do{i++;}while(a[i]<0);
        do{i++;}while(a[i]<0);
        if(i>=j)
        {
            return;
        }
        int x=a[i];
        a[i]=a[j];
        a[j]=x;

    }
}