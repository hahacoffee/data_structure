#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> Ans;

int MROW, MCOL, X, Y,direction,sum,cmax,cmin,pointer;

void preorder_make(int** M, int row, int col) {
    if ((M[row][col] != 0) && (M[row][col] != -1)) {
        sum += M[row][col];
        switch (direction) {
        case 1:
            direction = 1;
            if(col + 1 < MCOL) preorder_make(M, row, col + 1);
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

        if (sum > cmax && pointer == 1) {
            pointer = 1;
            cmax = sum;
        }
        if (sum < cmin && pointer == 2) {
            pointer = 2;
            cmin = sum;
        }
        if (sum < cmax && pointer == 1) {
            pointer = 2;
            Ans.push(cmax);
            cmin = cmax;
            cmax = 0;
        }
        if (sum > cmin && pointer == 2) {
            pointer = 1;
            cmin = 10000;
            cmax = sum;
        }
        sum -= M[row][col];
    }
}

int main(void) { 

    cin >> MROW >> MCOL >> X >> Y;
    
    int **Matrix = new int*[MROW];
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
    pointer = 1;
    cmax = 0;
    cmin = 10000;

    preorder_make(Matrix,Y,X);

    cout << Ans.top() << endl;

    for (int i = 0; i < MROW; i++) {
        delete [] Matrix[i];
    }

    delete [] Matrix;

    return 0;
}