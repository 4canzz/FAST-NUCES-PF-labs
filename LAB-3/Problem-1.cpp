#include <iostream>
using namespace std;

void resize(int* &arr, int &size, int nsize) {
    int * newarr = new int[nsize];
    if (nsize > size) {
        for (int i = 0; i < size; i++) {
            newarr[i] = arr[i];
        }
        for (int i = size; i < nsize; i++) {
            newarr[i] = 0;
        }
        delete[] arr;
        arr = newarr;
    }
    else if (nsize <= size) { 
        for (int i = 0; i < nsize; i++) {
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
    }
    size = nsize;
}

void printArr(int arr[], int arrSize){
	cout << "{";
	for (int i = 0; i < arrSize; i++) {
		if (i == arrSize-1) {
			cout << arr[i];
		}
		else {
			cout << arr[i] << ", ";
		}
	}
	cout << "}" << endl;
}

int main() {
    int size, nsize;
    cout << "Enter size: ";
    cin >> size;
    int* arr = new int[size];
    cout << "Make entries: ";
    for (int i = 0; i < size; i++) {
        cin >> *(arr + i);
    } 
    cout << "Enter new size: ";
    cin >> nsize;

    cout << "Before resize: ";
    printArr(arr, size);

    resize(arr, size, nsize);

    cout << "After resize: ";
    printArr(arr, size);

    delete[] arr;
    return 0;
}


/*Exercise 1: (10 points)
Write a function resize() that takes as arguments: a pointer pointing to the array of integers, its
size, and new_size which can be any number greater than 0. This function should change the size
of the array. If the new size is greater than the previous one, then insert zeroes in new cells.
Example:
Case 1: (new_size > size)
new_size=7, size=5
Before calling resize function:

Array -> 2 32 4 34 51

After calling resize function:

Array ->; 2 32 4 34 51 0 0

Case 2: (new_size < size)
new_size=3, size=5
Before calling resize function:

Array -> 2 32 4 34 51

After calling resize function:

Array -> 2 32 4*/