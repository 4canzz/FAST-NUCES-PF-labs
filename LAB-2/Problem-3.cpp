//(c) 24L - 6116
#include <iostream>
using namespace std;

int main() {
    int size, rollNumber;

    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter your roll number: ";
    cin >> rollNumber;

    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; i++) {
        *(arr + i) = rollNumber + i;  
    }

    cout << "Array elements are: ";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}

/*Exercise 3: (10 points)
Write a code in C++ that asks the user for size of an array, then allocates the required memory
for a dynamic array. Using pointer arithmetic ( and not the [] operator) it should then populate
the array with data (if it is an integer array do add your rollnumber as well), display the data and
upon completion it should deallocate the memory assigned to the array so no memory leak
happens.*/