#include <iostream>
using namespace std;

// Enum to identify data types
enum class DataType { CHAR, INT, FLOAT, DOUBLE };

// Regular union
union NamedUnion {
    char c;
    int i;
    float f;
};

// Structure with anonymous union
struct WithAnonymousUnion {
    DataType type;

    // Anonymous union - members are directly accessible in the struct
    union {
        char c;
        int i;
        float f;
        double d;
    };

    // Helper function to print based on type
    void print() const {
        cout << "Value: ";
        switch(type) {
            case DataType::CHAR: cout << c; break;
            case DataType::INT: cout << i; break;
            case DataType::FLOAT: cout << f; break;
            case DataType::DOUBLE: cout << d; break;
        }
        cout << endl;
    }
};

int main() {
    // =============================================
    // Regular (named) union
    // =============================================

    NamedUnion named;
    named.i = 65;
    cout << "\nNamed union:\n";
    cout << "As int: " << named.i << endl;
    cout << "As char: " << named.c << " (ASCII " << (int)named.c << ")" << endl;

    // =============================================
    // Anonymous union demonstration
    // =============================================
    WithAnonymousUnion anon;
    anon.type = DataType::FLOAT;
    anon.f = 3.14159f; // Direct access without .data member

    cout << "\nAnonymous union in struct:\n";
    anon.print();

    // Change type and value
    anon.type = DataType::CHAR;
    anon.c = 'X';
    anon.print();

    // =============================================
    // Anonymous union in local scope
    // =============================================
    cout << "\nLocal anonymous union:\n";
    {
        // Anonymous union in local scope
        union {
            int x;
            double y;
        };

        x = 10;
        cout << "x = " << x << endl;

        y = 3.14;
        cout << "y = " << y << endl;
        cout << "x is now garbage: " << x << endl;
    }

    // =============================================
    // Anonymous union with struct
    // =============================================
    cout << "\nAnonymous union with struct members:\n";
    struct {
        DataType type;
        union {
            char c;
            int i;
            float f;
        };
    } custom;

    custom.type = DataType::INT;
    custom.i = 42;

    if(custom.type == DataType::INT) {
        cout << "Custom value: " << custom.i << endl;
    }

    // =============================================
    // 5. Size comparisons
    // =============================================
    cout << "\nSize comparisons:\n";
    cout << "Named union: " << sizeof(NamedUnion) << " bytes\n";
    cout << "WithAnonymousUnion: " << sizeof(WithAnonymousUnion) << " bytes\n";
    cout << "Note: WithAnonymousUnion is larger due to the enum type tag\n";

    return 0;
}
