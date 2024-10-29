#include <bits/stdc++.h>
using namespace std;

bool startsWith(const string &s, int i, const string &s1)
{
    for (int j = 0; j < s1.length(); ++j)
    {
        if (s[i + j] != s1[j])
            return false;
    }
    return true;
}


void modifyString(string &s, const string &s1, const string &s2)
{
    string ans = "";
    int i = 0;
    while (i < s.length())
    {
        if (startsWith(s, i, s1))
        {
            ans += s2;
            i += s1.length();
        }
        else
        {
            ans += s[i++];
        }
    }
    cout << ans;
}


int main()
{
    string S = "geeksforgeeks";
    string S1 = "eek";
    string S2 = "ok";
    modifyString(S, S1, S2);
 
}
