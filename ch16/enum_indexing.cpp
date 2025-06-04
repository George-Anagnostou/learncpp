#include <cassert>
#include <iostream>
#include <vector>

namespace Animals {
    enum Animal {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_animals,
    };

    std::vector<int> legs{ 2, 4, 4, 4, 2, 0 };
}

int main() {
    assert(std::size(Animals::legs) == Animals::max_animals);

    std::cout << "An elephant has " << Animals::legs[Animals::elephant] << " legs\n";
    
    return 0;
}