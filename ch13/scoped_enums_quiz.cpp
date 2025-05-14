#include <iostream>
#include <string_view>

enum class Animal {
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

constexpr std::string_view getAnimalName(Animal animal) {
    switch (animal) {
        case Animal::pig: return "pig";
        case Animal::chicken: return "chicken";
        case Animal::goat: return "goat";
        case Animal::cat: return "cat";
        case Animal::dog: return "dog";
        case Animal::duck: return "duck";
        default: return "???";
    }
}

constexpr int printNumberOfLegs(Animal animal) {
    switch (animal) {
        case Animal::pig: return 4;
        case Animal::chicken: return 2;
        case Animal::goat: return 4;
        case Animal::cat: return 4;
        case Animal::dog: return 4;
        case Animal::duck: return 2;
        default: return -1;
    }
}

int main() {
    std::cout << "A " << getAnimalName(Animal::cat) << " has " << printNumberOfLegs(Animal::cat) << " legs\n";
    std::cout << "A " << getAnimalName(Animal::chicken) << " has " << printNumberOfLegs(Animal::chicken) << " legs\n";

    return 0;
}