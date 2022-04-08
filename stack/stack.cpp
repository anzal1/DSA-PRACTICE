#include<bits/stdc++.h>
using namespace std;

struct Mystack
{
    int *arr;
    int cap;
    int top;
    Mystack(int c)
    {
        cap=c;
        arr=new int [c];
        top =-1;
    }
void push(int x)
{   if(top<cap){
    top++;
    arr[top]=x;}
    else{cout<<"overflow";}
}
int pop()
{   if(top>-1){
    int res =arr[top];
    top--;
    return res;
}
else {cout<<"underflow";}
}
int peek()
{
    return arr[top];
}
int size()
{
    return(top+1);
}
bool isEmpty()
{
    return (top==-1);
}
};



//for dynamic testing use vector 
// use push back and pop back.
