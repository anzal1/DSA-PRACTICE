#include<bits/stdc++.h>
using namespace std;


bool palin_link(Node head)
{
    if(head ==null)return true;
    Node slow =head,fast =head;
    while(fast.next!=null&&fast.null.null!=null)
    {
        slow=slow.next;
        fast=fast.next.next;
    }
    Node rev =reverseList(slow.next);
    Node curr=head;
    while(rev!=null)
    {
        if(rev.data!=curr.data)
        {
            return false;
        }
        rev=rev.next;
        curr=curr.next;
    }
    return true;
}