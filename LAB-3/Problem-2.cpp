#include <iostream>
using namespace std;

int arrnum = 0;

void GetData(int arr [], int arrSize) {
    cout << "Enter data for array" << ++arrnum << ": ";
    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }
}

void DisplayData(int arr[], int arrSize){
	cout << "{";
	for (int i = 0; i < arrSize; i++) {
		if (i == arrSize-1) {
			cout << arr[i];
		}
		else {
			cout << arr[i] << ", ";
		}
	}
	cout << "}" << endl;
}

void Print_Min(int arr[], int arrSize) {
    int min = arr[0];
    for (int i = 0; i < arrSize; i++) {
        if(arr[i] < min) min = arr[i];
    }
    cout << "Minimum (arr3): " << min << endl;
}

void Print_Max(int arr[], int arrSize) {
    int max = arr[0];
    for (int i = 0; i < arrSize; i++) {
        if(arr[i] > max) max = arr[i];
    }
    cout << "Maximum (arr3): " << max << endl;
}

int * Merge(int * &array1, int size1, int * &array2, int size2 ) {
    int * array3 = new int[size1 + size2];
    for (int i = 0; i < size1; i++) {
        array3[i] = array1[i];
    }
    for (int i = size1; i < size1 + size2; i++) {
        array3[i] = array2[i-size1];
    }
    return array3;
}

int main() {

    int size1, size2, size3;
    cout << "Enter sizes for array 1 and 2 repectively: ";
    cin >> size1 >> size2;
    size3 = size1 + size2;
    int *array1 = new int[size1];
    int *array2 = new int[size2];

    GetData(array1, size1);
    GetData(array2, size2);

    int *array3 = Merge(array1, size1, array2, size2);

    DisplayData(array3, size3);
    Print_Min(array3, size3);
    Print_Max(array3, size3);
    DisplayData(array3, size3);

    delete[] array1;
    delete[] array2;
    delete[] array3;
    return 0;
}

/*Exercise 2: (10 points)
Implement all the functions called in the following main which creates two dynamic arrays of
sizes size_1 and size_2 respectively. Take input in these arrays from the user. Now create a third
array of size (size_1 + size_2) and insert all the elements of both arrays in this array. Find
minimum and maximum values in array
Example:

Array 1 -> 10 2 13 4
Array 2 -> 3 4 7 6 7

After merging Array1 and Array2:

Array 3 -> 10 2 13 4 3 4 7 6 7

You may test your code using the following main function:
int main()
{
int size1, size2, size3;
cin >> size1 >> size2;
size3 = size1 + size2;
int *array1= new int[size1];
int *array2= new int[size2];
GetData(array1, size1);
GetData(array2, size2);
int *array3= Merge(array1, size1, array2, size2);
DisplayData(array3, size3);
Print_Min(array3, size3);
Print_Max(array3, size3);
DisplayData(array3, size3);
delete [] array1; 
delete [] array2; 
delete [] array3;
return 0;
}*/