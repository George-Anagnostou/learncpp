// the size of a struct is at LEAST the sum of its members, but
// sometimes the compiler will add padding - adding gaps between members
#include <iostream>

struct Foo {
    short a {};
    int b {};
    double c {};
};

// minimize padding by defining members in decreasing order of size
struct Foo1 {
    short a {};
    int b {};
    short c {};
};

struct Foo2 {
    int a {};
    short b {};
    short c {};
};

int main() {
    std::cout << "Size of short is " << sizeof(short) << " bytes\n";
    std::cout << "Size of int is " << sizeof(int) << " bytes\n";
    std::cout << "Size of double is " << sizeof(double) << " bytes\n";
    
    std::cout << "Size of Foo is " << sizeof(Foo) << " bytes\n"; 
    
    std::cout << "Size of Foo1 is " << sizeof(Foo1) << " bytes\n";
    std::cout << "Size of Foo2 is " << sizeof(Foo2) << " bytes\n";
    
    return 0;
}