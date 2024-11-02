#include <bits/stdc++.h>
using namespace std;
void TowerOfHanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << a << " " << c << endl;
        return;
    }
    else
    {
        TowerOfHanoi(n - 1, a, c, b);
        cout << a << " " << c << endl;
        TowerOfHanoi(n - 1, b, a, c);
    }
}
int main()
{
    int n;
    TowerOfHanoi(3, 'A', 'B', 'C');
}