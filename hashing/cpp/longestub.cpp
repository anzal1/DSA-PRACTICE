#include<bits/stdc++.h>
using namespace std;


 void summer(int a[],int n,int sum)
 {
   unordered_map<int ,int>m;
   int presum=0,res=0;
   for(int i=0;i<n;i++)
   {
       presum=a[i];
       if(presum==sum){res=i+1;}
       if(m.find(presum)==m.end())
       {
           m.insert(presum,i);
       }
        if(m.find(presum-sum)!=m.end())
        {
            res =max(res,i-m[presum-sum]);
        }
   }
   cout<<res;

 }