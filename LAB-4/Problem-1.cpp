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
	system("pause");
	return 0;
}
