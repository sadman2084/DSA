#include <bits/stdc++.h>
using namespace std;

int main()
{

    int DATA[] = {10, 20, 30, 40, 50};
    int LB = 0;
    int UB = sizeof(DATA) / sizeof(DATA[0]) - 1;
    int ITEM = 30;

    int BEG = LB;
    int END = UB;
    int MID;
    int LOC=-1;
    while (BEG <= END)
    {
        MID = (BEG + END) / 2;

        if (DATA[MID] == ITEM)
        {
            LOC = MID;
            break;
        }

        else if (ITEM < DATA[MID])
        {
            END = MID - 1;
        }

        else
        {
            BEG = MID + 1;
        }
    }

    if (LOC != -1)
    {
        cout << "Item found at position: " << LOC << endl;
    }
    else
    {
        cout << "Item not found." << endl;
    }

    return 0;
}
