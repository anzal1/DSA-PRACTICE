#include<bits/stdc++.h>
using namespace std;


int distance(int petrol[],int dist[], int n)
{
 int start=0,curr_pet=0;
 int prev_pet=0;
 for(int i=0;i<n;i++)
 {
     curr_pet+=(petrol[i]-dist[i]);
     if(curr_pet<0)
     {
         start=i+1;
         prev_pet+=curr_pet;
         curr_pet;

     }
 }
 return((curr_pet+prev_pet)>=0?(start+1):1);


}