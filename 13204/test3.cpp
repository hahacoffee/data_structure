#include <iostream>

using namespace std;

int MROW, MCOL, X , Y , direction, sum, pointer,Ans;

void preorder_make(int** M, int row, int col) {
    if ((M[row][col] != 0)) {
        sum += M[row][col];
        switch (direction) {
        case 1:
            direction = 1;
            if (col + 1 < MCOL) preorder_make(M, row, col + 1);
            direction = 3;
            if (row - 1 >= 0) preorder_make(M, row - 1, col);
            direction = 4;
            if (row + 1 < MROW) preorder_make(M, row + 1, col);
            break;
        case 2:
            direction = 2;
            if (col - 1 >= 0) preorder_make(M, row, col - 1);
            direction = 3;
            if (row - 1 >= 0) preorder_make(M, row - 1, col);
            direction = 4;
            if (row + 1 < MROW) preorder_make(M, row + 1, col);
            break;
        case 3:
            direction = 1;
            if (col + 1 < MCOL) preorder_make(M, row, col + 1);
            direction = 2;
            if (col - 1 >= 0) preorder_make(M, row, col - 1);
            direction = 3;
            if (row - 1 >= 0) preorder_make(M, row - 1, col);
            break;
        case 4:
            direction = 1;
            if (col + 1 < MCOL) preorder_make(M, row, col + 1);
            direction = 2;
            if (col - 1 >= 0) preorder_make(M, row, col - 1);
            direction = 4;
            if (row + 1 < MROW) preorder_make(M, row + 1, col);
            break;
        }
        if (col == (MCOL-1) && row == (MROW-1)) {
            cout << sum << endl;
            pointer = 1;
        }

        sum -= M[row][col];
    }
}

int main(void) {

    cin >> MROW >> MCOL;

    int** Matrix = new int* [MROW];
    for (int i = 0; i < MROW; i++) {
        Matrix[i] = new int[MCOL] {0};
    }

    for (int i = 0; i < MROW; i++) {
        for (int j = 0; j < MCOL; j++) {
            cin >> Matrix[i][j];
        }
    }

    direction = 1;
    sum = 0;
    X = 0;
    Y = 0;
    Ans = 0;
    pointer = 0;


    preorder_make(Matrix, Y, X);
    if (pointer == 0) cout << Ans << endl;

    for (int i = 0; i < MROW; i++) {
        delete[] Matrix[i];
    }

    delete[] Matrix;

    return 0;
}
