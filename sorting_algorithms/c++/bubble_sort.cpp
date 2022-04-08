#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }

    bool swap;
    for (int i = 0; i < 9; i++)
    {
        swap = false;
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int ab = a[j + 1];
                a[j + 1] = a[j];
                a[j] = ab;
                swap = true;
            }
        }
            if (swap == false)
            {
                break;
            }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
}