#include<bits/stdc++.h>
using namespace std;



void deletenodewithsinglepointer(Node *random)
{
    Node *temp=random.next;
random.data=temp.data;
    random.next=temp.next;
    free(temp);
}