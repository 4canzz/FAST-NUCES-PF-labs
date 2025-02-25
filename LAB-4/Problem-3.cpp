#include <iostream>
using namespace std;

int main() {
	int rows, cols;
	cout << "Enter rows for 2D Array: " << endl;
	cin >> rows;
	cout << "Enter columns for 2D Array: " << endl;
	cin >> cols;

	int** arr = new int*[rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}

	cout << "Enter elements row wise: " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> arr[i][j];
		}
	}

	cout << "Minimum values in each row: " << endl;
	for (int i = 0; i < rows; i++) {
		int min = arr[i][0];
		for (int j = 0; j < cols; j++) {
			if (arr[i][j] < min) min = arr[i][j];
		}
		cout << min << endl;
	}

	for (int i = 0; i<rows; i++) {
		delete[] arr[i];
	}

	delete[] arr;

	return 0;
}

/*Exercise 3: (10 marks)
Write a C++ program that:
1. Dynamically allocates a 2D matrix of size rows × cols.
2. Takes input for each element from the user.
3. Finds and prints the minimum number in each row of the matrix.
4. Deallocates the dynamically allocated memory.*/
