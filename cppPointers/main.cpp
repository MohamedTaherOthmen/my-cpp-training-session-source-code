#include <iostream>
using namespace std;

void assignPointerType(void *data, int psize);
int functionWithPtr(int a, int b);
void demoFunctionPointer(int (*funcPtr)(int, int), int x, int y);

int main() {
    // =============================================
    // BASIC POINTER OPERATIONS
    // =============================================

    // Clearer variable naming and initialization
    int value = 5;          // Regular integer variable
    int* pointer = nullptr; // Pointer initialized to null (best practice)
    int dereferenced_value;  // Will store dereferenced pointer value

    // Assign address of 'value' to pointer
    pointer = &value;

    cout << "Value of 'value': " << value << endl;
    cout << "Address of 'value': " << &value << endl;
    cout << "Value of 'pointer': " << pointer << " (same as address above)\n";
    cout << "Address of 'pointer' itself: " << &pointer << endl;

    // Dereferencing the pointer
    dereferenced_value = *pointer;
    cout << "Value pointed to by 'pointer': " << dereferenced_value << endl;

    // Modifying value through pointer
    *pointer = 10;
    cout << "\nAfter modifying through pointer:\n";
    cout << "New value of 'value': " << value << endl;
    cout << "New dereferenced value: " << *pointer << endl;

    // =============================================
    // POINTER COMPARISONS
    // =============================================

    int another_value = 20;
    int* another_pointer = &another_value;

    cout << "pointer points to: " << pointer << endl;
    cout << "another_pointer points to: " << another_pointer << endl;

    // Comparing pointer addresses
    if (pointer == another_pointer) {
        cout << "Pointers point to the same address\n";
    } else {
        cout << "Pointers point to different addresses\n";
    }

    // Comparing values through pointers
    if (*pointer == *another_pointer) {
        cout << "Pointers point to equal values\n";
    } else {
        cout << "Pointers point to different values\n";
    }

    // =============================================
    // POINTER TYPE SAFETY
    // =============================================

    double double_value = 3.14;
    // int* int_ptr = &double_value; // This would be a compiler error

    // Proper typed pointer
    double* double_ptr = &double_value;
    cout << "Properly typed pointer value: " << *double_ptr << endl;

    // =============================================
    // NULL vs nullptr
    // =============================================

    int* null_pointer = nullptr; // Modern C++ way (preferred)
    // int* null_pointer = NULL;  // Older C-style (avoid in new code)
    // int* null_pointer = 0;     // Also works but less clear

    if (null_pointer == nullptr) {
        cout << "Pointer is null (doesn't point to valid memory)\n";
    }

    // =============================================
    // POINTER ARITHMETIC
    // =============================================

    int numbers[] = {10, 20, 30, 40, 50};
    int* numbers_ptr = numbers; // Points to first element

    cout << "First element: " << *numbers_ptr << endl;
    numbers_ptr++; // Moves to next element
    cout << "Second element: " << *numbers_ptr << endl;
    numbers_ptr += 2; // Moves two elements forward
    cout << "Fourth element: " << *numbers_ptr << endl;

    // Calculating distance between pointers
    int* first = &numbers[0];
    int* last = &numbers[4];
    cout << "Distance between first and last: " << (last - first) << " elements\n";

    // =============================================
    // POINTER AND ARRAYS
    // =============================================

    int numbersArray[5] = {5, 2, 9, 8, 10};
    int *firstelt = numbersArray, *secondelt;
    secondelt = firstelt++;
    cout << "first element of numbers array : " << *firstelt << endl;
    cout << "second element of numbers array : " << *secondelt << endl;
    *(numbersArray+4) = 12;
    cout << "fourth element of numbers array : " << *(numbersArray+4) << endl;

    // =============================================
    // POINTERS AND STRINGS
    // =============================================

    // Note: const for string literals
    const char* stringptr = "Hello Taher";

    cout << "Full string: " << stringptr << endl;
    cout << "First character: " << *stringptr << endl;
    cout << "After post-increment: " << *(stringptr++) << " (now points to 'e')\n";
    cout << "After += 2: " << *(stringptr += 2) << " (now points to 'l')\n";

    // =============================================
    // POINTER ARITHMETICS
    // =============================================

    int g = 15, h = 20;
    int* po = &g;

    // Dangerous operation - po+1 points to invalid memory!
    cout << "*++po (invalid memory access): " << *++po << endl;

    // Reset pointer to valid memory
    po = &g;
    cout << "Safe operations with defined behavior:\n";
    cout << "Original value: " << *po << endl;
    cout << "After (*po)++: " << (*po)++ << " (g is now " << g << ")\n";

    // =============================================
    // DOUBLE POINTERS
    // =============================================

    int val = 100;
    int* single_ptr = &val;
    int** double__ptr = &single_ptr;

    cout << "val: " << val << endl;
    cout << "single_ptr points to: " << *single_ptr << endl;
    cout << "double_ptr points to single_ptr at: " << double__ptr << endl;
    cout << "**double_ptr gives val: " << **double__ptr << endl;

    // Modifying value through double pointer
    **double__ptr = 200;
    cout << "After modification through double pointer, val: " << val << endl;


    // void pointers :
    void * a;
    assignPointerType(&a, sizeof(int));
    assignPointerType(&a, sizeof(char));


    // null pointer :
    int * pointerr;
    // p has a null pointer value
    pointerr = 0;
    pointerr = nullptr;

    // =============================================
    // POINTER TO FUNCTIONS
    // =============================================

    int m = 10, n = 5;

    // Correct way to declare and initialize function pointer
    int (*funcPtr)(int, int) = functionWithPtr;

    // Using the function pointer
    cout << "Calling through function pointer: " << funcPtr(m, n) << endl;

    // Passing function pointer to another function
    demoFunctionPointer(functionWithPtr, m, n);

    // Alternative syntax
    int (*anotherFuncPtr)(int, int) = &functionWithPtr;
    cout << "Alternative syntax result: " << (*anotherFuncPtr)(m, n) << endl;

    return 0;
}

void assignPointerType(void *data, int psize){
    switch (psize){
        case sizeof(int):
            int* pint;
            pint = (int *) data;
            cout << "It's an integer pointer and we did cast it" << endl;
            break;
        case sizeof(char):
            char *pchar;
            pchar = (char *) data;
            cout << "It's a char pointer and we did cast it" << endl;
            break;
        default:
            cout << "unknown pointer type !!" << endl;
            break;
    }
}


int functionWithPtr(int a, int b) {
    cout << "Executing functionWithPtr with " << a << " and " << b << endl;
    return a + b;
}

void demoFunctionPointer(int (*funcPtr)(int, int), int x, int y) {
    cout << "Inside demoFunctionPointer: ";
    int result = funcPtr(x, y);
    cout << "Result: " << result << endl;
}
