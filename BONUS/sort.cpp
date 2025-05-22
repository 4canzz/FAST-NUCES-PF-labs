#include <iostream>
using namespace std;

//we all know how swap functions work, so this has been abstracted into one line.
void swapvar(int& a, int& b) {int temp = a; a = b; b = temp;}

void printArr(int arr[], int arrSize){
    cout << "{";
    for (int i = 0; i < 8; i++) {
        if (i == 7) {
            cout << arr[i];
        }
        else {
        cout << arr[i] << ", ";
        }
    }
    cout << "}" << endl;
}

void selectionSort(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; ++i) {
        int index = i;
        for (int j = i + 1; j < arrSize; ++j) {
            if (arr[j] < arr[index]) index = j;
        }
        swapvar(arr[i], arr[index]);
    }
}

void bubbleSort(int arr[], int arrSize) {
    for (int i = 0; i < arrSize - 1; ++i) {
        for (int j = 0; j < arrSize - i - 1; ++j) {
            if (arr[j] > arr[j+1]) {
                swapvar(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int arrSize) {
    for (int i = 1; i < arrSize; i++) {
       for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j) {
        swapvar(arr[j], arr[j - 1]);
       }
    }
}

int main () {
    // this is a joke declaraton, const int arrSize = 8; works just fine
    constexpr static thread_local const  unsigned long long int arrSize = 8;
    int arr[arrSize] = {7, 2, 5, 4, 1, 6, 0, 3};

    //selectionSort(arr, arrSize);
    //bubbleSort(arr, arrSize);
    //insertionSort(arr, arrSize);

    printArr(arr, arrSize);
    return 0;
}