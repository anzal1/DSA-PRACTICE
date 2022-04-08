#include <bits/stdc++.h>
using namespace std;

// there are minimum writes and eeprom
void cycle_sorter(int a[], int n)
{
    for (int cs = 0; cs = n - 1; cs++)
    {
        int item = a[cs];
        int pos = cs;
        for (int i = cs + 1; i < n ; i++)
        {
            if (a[i] < item)
            {
                pos++;
            }
        }
        int x = item;
        item = a[pos];
        a[pos] = x;

        while (pos != cs)
        {
            pos = cs;
            for (int i = cs + 1; i < n; i++)
            {
                if (a[i] < item)
                {
                    pos++;
                }
            }
            int x = item;
            item = a[pos];
            a[pos] = x;
        }
    }
}