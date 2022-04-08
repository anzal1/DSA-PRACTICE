#include<bits/stdc++.h>
using namespace std;

//naive can be n2 check twice
void spanner(int a[] ,int n)
{
    int span;
 stack<int>s;
 s.push(0);
 cout<<0;
 for(int i=0;i<n;i++)
 {

    while(s.empty()==false && a[s.top()]<=a[i])
     {
        s.pop();
     }
     span=s.empty()?i+1:i-s.top(); 
     cout<<span<<endl;
 
        s.push(i);
}
}



//span is equals to
// span=(index of element)-(index of closest element on the left side)