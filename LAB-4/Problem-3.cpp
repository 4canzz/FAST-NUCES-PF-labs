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

	system("pause");
	return 0;
}
