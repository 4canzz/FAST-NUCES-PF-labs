//(c) 24L - 6116
#include <iostream>

using namespace std;

int main() {
    int size, rollNumber;

    // Ask user for the size of the array
    cout << "Enter the size of the array: ";
    cin >> size;

    // Allocate memory dynamically for the array
    int* arr = new int[size];

    // Ask for roll number
    cout << "Enter your roll number: ";
    cin >> rollNumber;

    // Populate the array using pointer arithmetic
    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; i++) {
        *(arr + i) = rollNumber + i;  // Adding roll number with index
    }

    // Display the array using pointer arithmetic
    cout << "Array elements are: ";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    // Deallocate memory to prevent memory leaks
    delete[] arr;

    return 0;
}
