//(c) 24L - 6116
#include <iostream>
#define SIZE 6
using namespace std;

bool IsIdenticalArrays(int Array1[],int Array2[]);

int main() {
    int foo[SIZE];
    int bar[SIZE];

    cout << "enter  numbers for first array: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> foo[i];
    }

    cout << "enter  numbers for second array: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> bar[i];
    }

    if (IsIdenticalArrays(foo, bar)) {
       cout << "the arrays are equal" << endl;
    }
    else {
        cout << "the arrays are not equal" << endl;
    }
}

bool IsIdenticalArrays(int Array1[],int Array2[]) {
    for (int i = 0; i < SIZE; i++) {
        if (Array1[i] != Array2[i]) return false;
    }
    return true;
}

/*Exercise 2: (10 points)
You are required to write a program which will take input from user in two integer arrays.
The program should compare both arrays for checking if both arrays are totally identical
(Exactly same). Write a boolean function which return true if arrays are totally identical
otherwise return false. Example of two identical (Exactly same) arrays:

Example of two identical (Exactly same) arrays :
Array1  Array2
1       1
2       2
3       3
5       5
7       7
9       9

Main function:
Declare and initialize two integer Arrays;
IsIdenticalArrays(Array1,Array2);
Output if arrays are equal or not;*/