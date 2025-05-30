#include <iostream>
#include <string_view>

enum AnimalType {
    cat,
    dog,
    chicken,
    snake,
};

constexpr std::string_view animalName(AnimalType type) {
    switch (type) {
        case cat: return "cat";
        case dog: return "dog";
        case chicken: return "chicken";
        case snake: return "snake";
        default: return "unknown";
    }
}

constexpr int numLegs(AnimalType type) {
    switch (type) {
        case cat: return 4;
        case dog: return 4;
        case chicken: return 2;
        case snake: return 0;
        default: return 0;
    }
}

int main() {
    AnimalType animal { cat };
    std::cout << "A " << animalName(animal) << " has "
        << numLegs(animal) << " legs.\n";
    
    AnimalType snakeAinmal { snake };
    std::cout << "A " << animalName(snakeAinmal) << " has "
        << numLegs(snakeAinmal) << " legs.\n";
    
    return 0;
}