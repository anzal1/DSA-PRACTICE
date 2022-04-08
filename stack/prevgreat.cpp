#include<bits/stdc++.h>
using namespace std;

void prevgreat(int a[] ,int n)
{
    stack<int>s;
    s.push(a[0]);
    cout<<a[a[0]];

for(int i=0;i<n;i++)
{
    while(s.empty()==false && s.top()<=a[i])
    {
     s.pop();
    }
     int popper=(s.empty())?-1:s.top();
     cout<<popper<<endl;
     s.push(a[i]);


}
}