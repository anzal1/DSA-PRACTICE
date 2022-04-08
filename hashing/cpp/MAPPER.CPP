#include<bits/stdc++.h>
using namespace std;


int main()
{
    unordered_map<string,int>m;
    m["gfg"]=20;
    m["ide"]=30;
    m["courses"]=15;
    if(m.find("ide")!=m.end())
    {
        cout<<"found\n";
    }
    else{
        cout<<"not found\n";
    }
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<(it->first)<<" "<<(it->second)<<endl;

    }
    return 0;

}