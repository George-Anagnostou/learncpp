#include <cassert>
#include <iostream>
#include <vector>

namespace Items {
    enum Items {
        health_potion,
        torch,
        arrow,
        max_items,
    };
}

int countTotalItems(const std::vector<int>& inventory) {
    int sum {};
    for (auto elm : inventory) {
        sum += elm;
    }
    return sum;
}

void printItemCounts(const std::vector<int>& inventory) {
    std::cout << "You have " << inventory[Items::health_potion] << " health potion" << (inventory[Items::health_potion] == 1 ? "" : "s") << '\n';
    
    std::cout << "You have " << inventory[Items::torch] << " torch" << (inventory[Items::torch] == 1 ? "" : "es") << '\n';
    
    std::cout << "You have " << inventory[Items::arrow] << " arrow" << (inventory[Items::arrow] == 1 ? "" : "s") << '\n';
}

int main() {
    std::vector inventory { 1, 5, 10 };
    assert(std::size(inventory) == Items::max_items);
    
    printItemCounts(inventory);
    std::cout << "You have " << countTotalItems(inventory) << " total items\n";

    return 0;
}