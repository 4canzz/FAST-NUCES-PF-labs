#include <iostream>
using namespace std;

int main(){
	int rows, cols;
	cout << "Enter rows: " << endl;
	cin >> rows;
	cout << "Enter columns: " << endl;
	cin >> cols;

	int** arr = new int*[rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}

	cout << "Enter elements row wise: " << endl;
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			cin >> arr[i][j];
		}
	}

	cout << "2D Array: " << endl;
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i<rows; i++){
		delete[] arr[i];
	}

	delete[] arr;
	return 0;
}

/*Exercise 1: (10 marks)
Write a C++ program that dynamically allocates a 2D integer array of size rows × cols, takes input from the user, prints the array, and then deallocates the memory.*/
