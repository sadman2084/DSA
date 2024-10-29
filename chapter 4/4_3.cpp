#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[100] = {4, 7, 8, 13, 86};
    int size = 5;

    int index = 3;
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size = size - 1;
    cout << "updated arr: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}