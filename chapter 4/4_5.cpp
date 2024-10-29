#include <bits/stdc++.h>
using namespace std;

int main()
{

    int DATA[] = {10, 20, 30, 40, 50};
    int N = sizeof(DATA) / sizeof(DATA[0]);
    int ITEM = 30;

    int LOC;

    for (LOC = 0; LOC < N && DATA[LOC] != ITEM;)
    {
        LOC++;
    }

    if (LOC < N)
    {
        cout << "Item found at position: " << LOC << endl;
    }
    else
    {
        cout << "Item not found." << endl;
    }

}
