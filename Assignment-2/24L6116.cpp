/**
 * IMPLEMENTATION FILE
 * CS1002
 * Programming Fundeentals - Assignment 2
 * Syed Furqan Hassan
 * 24L - 6116
 * BEE - 2D
 *
 * Note: Since the assignment outline did not include any mention of an input functionality, all values will be hardcoded.
 *
 **/

#include "SparseMatrix.h"
#include <iostream>
using namespace std;

int main() {
    SparseMatrix A(2, 3, 3), B(3, 3, 2), C(3, 3, 4);
    // Matrix A will have 3 non-zero Values and an order of 3x2
    // Matrix B will have 2 non-zero Values and an order of 3x3
    // MAtrix C will have 4 non-zero Values and an order of 3x3

    // initialize matrix A as    {{1, 0, 0},
    A.setElement(0, 0, 0, 1); // {-1, 0, 3}}
    A.setElement(1, 1, 0, -1);
    A.setElement(2, 1, 2, 3);
    cout << "----Matrix A:-----" << endl;
    A.output();
    cout << "------------------" << endl;

    // initialize matrix B as   {{7, 0, 0},
    B.setElement(0, 0, 0, 7); // {0, 0, 0},
    B.setElement(1, 2, 2, 1); // {0, 0, 1}}
    cout << "----Matrix B:-----" << endl;
    B.output();
    cout << "------------------" << endl;

    // initialize matrix C as   {{0, 2, 2},
    C.setElement(0, 0, 1, 2); // {0, 0, 3},
    C.setElement(1, 0, 2, 2); // {2, 0, 0}}
    C.setElement(2, 1, 2, 3);
    C.setElement(3, 2, 0, 2);
    cout << "----Matrix C:-----" << endl;
    C.output();
    cout << "------------------" << endl;

    // initialize a pointer resultant matrix, here RES is pointing to the resultants returned by member functions
    // addition, subtraction, and multiplication of A with B.
    cout << "------A + B:------" << endl;
    SparseMatrix* RES = new SparseMatrix(A.add(B)); // RES = A + B.
    RES->output();
    delete RES;

    cout << "------A - B:------" << endl;
    RES = new SparseMatrix(A.subtract(B)); // RES = A - B.
    RES->output();
    delete RES;

    cout << "------A x B:------" << endl;
    RES = new SparseMatrix(A.multiply(B)); // RES = A x B.
    RES->output();
    delete RES;

    // addition, subtraction, and multiplication of B with C
    cout << "------B + C:------" << endl;
    RES = new SparseMatrix(B.add(C)); // RES = B + C.
    RES->output();
    delete RES;

    cout << "------B - C:------" << endl;
    RES = new SparseMatrix(B.subtract(C)); // RES = B - C.
    RES->output();
    delete RES;

    cout << "------A x B:------" << endl;
    RES = new SparseMatrix(B.multiply(C)); // RES = A x B.
    RES->output();
    delete RES;

    // addition, subtraction, and multiplication of A with C
    cout << "------A + C:------" << endl;
    RES = new SparseMatrix(A.add(C)); // RES = A + C.
    RES->output();
    delete RES;

    cout << "------A - C:------" << endl;
    RES = new SparseMatrix(A.subtract(C)); // RES = A - C.
    RES->output();
    delete RES;

    cout << "------A x B:------" << endl;
    RES = new SparseMatrix(A.multiply(C)); // RES = A x C.
    RES->output();
    delete RES;

    cout << "------Transpose of A:------" << endl;
    A.transpose();
    A.output();

    cout << "------Transpose of B:------" << endl;
    B.transpose();
    B.output();

    cout << "------Transpose of C:------" << endl;
    C.transpose();
    C.output();
    
    delete RES;
    return 0;
}
