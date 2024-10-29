
#include <bits/stdc++.h>
using namespace std;
int main()
{

    int LA[] = {1, 2, 3, 4, 5};
    int LB = 0;
    int UB = sizeof(LA) / sizeof(LA[0]);

    int K = LB;
    int element;

    while (K < UB)
    {

        element += 1;

        K = K + 1;
    }

    for (int i = 0; i < UB; ++i)
    {
        cout << LA[i] << " ";
    }
    cout << endl;

    return 0;
}
