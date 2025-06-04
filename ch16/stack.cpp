#include <iostream>
#include <string_view>
#include <vector>

void print(std::string_view action, int val, std::vector<int> stack) {
    std::cout << action;
    std::cout << '\t';
    
    if (val) {
        std::cout << ' ' << val << ' ';
    } else {
        std::cout << "   ";
    }
    
    std::cout << "(Stack:";

    if (stack.empty()) {
        std::cout << " empty";
    } else {
        for (auto elm : stack) {
            std::cout << ' ' <<  elm;
        }
    }

    std::cout << ")\n";
}

int main() {
    std::vector<int> stack{};
    print("", 0, stack);
    
    stack.push_back(1);
    print("Push", 1, stack);
    
    stack.push_back(2);
    print("Push", 2, stack);

    stack.push_back(3);
    print("Push", 3, stack);

    stack.pop_back();
    print("Pop", 0, stack);

    stack.push_back(4);
    print("Push", 4, stack);

    stack.pop_back();
    print("Pop", 0, stack);
    
    stack.pop_back();
    print("Pop", 0, stack);

    stack.pop_back();
    print("Pop", 0, stack);

    return 0;
}