#include <iostream>

// declare default arguments in forwrad declaration
// cannot re-declare default arguments in the function definition
void print(int x, int y=4);

int main() {
    print(1, 2);
    print(3);
    
    return 0;
}

void print(int x, int y) {
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}
