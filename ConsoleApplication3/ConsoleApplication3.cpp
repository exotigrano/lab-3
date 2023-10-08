#include <iostream>
#include <time.h>
using namespace std;

void main()
{
label:
    const int row = 3, col = 3;
    int arr[row][col];
    srand(time(NULL));
    int diag1 = 0, diag2 = 0, gor = 0, vert = 0, gor2 = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 10;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j) {
                diag1 += arr[i][j];
            }
            if (i + j == row - 1) {
                diag2 += arr[i][j];
            }

        }
    }
    //gor
    for (int l = 0; l < row; l++)
    {
        for (int v = 0; v < col; v++)
        {
            gor += arr[l][v];
        }
        gor = 0;
    }
    int tmp = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            gor += arr[i][j];
            if ((i < row) && (j < col))
                gor2 += arr[i + 1][j + 1];
            else
                gor2 += arr[i - 1][j - 1];
            //      cout << gor << " ";
            tmp = gor;
        }
        if (tmp != gor2) {
            goto label;
        }
        gor2 = 0;
    }
    if (diag1 != diag2) {
        goto label;
    }
    cout << diag1 << " " << diag2 << endl << gor << endl;
}
//derwerq////yrur///