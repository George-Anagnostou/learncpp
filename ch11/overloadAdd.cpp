#include <iostream>

int add(int a, int b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

double add(double a, double b) {
    return a + b;
}

void foo(int) {}
void foo (const int&) {}

int main() {
    
    std::cout << add(1, 2) << '\n';
    std::cout << add(1, 2, 3) << '\n';
    std::cout << add(1.2, 3.2) << '\n';
    std::cout << foo(1) << '\n';

    return 0;
}