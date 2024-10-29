#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10];
    int i;
    int k;
    int count = 0;
    for (i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    cout << "value to find: ";
    int value;
    cin >> value;

    for (i = 0; i < 10; i++)
    {
        if (value == arr[i])
        {
            count = 1;
            k = i;
            break;
        }
        else
        {
            count = 0;
        }
    }
    if (count == 0)
    {
        cout << "value not found";
    }
    else
    {
        cout << "value found at index: " << k;
    }
}