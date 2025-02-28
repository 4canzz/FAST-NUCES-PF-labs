#include <iostream>
using namespace std;

void reverse(int* arr, int arrSize) {
    for (int i = 0; i < arrSize / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[arrSize - i - 1];
        arr[arrSize - i - 1] = temp;
    }
}

void printArr(int arr[], int arrSize){
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

    printArr(arr, arrSize);

    delete[] arr;
    return 0;
}
