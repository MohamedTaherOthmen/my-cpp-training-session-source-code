#include <iostream>
#include <string>

using namespace std;

// =============================================
// CLASS: CRectangle
// =============================================
class CRectangle {
    int x, y;  // Private member variables (width and height)
public:
    // Sets the dimensions of the rectangle
    void set_values(int a, int b) {
        x = a;
        y = b;
    }

    // Calculates and returns the surface area
    int surface() const {
        return x * y;
    }

    // Prints the coordinates/dimensions of the rectangle
    void printcoordonnantes() const {
        cout << "Rectangle (" << x << ", " << y << ")\n";
    }
};

// =============================================
// CLASS: Student
// =============================================
class Student {
    unsigned long id;  // Student ID
    string name;       // Student name
    float moy;         // Average grade
public:
    // Constructor with ID only
    Student(unsigned long a) : id(a) {}  // Initializes only the ID

    // Constructor with ID and name
    Student(unsigned long a, string nom) : id(a), name(nom) {}  // Initializes ID and name

    // Constructor with ID, name, and average grade
    // This is a constructor initialization list - it initializes member variables
    // before the constructor body executes. More efficient than assigning in the body.
    Student(unsigned long a, string nom, float moyenne) : id(a), name(nom), moy(moyenne) {}

    // Copy constructor - creates a new Student from an existing one
    Student(const Student& student) : id(student.id), name(student.name), moy(student.moy) {}

    // Prints student credentials
    void printCread() const {
        cout << "Id = " << id << "\nName = " << name << "\nMoyenne = " << moy << "\n\n";
    }
};

// =============================================
// CLASS: Teacher
// =============================================
class Teacher {
    unsigned long* id;     // Pointer to ID (dynamic allocation)
    string* name;         // Pointer to name (dynamic allocation)
    float* salaire;       // Pointer to salary (dynamic allocation)
public:
    // Constructor with dynamic memory allocation
    Teacher(unsigned long a, string nom, float sal) {
        id = new unsigned long(a);
        name = new string(nom);
        salaire = new float(sal);
    }

    // Destructor - cleans up dynamically allocated memory
    ~Teacher() {
        delete id;
        delete name;
        delete salaire;
    }

    // Prints teacher credentials
    void printCread() const {
        cout << "Id = " << *id << "\nName = " << *name << "\nSalaire = " << *salaire << "\n\n";
    }
};

// =============================================
// CLASS: noConstructor
// =============================================
class noConstructor {
protected:
    int x, y, z;  // Protected member variables
public:
    // Prints the values of x, y, and z
    void printCred() const {
        cout << x << " " << y << " " << z << "\n";
    }
};

// =============================================
// MAIN FUNCTION
// =============================================

int main() {
    // CRectangle demonstration
    CRectangle recA;
    recA.set_values(4, 5);
    cout << "Surface of rectangle = " << recA.surface() << "\n";
    recA.printcoordonnantes();

    // Student demonstrations
    Student taher(1001, "Mohamed Taher Othmen", 15.05f);
    taher.printCread();

    Student skander(1002, "ISkander Jannen");
    skander.printCread();

    // Teacher demonstration
    Teacher mohamed(9001, "Mohamed Ali", 2800.5f);
    mohamed.printCread();

    // noConstructor demonstration
    noConstructor obj;
    obj.printCred();

    // Copy constructor demonstration
    Student amira(taher);
    amira.printCread();

    return 0;
}
