#include <bits/stdc++.h>
using namespace std;
void fibo(int n)
{
    stack<int> s;
    s.push(0);
    s.push(1);
    if (n == 0)
    {
        cout << "0";
        return;
    }
    cout << "0 1 ";

    for (int i = 2; i < n; i++)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        int next = a + b;
        cout << next << " ";

        s.push(a);
        s.push(next);
    }
}
int main()
{
    int n;
    cin >> n;
    fibo(n);
}