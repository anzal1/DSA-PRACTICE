#include<bits/stdc++.h>
using namespace std;



void evenoddsegretgator(Node *head)
{
Node *es=null,ee=null,os=null,oe=null;

for(Node*curr=head;curr!=null;curr=curr.next)
{
    int x=curr.data;
    if(x%2==0)
    {
        if(es==null)
        {
            es=curr;
            ee=es;
        }
        else{ee.next=curr;
        ee=ee.next}
    }
    else
    if(os==null)
    {
        os=curr;
        oe=os;
    }
    else{
        oe.next=curr;
        os=os.next;
    }
}
if(os==null||es=null)
{
    return head;
}
ee.next=os;
oe.next=null;
}