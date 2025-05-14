#include <bitset>
#include <iostream>

namespace Flags {
    enum State {
        isHungry,
        isSad,
        isMad,
        isHappy,
        isLaughing,
        isAsleep,
        isDead,
        isCrying,
    };
}

namespace Monster {
    enum MonsterType {
        orc,
        goblin,
        troll,
        ogre,
        skeleton,
    };
}

int main() {
    std::bitset<8> me{};
    me.set(Flags::isHappy);
    me.set(Flags::isLaughing);
    
    std::cout << std::boolalpha;

    std::cout << "I am happy? " << me.test(Flags::isHappy) << '\n';
    std::cout << "I am laughing? " << me.test(Flags::isLaughing) << '\n';
    std::cout << "I am hungry? " << me.test(Flags::isHungry) << '\n';
    
    Monster::MonsterType monster {Monster::troll};

    return 0;
}