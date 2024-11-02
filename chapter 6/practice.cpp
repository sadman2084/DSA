#include <bits/stdc++.h>
using namespace std;
int presidence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
void InToPost(string p)
{
    stack<char> s;
    string result;

    for (int i = 0; i < p.size(); i++)
    {
        if ((p[i] >= 'a' && p[i] <= 'z') || (p[i] >= 'A' && p[i] <= 'Z'))
        {
            result = result + p[i];
        }
        else if (p[i] == '(')
        {
            s.push(p[i]);
        }
        else if (p[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                result = result + s.top();
                s.pop();
            }

            if (!s.empty())
            {
                s.pop();
            }
        }
        else
        {
            while (!s.empty() && presidence(s.top()) >= presidence(p[i]))
            {
                result = result + s.top();
                s.pop();
            }
            s.push(p[i]);
        }
    }

    while (!s.empty())
    {
        result = result + s.top();
        s.pop();
    }

    cout << result << endl;
}
int main()
{
    string p;
    cin >> p;

    InToPost(p);
}