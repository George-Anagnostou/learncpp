#include <iostream>
#include <optional>
#include <string>
#include <string_view>

enum Pet {
    cat,
    dog,
    pig,
    whale,
};

constexpr std::string_view getPetName(Pet pet) {
    switch (pet) {
        case cat: return "cat";
        case dog: return "dog";
        case pig: return "pig";
        case whale: return "whale";
        default: return "???";
    }
}

constexpr std::optional<Pet> getPetFromString(std::string_view sv) {
    if (sv == "cat") return cat;
    if (sv == "dog") return dog;
    if (sv == "pig") return pig;
    if (sv == "whale") return whale;

    return {};
}

// overload the >> operator for input
std::istream& operator>>(std::istream& in, Pet& pet) {
    std::string s;
    in >> s;

    std::optional<Pet> match { getPetFromString(s) };
    if (match) {
        pet = *match;
        return in;
    }
    
    in.setstate(std::ios_base::failbit);
    pet = {};

    return in;
}

int main() {
    std::cout << "Enter a pet: cat, dog, pig, or whale: ";
    Pet pet{};
    std::cin >> pet;

    // std::optional<Pet> pet { getPetFromString(s) };

    // if (!pet) {
    //     std::cout << "You entered an invalid pet\n";
    // } else {
    //     std::cout << "You entered: " << getPetName(*pet) << '\n';
    // }
    
    if (std::cin) {
        std::cout << "You chose: " << getPetName(pet) << '\n';
    } else {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "You pet was not valid\n";
    }
    
    return 0;
}