#include <bits/stdc++.h>
using namespace std;
void POSTFIX(string p)
{
    stack<int> s;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] >= '0' && p[i] <= '9')
        {
            s.push(p[i] - '0');
        }

        else
        {
            int op1 = s.top();
            s.pop();
            int op2 = s.top();
            s.pop();

            switch (p[i])
            {
            case '+':
                s.push(op1 + op2);
                break;
            case '-':
                s.push(op1 - op2);
                break;
            case '*':
                s.push(op1 * op2);
                break;
            case '/':
                s.push(op1 / op2);
                break;
            case '^':
                s.push(pow(op1, op2));
                break;
            }
        }
    }

    cout << s.top();
}

int main()
{
    string p;
    cin >> p;

    POSTFIX(p);
}