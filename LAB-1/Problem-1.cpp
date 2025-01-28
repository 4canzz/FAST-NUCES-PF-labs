//(c) 24L - 6116
#include <iostream>
using namespace std;

int main () {
    //Declare an integer array of size 10

    int array[10];

    //Ask user to enter 10 numbers for the array
    cout << "enter 10 numbers: ";
    for (int i = 0; i < 10; i++) {
        cin >> array[i];
    }

    //Print out the array in index ascending order
    cout << "{";
    for (int i = 0; i < 10; ++i) {
        cout << array[i];
        if (i != 9) cout << ", ";
    }
    cout << "}" << endl;

    //Print out the array in index descending order

    cout << "{";
    for (int i = 9; i > -1; --i) {
        cout << array[i];
        if (i != 0) cout << ", ";
    }
    cout << "}" << endl;

    //Find the sum of the array and print it out
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += array[i];
    }
    cout << "sum is " << sum << endl;

}

/*Exercise –1 (10 points)
Write a C++ program that includes the following
a) Declare an integer array of size 10
b) Ask user to enter 10 numbers for the array
c) Print out the array in index ascending order
d) Print out the array in index descending order
e) Find the sum of the array and print it out*/
