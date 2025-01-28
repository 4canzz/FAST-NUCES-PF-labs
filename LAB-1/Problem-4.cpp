//(c) 24L - 6116
#include <iostream>
using namespace std;

const int row = 3;
const int col = 4;

void GetData(int matrix[][col], int row , int col);
void PrintMaximumValueInRow(int matrix[][col], int row , int col);

int main () {
    int matrix[row][col];

    cout << "Populate the matrix by making entries: ";
    GetData(matrix, row, col);
    PrintMaximumValueInRow(matrix, row, col);
    return 0;
}

void GetData(int matrix[][col], int row , int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }
}

void PrintMaximumValueInRow(int matrix[][col], int row , int col) {
    for (int i = 0; i < row; i++) {
        int largest = 0;
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] > largest) {
                largest = matrix[i][j];
            }
        }
        cout << largest << endl;
    }
}

/*Exercise 4: (10 points)
Write a program which declares a 2-dimensional integer array with 3 rows and 4 columns. Write
a function called GetData which populates this array with integers typed in by the user. Write
another function called PrintMaximumValueInRow which outputs the maximum values present
in each row.
For example if the array gets populated with the following data:
7 11 9 8
4 22 6 3
1 2 3 4
Your output would be:
11
22
4*/