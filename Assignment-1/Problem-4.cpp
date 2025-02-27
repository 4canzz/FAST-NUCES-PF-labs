#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void PickLarger(int* arr1, int* arr2, int* resizedArr, int arrSize) {
    int n = 2;
    for (int i = 0; i < arrSize; i++) {
        if (arr1[i] < arr2[i]) {
            resizedArr[i] = arr2[i];
        }
        else if (arr1[i] > arr2[i]) {
            resizedArr[i] = arr1[i];
        }
        else {
            resizedArr[i] = arr1[i];
        }
    }
    int primeCount = 0;
    int num = 2;
    while (primeCount < arrSize) {
        if (isPrime(num)) {
            resizedArr[arrSize + primeCount] = num;
            primeCount++;
        }
        num++;
    }
}

void ResizeArray(int*& arr, int oldSize, int newSize) {
    int* newArr = new int[newSize];
    for (int i = 0; i < oldSize; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

int main() {
    int arrSize;
    cout << "enter the size of array: ";
    cin >> arrSize;

    int* arr1 = new int[arrSize];
    int* arr2 = new int[arrSize];
    int* resizedArr = new int [arrSize * 2];

    cout << "Enter elements row wise for 1st array: ";
    for (int i = 0; i < arrSize; i++) {
        cin >> arr1[i];
    }

    cout << "Enter elements row wise for 2nd array: ";
    for (int i = 0; i < arrSize; i++) {
        cin >> arr2[i];
    }

    PickLarger(arr1, arr2, resizedArr, arrSize);

    ResizeArray(arr1, arrSize, 2 * arrSize);

    for (int i = 0; i < arrSize * 2; i++) {
        arr1[i] = resizedArr[i];
    }

    cout << "{";
	for (int i = 0; i < arrSize * 2; i++) {
		if (i == (arrSize * 2) - 1) {
			cout << arr1[i];
		}
		else {
			cout << arr1[i] << ", ";
		}
	}
	cout << "}" << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] resizedArr;
    return 0;
}

/*Question No. 4 (CLO No. 1) Marks: 6
Write a function PickLarger( ) which compares the corresponding elements of 1 D dynamic array, picks the
larger element among them and saves the larger element in the output array which is double the size of
original arrays. The remaining elements of the output array will be any prime numbers. Write another function which resize the original array to the output array. Sample Input and Output:
Input:
Array 1: 1 2 1 5 9 1 3 5
Array 2: 8 2 1 0 11 10 3 4
Output:
Output Array: 8 2 1 5 11 10 3 5 2 3 5 7 11 13 17 19*/
