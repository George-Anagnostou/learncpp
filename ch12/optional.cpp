#include <iostream>
#include <optional>

std::optional<int> doIntDivision(int x, int y) {
    if (y == 0)
        return {};
    return x / y;
}

int main() {
    std::optional<int> result1 { doIntDivision(20, 5) };
    if (result1)
        std::cout << "Result 1: " << *result1 << '\n';
    else
        std::cout << "Result 1: failed\n";
    
    if (result1.has_value()) { std::cout << "Result 1 has value\n"; }
    
    std::optional<int> result2 { doIntDivision(5, 0) };
    if (result2)
        std::cout << "Result 2: " << *result2 << '\n';
    else
        std::cout << "Result 2: failed\n";
    
    std::cout << result2.value_or(100) << '\n';
    
    return 0;
}