import java.util.*;
 

class Mystack
{
    int arr[];
    int cap;
    int top;
    Mystack(int c)
    {
        top=-1;
        cap=c;
        arr=new int[cap];
    }
    void push(int x)
    {
        top++;
        arr[top]=x;
    }
    int pop()
    {
        int res=arr[top];
        top--;
        return res;
    }
    int size()
    {
        return top+1;
    }
    boolean isempty()
    {
        return(top==-1);
    }
}


//for dynamic allocation just use Array list and create handle cases



// can also be implemented using link list 