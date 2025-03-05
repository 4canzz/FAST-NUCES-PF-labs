//(c) 24L - 6116
#include <iostream>
using namespace std;

int main() {
	int rows, cols;
	cout << "Enter rows for both 2D Arrays: " << endl;
	cin >> rows;
	cout << "Enter columns for both 2D Arrays: " << endl;
	cin >> cols;

	int** a = new int*[rows];
	for (int i = 0; i < rows; i++) {
		a[i] = new int[cols];
	}

	cout << "Enter elements row wise for first matrix: " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> a[i][j];
		}
	}

	int** b = new int*[rows];
	for (int i = 0; i < rows; i++) {
		b[i] = new int[cols];

	}

	cout << "Enter elements row wise for second matrix: " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++){
			cin >> b[i][j];
		}
	}



	int** add = new int*[rows];
	for (int i = 0; i < rows; i++){
		add[i] = new int[cols];
	}



	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			add[i][j] = a[i][j] + b[i][j];
		}
	}

	cout << "answer: " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << add[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < rows; i++){
		delete[] a[i];
	}

	for (int i = 0; i < rows; i++){
		delete[] b[i];
	}

	for (int i = 0; i < rows; i++){
		delete[] add[i];
	}

	delete[] b;
	delete[] a;
	delete[] add;
	
	return 0;
}

/*Exercise 2: (10 marks)
Write a C++ program to add two dynamic 2-D matrices (A and B) and store the result in another
dynamic 2-D matrix (C). Assume the dimensions of both matrices are m x n.*/
