#include <bits/stdc++.h>
using namespace std;

int rabin_karp(string txt, string pat)
{
    int n = txt.length();
    int m = pat.length();
    int h = 1;
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }
    int p = 0;
    int t = 0;
    for (int i = 0; i < m - 1; i++)
    {
        p = ((p * d) + pat[i]) % q;
        t = ((t * d) + txt[i]) % q;
    }
    for (int i = 0; i < m - 1; i++)
    {
        if (p == t)
        {
            bool flag;
            for (int j = 0; j < m - 1; j++)
            {
                if (txt[i + 1] != pat[j])
                {
                    flag = false;
                    break;
                }
                if (flag = true)
                {
                    cout << i;
                }
            }
            if (i < n - m)
            {
                t = ((d * (t - txt[i] * h) + txt[i + m]) % q);
                if (t < 0)
                {
                    t = t + q;
                }
            }
        }
    }
}