#include <bits/stdc++.h>
using namespace std;

// find a proper prefix and a suffix
void prefixarr(string s, int lps[])
{
    int n = s.length(), len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}

void kmp(string pat, string txt)
{
    int n = txt.length();
    int m = pat.length();
    int lps[m];
    prefixarr(pat, lps);
    int i = 0, j = 0;
    while (i < n)
    {
        if (pat[j] == txt[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << (i - j);
            j = lps[j - 1];
        }
        else if (i < n && pat[i] != txt[i])
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }
    }
}

// int main()
// {
//     string s;
//     string p;
//     cin>>p>>s;
//     kmp(p,s);
// }