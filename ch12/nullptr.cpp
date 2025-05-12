#include <iostream>
#include <cstddef> // for NULL

void print(int x) {
    std::cout << "print(int): " << x << '\n';
}

void print(int* ptr) {
    std::cout<< "print(int*): " << (ptr ? "non-null\n" : "null\n");
}

// useful to disambiguate from print(int*)
// otherwise, nullptr will be converted to int*
void print(std::nullptr_t) {
    std::cout << "in print(std::nullptr_t)\n";
}

void checkpointers() {
    int x { 5 };
    int* ptr { &x };

    print(ptr); // should always resolve to print(int*)
    print(0); // should always resolve to print(int). hopefully that's expected

    // print(NULL); // ambiguous on gcc and Clang

    print(nullptr); // always print(int*)
}

int main() {
    int x { 5 };
    int* ptr { &x };

    if (ptr == nullptr) {
        std::cout << "ptr is null\n";
    } else {
        std::cout << "ptr is non-null\n";
    }
    
    int* nullPtr {};
    std::cout << "nullPtr is " << (nullPtr==nullptr ? "null\n" : "non-null\n");
    
    // since nulptr as a bool evaluates to true or false, we don't need to explicitly compare it to nullptr
    if (ptr) {
        std::cout << "ptr is non-null\n";
    } else {
        std::cout << "ptr is null\n";
    }
    std::cout << "nullPtr is " << (nullPtr ? "non-null\n" : "null\n");
    
    checkpointers();
    
    return 0;
}