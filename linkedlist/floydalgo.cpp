#include<bits/stdc++.h>
using namespace std;


//well maintain two pointers fast and slow and then  move them accordinly then wecompare the values

bool detector(Node *head )
{
    Node *slowp=head,*fastp=head;
    while(fastp!=null,fastp.next!=null)
    {
        slowp=slowp.next;
        fastp=fastp.next.next;
        if(slowp=fastp)
        {
            return true;
        }
        return false;

    }
}


// linear in the approach O(m+n)