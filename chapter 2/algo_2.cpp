#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int d = (b * b) - 4 * a * c;
    if (d < 0)
    {
        cout << "Imaginary" << endl;
    }
    else if (d == 0)
    {
        int x = -b / (2 * a);
        cout << x << endl;
    }
    else if (d > 0)
    {
        int x = -b + sqrt(d);
        int y = -b - sqrt(d);
        cout << x << endl;
        cout << y << endl;
    }
}