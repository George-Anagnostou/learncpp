// data members of structs and classes should typically be owned by the struct or class

#include <iostream>
#include <string>
#include <string_view>

struct Owner {
    std::string name{};
};

struct Viewer {
    std::string_view name {};
};

// getName() returns the user-entered string as a temporary std::string
// This temporary std::string will be destroyed at the end of the 
// full expression containing the function call
std::string getName() {
    std::cout << "Enter a name: ";
    std::string name {};
    std::cin >> name;
    return name;
}

int main() {
    Owner o { getName() };
    std::cout << "Owner: " << o.name << '\n';

    Viewer v { getName() }; // undefined behavior
    std::cout << "Viewer: " << v.name << '\n';
    
    return 0;
}