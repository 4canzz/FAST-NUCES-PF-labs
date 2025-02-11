//(c) 24L - 6116
#include <iostream>
using namespace std;

void resize(int* &arr, int &size, int new_size) {
    if (new_size > size) {
        int* new_arr = new int[new_size];
        for (int i = 0; i < size; ++i) {
            new_arr[i] = arr[i];
        }
        for (int i = size; i < new_size; ++i) {
            new_arr[i] = 0;
        }
        delete[] arr;
        arr = new_arr;
    } 
    else if (new_size < size) {
        int* new_arr = new int[new_size];
        for (int i = 0; i < new_size; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
    }
    size = new_size;
}

int main() {
    int size = 5;
    int new_size;
    cout << "Enter new size: ";
    cin >> new_size;

    int* arr = new int[size]{2, 32, 4, 34, 51};

    cout << "Before resize: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    resize(arr, size, new_size);

    cout << "After resize: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}


/*Exercise 2: (10 points)
Write a function resize() that takes as arguments: a pointer pointing to the array of integers, its
size, and new_size which can be any number greater than 0. This function should change the size
of the array. If the new size is greater than the previous one, then insert zeroes in new cells.

Example:
Case 1: (new_size < size)
new_size=7, size=5
Before calling resize function:

Array -> 2 32 4 34 51

After calling resize function:

Array -> 2 32 4 34 51 0 0

Case 2: (new_size > size)
new_size=3, size=5
Before calling resize function:

Array -> 2 32 4 34 51

After calling resize function:

Array -> 2 32 4*/