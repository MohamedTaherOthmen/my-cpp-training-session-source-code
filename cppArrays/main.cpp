#include <iostream>
using namespace std;

// Constants for array dimensions
#define numRows 1
#define numCols 8

// Function prototypes
void printArray(int arr[], int size);
void modifyArray(int arr[], int size);
void print2DArray(int arr[][5], int rows);
void modify2DArray(int arr[][5], int rows);

int main()
{
    // =============================================
    // ONE-DIMENSIONAL ARRAYS
    // =============================================

    // Declaring an array (uninitialized)
    int intTab[5]; // Contains garbage values until initialized

    // Initializing an array
    bool boolTab[2] = {true, false};
    float tab[] = {2.5f, 6399.6f, 123.5f}; // Size automatically determined

    // Accessing array values
    cout << "Accessing array values:\n";
    cout << "boolTab[0]: " << boolTab[0] << endl;
    cout << "tab[1]: " << tab[1] << endl << endl;

    // Modifying array values
    intTab[0] = 10;
    intTab[1] = 20;
    cout << "Modified intTab[0]: " << intTab[0] << endl;

    // =============================================
    // MULTIDIMENSIONAL ARRAYS
    // =============================================

    // Declaring multidimensional array (uninitialized)
    char charTab[2][5]; // 2 rows, 5 columns

    // Initializing multidimensional array
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // Using defined constants for array size
    double constTab[numRows][numCols] = {0}; // Initialized to all zeros

    // Accessing multidimensional array values
    cout << "\nAccessing 2D array:\n";
    cout << "matrix[1][2]: " << matrix[1][2] << endl;
    cout << "charTab[0][0]: " << charTab[0][0] << " (uninitialized)\n\n";

    // =============================================
    // PASSING ARRAYS TO FUNCTIONS
    // =============================================

    // Passing 1D array by copy (actually passes pointer)
    cout << "Passing 1D array by copy:\n";
    printArray(intTab, 5);

    // Passing 1D array by reference
    cout << "\nPassing 1D array by reference (modification):\n";
    modifyArray(intTab, 5);
    printArray(intTab, 5);

    // Passing 2D array by copy
    cout << "\nPassing 2D array by copy:\n";
    print2DArray(matrix, 2);

    // Passing 2D array by reference
    cout << "\nPassing 2D array by reference (modification):\n";
    modify2DArray(matrix, 2);
    print2DArray(matrix, 2);

    return 0;
}

// =============================================
// FUNCTION DEFINITIONS
// =============================================

// Function to print 1D array (passing by copy - actually pointer)
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to modify 1D array (passing by reference)
void modifyArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2; // Modifications affect original array
    }
}

// Function to print 2D array (passing by copy)
void print2DArray(int arr[][5], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to modify 2D array (passing by reference)
void modify2DArray(int arr[][5], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] += 10; // Modifications affect original array
        }
    }
}
