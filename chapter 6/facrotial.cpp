#include <bits/stdc++.h>
using namespace std;
int fact(int n)
{
    int i;
    if (n == 1)
    {
        return n;
    }
    else
    {
        return n * fact(n - 1);
    }
}
int main()
{
    int n;
    cout<<"enter the number: ";
    cin >> n;
    int factorial = fact(n);
    cout << "the factorial is: "<<factorial << endl;
}