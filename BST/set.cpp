#include <bits/stdc++.h>
using namespace std;


struct Test{
    int x;
    bool operator<(const Test& t) const{
        return x < t.x;
    }
};

int main()
{
    set<int, greater<int>> s;
    s.insert(10);
    s.insert(20);
    s.insert(10);
    s.insert(30);
    s.insert(40);
    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    auto it = s.find(10);
    if (it != s.end())
    {
        cout << "Element found" << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    while (it != s.end())
    {
        cout << *it << " ";
        it++;
    }

    s.clear();
    s.size();
    s.count(10);
    s.erase(10);
    s.rbegin();
    s.rend();
    s.lower_bound(10);
    s.upper_bound(10);
    s.equal_range(10);
    auto it=s.find(10);
    s.erase(it,s.end());
    
}