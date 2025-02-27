#include <iostream>
using namespace std;

bool isIdentical(int* arr1, int* arr2,  int arrSize1, int arrSize2) {
    if (arrSize1 != arrSize2) return false;
    for (int i = 0; i < arrSize1; i++) {
        if (arr1[i] != arr2[i]) return false;
    }
    return true;
}

int main() {
    int arrSize1, arrSize2;
    cout << "enter the size of 1st array: ";
    cin >> arrSize1;
    cout << "enter the size of 2nd array: ";
    cin >> arrSize2;

    int* arr1 = new int[arrSize1];
    int* arr2 = new int[arrSize2];

    cout << "Enter elements row wise for 1st array: " << endl;
    for (int i = 0; i < arrSize1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter elements row wise for 2nd array: " << endl;
    for (int i = 0; i < arrSize2; i++) {
        cin >> arr2[i];
    }

    if(isIdentical(arr1, arr2, arrSize1, arrSize2)) {
        cout << "both arrays are identical." << endl;
    }
    else {
        cout << "both arrays are NOT identical." << endl;
    }

    delete[] arr1;
    delete[] arr2;
    return 0;
}

/* Question No. 3 (CLO No. 1) Marks: 6
You are required to write a program which will take input from user in two integer arrays. The
program should compare both arrays for checking if both arrays are totally identical (Exactly same in size
and elements). Write a boolean function which return true if arrays are totally identical otherwise return false.*/