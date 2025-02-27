#include <iostream>
using namespace std;

void reverse(int* arr, int arrSize) {
    for (int i = 0; i < arrSize / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[arrSize - i - 1];
        arr[arrSize - i - 1] = temp;
    }
}

int main() {
    int arrSize;
    cout << "enter the size of 1D array: ";
    cin >> arrSize;

    int* arr = new int[arrSize];

    cout << "Enter elements row wise: " << endl;
    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }

    reverse(arr, arrSize);

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

    delete[] arr;
    return 0;
}

/*Question No. 2 (CLO No. 1) Marks: 6
Write a program that dynamically allocates memory for 1D array. Make a function which reverses the array elements
and a function to display the reversed array.*/