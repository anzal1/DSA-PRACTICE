#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> m;
    m.insert({1, 2});
    m.insert({2, 3});
    cout << m[1] << endl;
    cout << m[2] << endl;

    for (auto i = m.begin(); i != m.end(); i++)
    {
        cout << i->first << " " << i->second << endl;
    }

    m.clear();
    m.size();
    m.empty();
    m.count(1);
    m.find(1);
    m.find(2);
    m.lower_bound(1);
    m.upper_bound(1);
    m.equal_range(1);
    m.erase(1);
    m.erase(2);

    return 0;
}


// first refers to the key, second refers to the value

