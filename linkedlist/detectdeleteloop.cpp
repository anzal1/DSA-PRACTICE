#include<bits/stdc++.h>
using namespace std;



void delloop(Node *head)
{
     Node *slowp=head,*fastp=head;
    while(fastp!=null,fastp.next!=null)
    {
        slowp=slowp.next;
        fastp=fastp.next.next;
      if(slowp==fastp){break;}
    }
    if(slow!=fast){return;}

    slowp=head;
    while(slowp.next!=fast.next)
    {
        slowp=slow.next;
        fast=fast.next;
    }
    fast.next=null;

}


// maths behind this is first node removal where we wil remove tbe node as it as by comparing the next values of the loop

// (m+k+x*n)*2=m+k+y*n
// (m+k)=n(y-2x)   hence m+k is mulitple of n


//variations find length of the loop----detect the loop and fix one pointer on the first node and move the second ponter it meets it again