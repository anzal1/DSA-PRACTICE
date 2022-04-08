#include<bits/stdc++.h>
using namespace std;


//maintain sorted array using heap and take either two elements or 
//one array

void printMedians(int a[],int n)
{
    priority_queue<int>s;
    priority_queue<int ,vector<int>,greater<int>>g;
    s.push(a[0]);
    cout<<a[0]<<endl;
    for(int i=1;i<n;i++)
    {
        int x=a[i];
        if(s.size()>g.size())
        {
            if(s.top()>x)
            {
                g.push(s.top());
                s.pop();
            }
            else{
                g.push(x);
                cout<<(s.top()+g.top()/2.0)<<endl;
            }
        }
        else {
            if(x<=s.top())
            {
                s.push(x);
            }
            else{
                g.push(x);
                s.push(g.top());
                g.pop();
            }
            cout<<(s.top())<<endl;
        }
    }

}