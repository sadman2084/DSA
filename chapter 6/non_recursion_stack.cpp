#include <bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    stack<int> stk;
    stk.push(n);
    int fact = 1;
    while (!stk.empty())
    {
        int x = stk.top();

        fact = fact * x;
        stk.pop();
        x = x - 1;
        if (x > 0)
        {
            stk.push(x);
        }
    }
    return fact;
}
int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Factorial of " << num << " is " << factorial(num) << endl;
    return 0;
}