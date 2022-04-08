#include<bits/stdc++.h>
using namespace std;


int intersection(Node *h1,NOde *h2)
{
    if(a==null) return b;
    if(b==null) return a;
    Node *hed =null,*tail=null;
    if(a.data<=b.data)
    {
        head=tail=a;a=a.next;
    }
    else{
        head =tail=a,b=b.next;
    }
    while(a!=null&&b!=null)
    {
        if(a.data<=b.data)
        {
            tail.next=a;tail=a;a=a.next;
        }
        else{
            tail.next=b;tail=b;b=b.next;
        }
    }
    if(a==null)tail.next=b;
    else{ tail.next=a};
    return 0;
}