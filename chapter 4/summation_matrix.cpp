#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, k, A[100][100], B[100][100], c[100][100], result[100][100];
    int row1, col1, row2, col2, sum = 0;

    cout << "number of rows and columns for matrix A: ";
    cin >> row1 >> col1;

    // Input matrix A
    cout << "Matrix A:\n";
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    // Print matrix A
    cout << "A = \n";
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            cout << "\t" << A[i][j];
        }
        cout << "\n";
    }

    // Input matrix B
    cout << "number of rows and columns for matrix B: ";
    cin >> row2 >> col2;

    cout << "Matrix B:\n";
    for (i = 0; i < row2; i++)
    {
        for (j = 0; j < col2; j++)
        {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }

    // Print matrix B
    cout << "B = \n";
    for (i = 0; i < row2; i++)
    {
        for (j = 0; j < col2; j++)
        {
            cout << "\t" << B[i][j];
        }
        cout << "\n";
    }

    // Sum of matrices
    cout << "Sum of matrices:\n";
    if (row1 == row2 && col1 == col2)
    {
        for (i = 0; i < row1; i++)
        {
            for (j = 0; j < col1; j++)
            {
                c[i][j] = A[i][j] + B[i][j];
                cout << "\t" << c[i][j];
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "Math error: Matrices dimensions do not match for addition.\n";
    }
}