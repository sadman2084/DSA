#include <bits/stdc++.h>
using namespace std;
void tower(int n, char beg, char aux, char end, int &count)
{

    if (n <= 0)
    {
        cout << "ERROR";
    }
    else if (n == 1)
    {

        cout << "move disk " << beg << " to " << end << endl;
        count++;
    }
    else
    {

        tower(n - 1, beg, end, aux, count);

        tower(1, beg, aux, end, count);

        tower(n - 1, aux, beg, end, count);
    }
}
int main()
{
    int n;
    char A, B, C;
    cout << "enter the number: ";
    cin >> n;
    int count = 0;
    tower(n, 'A', 'B', 'C', count);
    cout << "counted step by recursion: " << count << endl;

    int x = pow(2, n) - 1;
    cout << "counted step by formula: " << x << endl;
}