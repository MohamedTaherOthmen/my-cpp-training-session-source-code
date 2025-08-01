#include <iostream>
#include <string>

using namespace std;

// =============================================
// BASIC FUNCTION TYPES
// =============================================

// 1. Function with return value
int addNumbers(int a, int b) {
    return a + b;
}

// 2. Void function (no return value)
void printMessage(const string& message) {
    cout << "Message: " << message << endl;
}

// =============================================
// PARAMETER PASSING METHODS
// =============================================

// 3. Function with copy parameters (default behavior)
void modifyCopy(int x) {
    x *= 2;
    cout << "Inside modifyCopy: " << x << endl;
}

// 4. Function with reference parameters
void modifyReference(int& x) {
    x *= 2;
    cout << "Inside modifyReference: " << x << endl;
}

// =============================================
// ADVANCED FUNCTION FEATURES
// =============================================

// 5. Function with default parameter values
void printInfo(string name, int age = 18, string country = "Unknown") {
    cout << "Name: " << name << ", Age: " << age << ", Country: " << country << endl;
}

// 6. Function overloading (same name, different parameters)
double computeArea(double radius) { // Circle
    return 3.14159 * radius * radius;
}

double computeArea(double width, double height) { // Rectangle
    return width * height;
}

// 7. Recursive function
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// =============================================
// INLINE FUNCTIONS
// =============================================

// 8. Inline function - simple operation
inline int square(int x) {
    return x * x;
}

// 9. Inline function with conditional logic
inline int maxValue(int a, int b) {
    return (a > b) ? a : b;
}

// 10. Inline function demonstration with multiple statements
inline void printSquare(int x) {
    cout << "The square of " << x << " is ";
    cout << x * x << endl;
}

// =============================================
// MAIN FUNCTION DEMONSTRATING ALL CONCEPTS
// =============================================

int main() {
    cout << "Hello world!" << endl << endl;

    // 1. Function with return value
    int sum = addNumbers(5, 7);
    cout << "Sum of 5 and 7: " << sum << endl << endl;

    // 2. Void function
    printMessage("Learning C++ functions!");
    cout << endl;

    // 3. Function with copy parameters
    int original = 10;
    cout << "Before modifyCopy: " << original << endl;
    modifyCopy(original);
    cout << "After modifyCopy: " << original << endl << endl;

    // 4. Function with reference parameters
    cout << "Before modifyReference: " << original << endl;
    modifyReference(original);
    cout << "After modifyReference: " << original << endl << endl;

    // 5. Function with default values
    printInfo("Alice"); // Uses default age and country
    printInfo("Bob", 25); // Uses default country
    printInfo("Charlie", 30, "Canada"); // All values provided
    cout << endl;

    // 6. Function overloading
    cout << "Area of circle (radius 5): " << computeArea(5.0) << endl;
    cout << "Area of rectangle (4x6): " << computeArea(4.0, 6.0) << endl << endl;

    // 7. Recursive function
    int num = 5;
    cout << "Factorial of " << num << ": " << factorial(num) << endl << endl;

    // 8-10. Inline functions demonstration
    cout << "=== Inline Functions ===" << endl;
    int val = 4;

    // Using inline square function
    cout << "Square of " << val << ": " << square(val) << endl;

    // Using inline maxValue function
    cout << "Max between 7 and 12: " << maxValue(7, 12) << endl;

    // Using inline printSquare function
    printSquare(5);

    // Multiple inline function calls
    cout << "Square of max between 3 and 9: " << square(maxValue(3, 9)) << endl;

    return 0;
}
