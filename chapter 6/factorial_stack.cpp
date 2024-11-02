#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    stack<int> s;

    for (int i = n; i > 0; i--)
    {
        s.push(i);
    }

    int p = 1;
    while (!s.empty())
    {
        p = p * s.top();
        s.pop();
    }

    cout<<p;
}