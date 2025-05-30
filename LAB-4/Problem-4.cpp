//(c) 24L - 6116
#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Enter the size of the matrix (n x n): ";
	cin >> n;

	int** matrix = new int*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}

	cout << "Enter elements of the matrix: "<< endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	cout << "Original Matrix: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	int** transpose = new int*[n];
	for (int i = 0; i < n; i++) {
		transpose[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			transpose[j][i] = matrix[i][j];
		}
	}
	cout << "Transposed Matrix:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << transpose[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
		delete[] transpose[i];
	}

	delete[] matrix;
	delete[] transpose;

	return 0;
}

/*Exercise 4: (10 marks)
Write a C++ program to create a dynamic 2-D array of size n x n. Fill the array and find its
transpose using double pointers. Print both the original and transposed matrices.*/
