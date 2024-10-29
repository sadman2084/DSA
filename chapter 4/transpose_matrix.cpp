#include <iostream>
using namespace std;

int main()
{
    int i, j, row, col;
    int A[10][10], transpose[10][10];

    cout << "Enter the number of rows and columns:\n";
    cin >> row >> col;

    // Input the matrix
    cout << "Enter the elements of matrix A:\n";
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    // Output the matrix
    cout << "Matrix A:\n";
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cout << A[i][j] << "\t";
        }
        cout << "\n";
    }

    // Compute the transpose
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            transpose[j][i] = A[i][j];
        }
    }

    // Output the transpose
    cout << "Transpose of matrix A (Matrix T):\n";
    for (i = 0; i < col; i++)
    { 
        for (j = 0; j < row; j++)
        {
            cout << transpose[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}
