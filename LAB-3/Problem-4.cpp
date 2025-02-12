#include <iostream>
using namespace std;

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

void populateArray(int arr[], int size) {
	cout << "populate array";
	for (int i = 0; i < size; i++){
		cin >> arr[i];
	}
}

void selectionSort(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		int index = i;
		for (int j = i + 1; j < arrSize; j++) {
			if (arr[j] < arr[index])
			{
				index = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
}

int main() {
	int size;
	cout << "Enter size: ";
	cin >> size;

	int* arr = new int[size];

	populateArray(arr, size);

	selectionSort(arr, size);

	printArr(arr, size);
	
	delete[] arr;
	return 0;
}

/*Exercise 4: (10 points)
Write a program that implements the Selection Sort algorithm to sort an array of N integers in
ascending order. The program should:
1. Take an integer N as input, representing the number of elements in the array.
2. Accept N integers as input (separated by spaces).
3. Use Selection Sort to sort the array.
4. Print the sorted array.*/
