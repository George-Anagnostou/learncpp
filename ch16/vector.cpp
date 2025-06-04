#include <iostream>
#include <vector>

void printProduct() {
    std::cout << "Enter 3 integers: ";
    std::vector<int> ints(3);
    std::cin >> ints[0] >> ints[1] >> ints[2];
    
    int sum { ints[0] + ints[1] + ints[2] };
    int product { ints[0] * ints[1] * ints[2] };
    
    std::cout << "The sum is: " << sum << '\n';
    std::cout << "The product is: " << product << '\n';;
}

void noBoundsChecking() {
    std::vector prime { 2, 3, 5, 7, 11 };
    std::cout << prime[3] << '\n';
    std::cout << prime[9] << '\n'; // notice no bounds checking
}

void withBoundsChecking() {
    std::vector prime { 2, 3, 5, 7, 11 };
    std::cout << prime.at(3);
    std::cout << prime.at(9);
}

void hello() {
    std::vector hello { 'h', 'e', 'l', 'l', 'o' };
    std::cout << "The array has " << hello.size() << " elements.\n";
    std::cout << hello[1] << hello.at(1) << '\n';
}

template <typename T>
void passByRef(const std::vector<T>& arr) {
    std::cout << arr[0] << '\n';
}

int main() {
    std::vector squares { 1, 4, 9, 16, 25 };
    
    std::vector<double> temps(365);
    
    printProduct();
    noBoundsChecking();
    // withBoundsChecking();
    hello();
    
    std::vector dbl { 1.1, 2.2, 3.3, 4.4 };
    passByRef(squares);
    passByRef(dbl);
    
    return 0;
}