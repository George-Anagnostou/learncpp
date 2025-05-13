#include <iostream>

int main() {
    int x { 5 };
    std::cout << x << '\n';
    std::cout << &x << '\n';

    std::cout << *(&x) << '\n';
    

    int a { 5 };
    int* ptr { &a };

    std::cout << *ptr << '\n';

    int b { 6 };
    ptr = &b;

    std::cout << *ptr << '\n';
    
    // changing the value of a pointer
    std::cout << "changing the value of a pointer\n";

    int c { 7 };
    int* ptr2 { &c };

    std::cout << c << '\n';
    std::cout << *ptr2 << '\n';
    
    *ptr2 = 6;

    std::cout << c << '\n';
    std::cout << *ptr2 << '\n';
    
    std::cout << "value of &" << '\n';
    std::cout << typeid(c).name() << '\n';
    std::cout << typeid(&c).name() << '\n';
    
    std::cout << "size of a pointer\n";
    char* chPtr{};
    int* iPtr{};
    long double* ldPtr{};
    std::cout << sizeof(chPtr) <<'\n';
    std::cout << sizeof(iPtr) << '\n';
    std::cout << sizeof(ldPtr) << '\n';
    
    std::cout << "dereference a dangling pointer\n";
    int g { 3 };
    int* gPtr{ &g };
    
    std::cout << *gPtr << '\n';

    {
        int h { 33 };
        gPtr = &h;
        
        std::cout << *gPtr << '\n';
    }
    
    std::cout << *gPtr << '\n'; // dangling pointer
    
    return 0;
}