#include <iostream>
#include <sstream>
#include <limits> // For numeric_limits
#include <iomanip> // For output formatting

using namespace std;

int main()
{
    // =============================================
    // VARIABLE DECLARATIONS AND TYPES
    // =============================================

    // Fundamental data types
    int a = 10;                  // 4-byte integer
    float b = 3.14f;             // 4-byte floating point
    double c = 3.1415926535;     // 8-byte floating point (higher precision)
    unsigned int ia = 100;       // Only positive integers
    long double lf = 3.141592653589793238L; // Extended precision
    bool expression = true;      // Boolean (true/false)
    char ch = 'A';               // Single character
    string str = "Hello Cpp Course By Coach Taher";    // String object

    // Display sizes of each type
    cout << "Size of int: " << sizeof(int) << " bytes\n";
    cout << "Size of float: " << sizeof(float) << " bytes\n";
    cout << "Size of double: " << sizeof(double) << " bytes\n";
    cout << "Size of bool: " << sizeof(bool) << " bytes\n";

    // =============================================
    // CONSTANTS AND LITERALS
    // =============================================

    // Literal examples
    cout << "Float literal: " << 3.5f << endl;      // float
    cout << "Hex literal: " << 0x15 << endl;        // hexadecimal (21 in decimal)
    cout << "Octal literal: " << 014 << endl;       // octal (12 in decimal)
    cout << "Binary literal: " << 0b1010 << endl;   // binary (10 in decimal, C++14)

    // Const declarations
    const float PI = 3.14159f;
    constexpr int MAX_SIZE = 100; // Compile-time constant

    // =============================================
    // BASIC INPUT/OUTPUT
    // =============================================

    // Output
    cout << "Hello C++ Session By Coach Mohamed Taher Othmen!\n";

    // Formatted output
    cout << fixed << setprecision(5) << "Pi: " << PI << endl;

    // Input
    int in;
    cout << "Enter an integer: ";
    cin >> in;
    cout << "You entered: " << in << endl;

    // String input
    string mystr;
    cout << "Enter a phrase: ";
    getline(cin, mystr);
    cout << "Your phrase: " << mystr << endl;

    // String stream parsing
    int myint;
    stringstream(mystr) >> myint;
    cout << "Extracted integer: " << myint << " (0 if no number found)\n";

    // =============================================
    // CONTROL STRUCTURES
    // =============================================

    // If-else statement
    bool condition = (10 % 2 == 0);
    if (condition) {
        cout << "10 is even\n";
    } else {
        cout << "10 is odd\n";
    }

    // Ternary operator
    cout << "? test: " << (condition ? "Even" : "Odd") << endl;

    // Switch statement
    int x = 3;
    switch (x) {
        case 1:
            cout << "x == 1\n";
            break;
        case 2:
            cout << "x == 2\n";
            break;
        case 3:
            cout << "x == 3\n";
            break;
        default:
            cout << "x > 3\n";
    }

    // =============================================
    // LOOPING STRUCTURES
    // =============================================

    // While loop
    int j = 0;
    while (j < 3) {
        cout << "  Iteration " << j << endl;
        j++;
    }

    // Do-while loop
    j = 0;
    do {
        cout << "  C++ Training Session By Coach Taher\n";
        j++;
    } while (j < 3);

    // For loop
    for (int k = 0; k < 3; k++) {
        cout << "  C++ Training Session!!\n";
    }

    // For loop variations
    j = 0;
    for (; j < 2; ) {
        j++;
        cout << "  C++ By Coach Taher Othmen\n";
    }

    // Loop control (break/continue)
    condition = true;
    j = 0;
    while (condition) {
        j++;
        if (j == 2) {
            break;
        }
        cout << "  This won't print after j == 2\n";
    }

    // =============================================
    // ADDITIONAL CONCEPTS
    // =============================================

    // Type conversion
    double d = 3.14;
    int i = static_cast<int>(d); // C++ style cast
    cout << "Res conversion: " << d << " -> " << i << endl;

    // char []
    char tab[] = {'A', 'B', 'C', 'D', '\0'};
    cout << tab << endl;
    cin >> tab;
    cout << tab << endl;
    string tabString;
    char tabString2[] = "Taher Othmen";
    tabString = tabString2;
    cout << tabString << endl;

    return 0;
}
