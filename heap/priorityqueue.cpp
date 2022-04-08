#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(10);
    pq.push(15);
    pq.push(5);

    cout << pq.size() << " ";
    cout << pq.top() << " ";
    while (pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

//it works on the heap ds and is easily customizable

//constructor for array to pq


// priority_queue<int> pq(arr,arr+3);

// to create a min heap just do
// for(int i=0;i<n;i++)
// {
//     arr[i]*=-1;
// }



// default structrizing

// struct Person{
//     int age;
//     float ht;
//     Person(int a,float h)
//     {
//         age=a;
//         ht=h;
//     }
// };