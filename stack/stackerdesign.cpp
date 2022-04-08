#include<bits/stdc++.h>
using namespace std;


stack<int>s;
int min;
void push(int x)
{
    if(s.empty())
    {
        min =t;
        s.push(x);
        else if (x<min)
        {
            s.push(2*x-min)
            min=x;
        }
        else{
            s.push(x);
        }
    }
}
//store minimum item diff and move forwardz
int getmin()
{
    return min;
}
int peek()
{
    t=s.peek();
    return(t<=min)?mn:t;
}
int pop()
{
    t=s,pop();
    if(t<=min)
    {
        res=min;
        min=2*min-t
        return res;

    }
    else{return t;}
}


