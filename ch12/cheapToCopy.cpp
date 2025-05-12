#include <iostream>

// function-like macro that evaluates to true if the type (or object) is equal or smaller than the size of two memory addresses
// can't use function, since C++ disallows passing types as parameters
#define isSmall(T) (sizeof(T) <= 2 * sizeof(void*))

struct S {
    double a;
    double b;
    double c;
};

int main() {
    std::cout << std::boolalpha;
    std::cout << isSmall(int) << '\n';
    
    double d {};
    std::cout << isSmall(d) << '\n';
    std::cout << isSmall(S) << '\n';
    
    return 0;
}