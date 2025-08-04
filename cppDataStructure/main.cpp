#include <iostream>
#include <string>

using namespace std;

#define TAB_WEIGHTS 10

// Nested structure example
struct Dimensions {
    float length;
    float width;
    float height;
};

// Main product structure with nested Dimensions
struct Product {
    int weight;
    float price;
    Dimensions size;  // Nested structure
};

Product banane, apple, ananas;

// Student structure with nested Address structure
struct Student {
    struct Address {  // Nested structure definition
        string street;
        string city;
        int zip;
    } address;  // Nested structure instance

    int mat;
    float moy;
} std1, std2, std3;

// User structure with array
struct User {
    struct LoginInfo {  // Nested structure
        string username;
        string password_hash;
    } credentials;

    int id;
    string name;
} tab[TAB_WEIGHTS];

// typedef : definition of a new type :
// typedef can be useful to define an alias for a type that is frequently used within a program
// typedef created only a synonyms of exciting types
// typedef existing_type new_type_name ;
typedef unsigned int ASCII;


int main() {
    // Initialize banana with nested structure
    banane.weight = 250;
    banane.price = 3.5f;
    banane.size = {15.5f, 3.2f, 3.2f};  // Initialize nested Dimensions
    cout << "Banana - Weight: " << banane.weight << "g, Size: " << banane.size.length << "x" << banane.size.width << "x" << banane.size.height << "cm\n";

    // Initialize student with nested address
    std1.mat = 1001;
    std1.moy = 16.5f;
    std1.address = {"123 Campus Rd", "University City", 12345};
    cout << "\nStudent - Mat: " << std1.mat
         << ", Address: " << std1.address.street << ", "
         << std1.address.city << " " << std1.address.zip << endl;

    // Initialize user with nested credentials
    tab[0].id = 1;
    tab[0].name = "Alice";
    tab[0].credentials = {"alice123", "hashed_password"};
    cout << "\nUser - Name: " << tab[0].name
         << ", Username: " << tab[0].credentials.username << endl;

    // =============================================
    // POINTERS TO NESTED STRUCTURES
    // =============================================

    // Pointer to main structure
    Product* ptrFruit = &banane;
    cout << "Fruit pointer - Price: " << ptrFruit->price << ", Length: " << ptrFruit->size.length << "cm" << endl;

    // Pointer to nested structure
    Dimensions* ptrSize = &banane.size;
    ptrSize->length = 16.0f;  // Modify through pointer
    cout << "Modified size via pointer: " << banane.size.length << "cm" << endl;

    // Pointer to student's nested address
    Student::Address* ptrAddress = &std1.address;  // Using scope resolution
    ptrAddress->city = "College Town";
    cout << "Updated student city: " << std1.address.city << endl;

    // Pointer to array element's nested structure
    User::LoginInfo* ptrCredentials = &tab[0].credentials;
    ptrCredentials->username = "alice_updated";
    cout << "Updated username: " << tab[0].credentials.username << endl;

    // =============================================
    // DYNAMIC ALLOCATION OF NESTED STRUCTURES
    // =============================================

    // Dynamically allocate a product with nested dimensions
    Product* dynProduct = new Product{300, 4.2f, {10.0f, 5.0f, 5.0f}};
    cout << "Dynamic product - Weight: " << dynProduct->weight
         << ", Width: " << dynProduct->size.width << "cm" << endl;
    delete dynProduct;

    // Dynamically allocate a student with nested address
    Student* dynStudent = new Student;
    dynStudent->address = {"456 College Ave", "Grad City", 54321};
    cout << "Dynamic student - Zip: " << dynStudent->address.zip << endl;
    delete dynStudent;

    return 0;
}
