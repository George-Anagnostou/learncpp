#include <iostream>
#include <vector>

std::string getName() {
    std::cout << "Enter a name: ";
    std::string name {};
    std::cin >> name;
    return name;
}

void findName(std::vector<std::string_view> names, std::string_view myName) {
    for (auto name : names) {
        if (myName == name) {
            std::cout << name << " was found.\n";
            return;
        }
    }
    std::cout << myName << " was not found.\n";
}

template <typename T>
bool isValueInArray(const std::vector<T>& arr, const T& val) {
    for (const auto& elm : arr) {
        if (val == elm) {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<std::string_view> names { "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };
    std::string_view myName { getName() };
    findName(names, myName);
    
    if (isValueInArray(names, myName)) {
        std::cout << myName << " was found.\n";
    } else {
        std::cout << myName << " was not found.\n";
    }

    return 0;
}