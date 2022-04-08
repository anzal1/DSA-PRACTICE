#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
    int arr[]={10,20,5,7};
    sort(arr,arr+4);
    for(int i=0;i<4;i++)
{
    cout << arr[i] << endl;

}
return 0;
}
// generics can be addded to change the order of sorting just create a new function and pass what is required.