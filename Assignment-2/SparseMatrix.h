/**
 * HEADER FILE
 * CS1002
 * Programming Fundeentals - Assignment 2
 * Syed Furqan Hassan
 * 24L - 6116
 * BEE - 2D
 **/

#include <iostream>
using namespace std;

class SparseMatrix {
private:
    int TotalRows;
    int TotalCols;
    int nonZeroCount; // this index keeper is needed to maintain memory efficiency
    int** Elements;
public:
    // constructor
    SparseMatrix(int r = 0, int c = 0, int nzc = 1) : TotalRows(r), TotalCols(c), nonZeroCount(nzc) {
        // allocate memory for non zero elements
        Elements = new int * [nonZeroCount];
        for (int i = 0; i < nonZeroCount; i++) {
            Elements[i] = new int[3]; // to store data in {row, col, val} format
        }
    }

    // copy constructor
    SparseMatrix(const SparseMatrix& m): TotalRows(m.TotalRows), TotalCols(m.TotalCols), nonZeroCount(m.nonZeroCount) {
        // deep copy Elements
        Elements = new int*[m.nonZeroCount];
        for (int i = 0; i < m.nonZeroCount; ++i) {
            Elements[i] = new int[3];
            Elements[i][0] = m.Elements[i][0];
            Elements[i][1] = m.Elements[i][1];
            Elements[i][2] = m.Elements[i][2];
        }
    }

    // destructor
    ~SparseMatrix() {
        for (int i = 0; i < nonZeroCount; ++i) {
            delete[] Elements[i];
        }
        delete[] Elements;
    }

    // helper function to set a non-zero element at a given index (row, col, value)
    void setElement(int index, int row, int col, int val) {
        // check if index is within bounds
        if (index >= nonZeroCount) {
            // increase the size of the Elements array to accommodate more non-zero elements
            int newSize = index + 1;
            int** newElements = new int*[newSize];
            for (int i = 0; i < nonZeroCount; i++) {  // copy existing elements to the new array
                newElements[i] = Elements[i];
            }

            // deallocate the old Elements array
            delete[] Elements;
            Elements = nullptr;  // ensure that old memory is not accessed after delete[] is called
            Elements = newElements;

            // allocate memory for the new element (row, col, val)
            Elements[index] = new int[3];  // Allocate space for a new element (row, column, value)
            nonZeroCount = newSize;  // Update the count of non-zero elements
        }

        // safely set the element at the specified index
        Elements[index][0] = row;
        Elements[index][1] = col;
        Elements[index][2] = val;
    }

    // output a sparse matrix in standard form (both zero and non-zero entries)
    void output() const {
        for (int i = 0; i < TotalRows; i++) {  // loop through all rows
            for (int j = 0; j < TotalCols; j++) {  // loop through all columns
                bool exists = false;

                // check if the current element (i, j) exists is non-zero in the sparse matrix
                for (int k = 0; k < nonZeroCount; k++) {
                    if (Elements[k][0] == i && Elements[k][1] == j) {
                        cout << Elements[k][2] << " ";  // print the value if it's non-zero
                        exists = true;
                        break;
                    }
                }

                // if no non-zero element is found, print 0
                if (!exists) {
                    cout << "0 ";
                }
            }
            cout << endl;  // print new line
        }
    }

    // function to add two sparse matrices if they are compatible for addition and return the resultant
    SparseMatrix add(const SparseMatrix& m) const {
        // check compatibility
        if (TotalRows != m.TotalRows || TotalCols != m.TotalCols) {
            cout << "Matrices have different dimensions, cannot add." << endl;
            return SparseMatrix();  // return empty SparseMatrix
        }

        // resultant sprase matrix matrix can have as many non-zero element, we will start at 0
        SparseMatrix result(TotalRows, TotalCols, 0);

        int i = 0, j = 0, k = 0;

        // loop through the non-zero elements of both matrices and add them to the resultant matrix
        while (i < nonZeroCount && j < m.nonZeroCount) {
            if (Elements[i][0] == m.Elements[j][0] && Elements[i][1] == m.Elements[j][1]) {
                // if both matrices have a non-zero element at the same position, add their values
                result.setElement(k++, Elements[i][0], Elements[i][1], Elements[i][2] + m.Elements[j][2]);
                i++; j++;
            }
            else if (Elements[i][0] < m.Elements[j][0] || (Elements[i][0] == m.Elements[j][0] && Elements[i][1] < m.Elements[j][1])) {
                // Else if the current element in this matrix is smaller (by row and/or column), copy it to result
                result.setElement(k++, Elements[i][0], Elements[i][1], Elements[i][2]);
                i++;
            }
            else {
                // If the current element in matrix m (other matrix) is smaller (by row and/or column), copy it to result
                result.setElement(k++, m.Elements[j][0], m.Elements[j][1], m.Elements[j][2]);
                j++;
            }
        }

        // copy any remaining elements from the first matrix
        while (i < nonZeroCount) {
            result.setElement(k++, Elements[i][0], Elements[i][1], Elements[i][2]);
            i++;
        }

        // copy any remaining elements from matrix m (other matrix)
        while (j < m.nonZeroCount) {
            result.setElement(k++, m.Elements[j][0], m.Elements[j][1], m.Elements[j][2]);
            j++;
        }

        return result;  // Return the resultant sparse matrix
    }

    // function to subtract one sparse matrix from another if they are compatible for subtraction and return the resultant
    SparseMatrix subtract(const SparseMatrix& m) const {
        // check compatibility
        if (TotalRows != m.TotalRows || TotalCols != m.TotalCols) {
            cout << "Matrices have different dimensions, cannot subtract." << endl;
            return SparseMatrix();  // return empty SparseMatrix
        }

        // the resultant sprase matrix matrix can have as many non-zero element, we will start at 0
        SparseMatrix result(TotalRows, TotalCols, 0);

        int i = 0, j = 0, k = 0;

        // loop through the non-zero elements of both matrices and subtract from other, then copy to the resultant matrix
        while (i < nonZeroCount && j < m.nonZeroCount) {
            if (Elements[i][0] == m.Elements[j][0] && Elements[i][1] == m.Elements[j][1]) {
                // if both matrices have a non-zero element at the same position, subtract value of matrix m (other matrix) from this matrix
                result.setElement(k++, Elements[i][0], Elements[i][1], Elements[i][2] - m.Elements[j][2]);
                i++; j++;
            }
            else if (Elements[i][0] < m.Elements[j][0] || (Elements[i][0] == m.Elements[j][0] && Elements[i][1] < m.Elements[j][1])) {
                // else if the current element in this matrix is smaller (by row and/or column), copy it to result
                result.setElement(k++, Elements[i][0], Elements[i][1], Elements[i][2]);
                i++;
            }
            else {
                // if the current element in matrix m (other matrix) is smaller (by row and/or column), copy it to result
                result.setElement(k++, m.Elements[j][0], m.Elements[j][1], m.Elements[j][2]);
                j++;
            }
        }

        // copy any remaining elements from the first matrix
        while (i < nonZeroCount) {
            result.setElement(k++, Elements[i][0], Elements[i][1], Elements[i][2]);
            i++;
        }

        // copy any remaining elements from matrix m (other matrix)
        while (j < m.nonZeroCount) {
            result.setElement(k++, m.Elements[j][0], m.Elements[j][1], m.Elements[j][2]);
            j++;
        }

        return result;  // return the resultant sparse matrix
    }

    // function to multiply two sparse matrices if they are compatible for multiplication and return the resultant.
    SparseMatrix multiply(const SparseMatrix& m) const {
        if (TotalCols != m.TotalRows) {
            cout << "Matrices have different dimensions, cannot multiply." << endl;
            return SparseMatrix();
        }

        // create a temporary matrix with maximum possible non-zero elements
        SparseMatrix tempResult(TotalRows, m.TotalCols, TotalRows * m.TotalCols);
        int count = 0;

        for (int i = 0; i < TotalRows; i++) { // loop through all rows of this matrix
            for (int j = 0; j < m.TotalCols; j++) { // loop through all columns of matrix m (other matrix)
                int sum = 0;

                for (int k = 0; k < TotalCols; k++) {  // multiply row i of first matrix with column j of second matrix
                    bool foundA = false, foundB = false;
                    int valA = 0, valB = 0;

                    for (int a = 0; a < nonZeroCount && !foundA; a++) {  // Find A[i][k]
                        if (Elements[a][0] == i && Elements[a][1] == k) {
                            valA = Elements[a][2];
                            foundA = true;
                        }
                    }

                    for (int b = 0; b < m.nonZeroCount && !foundB; b++) {  // Find B[k][j]
                        if (m.Elements[b][0] == k && m.Elements[b][1] == j) {
                            valB = m.Elements[b][2];
                            foundB = true;
                        }
                    }

                    sum += valA * valB;
                }

                if (sum != 0) {
                    tempResult.setElement(count++, i, j, sum);
                }
            }
        }

        // create final result with exact non-zero count
        SparseMatrix result(TotalRows, m.TotalCols, count);
        for (int i = 0; i < count; i++) {
            result.setElement(i, tempResult.Elements[i][0], tempResult.Elements[i][1], tempResult.Elements[i][2]);
        }

        return result;
    }

    // function to transpose a sparse matrix.
    void transpose() {
        int tempVAL = TotalCols;
        TotalCols = TotalRows;
        TotalRows = tempVAL;
        for (int i = 0; i < nonZeroCount; i++) {  //iterate through each element and swap their row and columnn value
            int temp = Elements[i][0];
            Elements[i][0] = Elements[i][1];
            Elements[i][1] = temp;
        }
    }
};
