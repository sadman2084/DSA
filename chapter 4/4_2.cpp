#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[100] = {4, 7, 8, 13, 86};
    int size = 5;
    int item = 6;
    int index = 3;
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = item;
    size = size + 1;
    cout << "Updated array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}