#include <iostream>

struct Employee {
    int id {};
    int age {};
    double wage {};
};

// use member selection operator (.) to access members of a struct from reference
// this does not work with pointers!
void printEmployee(const Employee& emp) {
    std::cout << "ID: " << emp.id << '\n';
    std::cout << "Age: " << emp.age << '\n';
    std::cout << "Wage: " << emp.wage << '\n';
    std::cout << "------------------------\n";
}

struct Point {
    double x {};
    double y {};
};

struct Triangle {
    Point* a {};
    Point* b {};
    Point* c {};
};

struct Paw {
    int claws {};
};

struct Animal {
    std::string name{};
    Paw paw {};
};

int main() {
    Employee joe { 1, 32, 60000.0 };
    
    ++joe.age;
    joe.wage = 68000.0;

    printEmployee(joe);
    
    Employee* ptr { &joe };
    std::cout << (*ptr).id << '\n'; // dereference pointer to get Employee object, then use member selection
    
    // alternatively, use the arrow operator (->) to access members of a struct from a pointer
    std::cout << ptr->id << '\n'; // dereference pointer to get Employee object, then use member selection

    Point a { 1,2 };
    Point b { 3,7 };
    Point c { 10,2 };
    
    Triangle tr { &a, &b, &c };
    Triangle* trptr { &tr };
    
    std::cout << (*(*trptr).c).y << '\n'; // dereference pointer to get Triangle object, then use member selection to get Point object, then use member selection to get y
    // or
    std::cout << trptr -> c -> y << '\n';
    

    // can mix and match member selection and dereferencing
    Animal puma { "Puma", { 5 } };
    Animal* pumaPtr { &puma };

    std::cout << (pumaPtr->paw).claws << '\n';
    
    return 0;
}