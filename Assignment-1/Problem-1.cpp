#include <iostream>
using namespace std;

void multiply(int** mat1, int** mat2, int **ansmat, int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for(int k = 0; k < c1; k++)
            {
                ansmat[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int r1, r2, c1, c2;

    cout << "enter rows for matrix 1: ";
    cin >> r1;
    cout << "enter columns for matrix 1: ";
    cin >> c1;
    cout << "enter rows for matrix 2: ";
    cin >> r2;
    cout << "enter columns for matrix 2: ";
    cin >> c2;

    if (c1 != r2) {
        cout << "ERROR: the number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl;
        return 1;
    }

    //init mat1
    int** mat1 = new int*[r1];
    for (int i = 0; i < r1; i++) {
        mat1[i] = new int[c1];
    }

    //init mat2
    int** mat2 = new int*[r2];
    for (int i = 0; i < r2; i++) {
        mat2[i] = new int[c2];
    }

    //init ansmat
    int** ansmat = new int* [r1];
    for (int i = 0; i < r1; i++) {
        ansmat[i] = new int[c2];
    }

    //ansmat = 0
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            ansmat[i][j] = 0;
        }
    }

    //populate mat1
    cout << "Enter elements row wise for matrix 1: " << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> mat1[i][j];
        }
    }

    //populate mat2
    cout << "Enter elements row wise for matrix 2: " << endl;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> mat2[i][j];
        }
    }

    multiply(mat1, mat2, ansmat, r1, c1, r2, c2);

    //print ansmat
    cout << "Answer Array: " << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << ansmat[i][j] << " ";
        }
        cout << endl;
    }

    //dealloc memory
    for (int i = 0; i < r1; i++) {
        delete mat1[i];
        delete ansmat[i];
    }
    for (int i = 0; i < r2; i++) {
        delete mat2[i];
    }
    delete[] mat1;
    delete[] mat2;
    delete[] ansmat;
    return 0;
}

/*Question No. 1 (CLO No. 1) Marks: 6
Write a code which creates two dynamic 2D arrays. Create a function which performs matrix multiplication
and put the result in another dynamic array. Take the dimensions and elements of the matrices from the
user.*/