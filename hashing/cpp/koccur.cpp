#include<bits/stdc++.h>
using namespace std;

void appear(int a[],int n,int k)
{
    unordered_map<int,int>h;
    for(int i=0;i<n;i++)
    {
        h[a[i]]++;
        for(auto e:h)
        {
            if(e.second>n/k)
            cout<<e.first<<" ";
        }
    }


//      EFFICIENT SOLUTION
//  MOORES VOTING ALGORITJM

//  1 CREATE A MAP 
//  2 PHASE ONE CANDIDATE ELEMENTS
//  3 FIND ALL ELEMENTS IN M 
