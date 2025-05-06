//(c) 24L - 6117 
#include <iostream>
using namespace std;

class C {
private:
	int x;
public:
	C(int ex = 0) : x(ex) {}
	int getX() { return x; }
};

template<typename var>
void resize(var*& arr, int& size, int nsize) {
	var* newarr = new var[nsize];
	if (nsize > size) {
		for (int i = 0; i < size; i++) {
			newarr[i] = arr[i];
		}
		for (int i = size; i < nsize; i++) {
			newarr[i] = var();
		}
		delete[] arr;
		arr = newarr;
	}
	else if (nsize <= size) {
		for (int i = 0; i < nsize; i++) {
			newarr[i] = arr[i];
		}
		delete[] arr;
		arr = newarr;
	}
	size = nsize;
}

template<typename var>
void printArr(var arr[], int arrSize) {
	cout << "{";
	for (int i = 0; i < arrSize; i++) {
		if (i == arrSize - 1) {
			cout << arr[i];
		}
		else {
			cout << arr[i] << ", ";
		}
	}
	cout << "}" << endl;
}

void printCArr(C arr[], int arrSize) {
	cout << "{";
	for (int i = 0; i < arrSize; i++) {
		if (i == arrSize - 1) {
			cout << arr[i].getX();
		}
		else {
			cout << arr[i].getX() << ", ";
		}
	}
	cout << "}" << endl;
}

int main() {
	int size = 5;
	int* intArray = new int[size]{1, 2, 3, 4, 5};
	cout << "Original int array: ";
	printArr(intArray, size);

	int newSize = 8;
	resize<int>(intArray, size, newSize);
	cout << "Resized int array: ";
	printArr(intArray, size);
	delete[] intArray;

	size = 5;
	double* doubleArray = new double[size]{1.2, 2.3, 3.4, 4.5, 5.6};
	cout << "Original double array: ";
	printArr(doubleArray, size);

	newSize = 8;
	resize<double>(doubleArray, size, newSize);
	cout << "Resized double array: ";
	printArr(doubleArray, size);
	delete[] doubleArray;

	size = 5;
	C* CArray = new C[size]{1, 2, 3, 4, 5};
	cout << "Original C array: ";
	printCArr(CArray, size);

	newSize = 8;
	resize<C>(CArray, size, newSize);
	cout << "Resized C array: ";
	printCArr(CArray, size);
	delete[] CArray;

	system("pause");
	return 0;
}

/*Exercise 2: (10 points)
Write a C++ generic ResizeArray function using templates that takes as parameters a single dimensional array’s pointer and its current
size and new size. The function then changes the size of this array to the new size (the way you did in lab2). Test this template
function with various built-in datatype and a user-defined type.*/
