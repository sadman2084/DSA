#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10];
    int i, k = 0;
    for (i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    int max = arr[0];
    for (i = 1; i < 10; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            k = i;
        }
    }
    cout<<max<<endl;
    cout<<k+1<<endl;
    return 0;
}