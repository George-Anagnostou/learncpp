#include <iostream>
#include <string>

struct Monster {
    enum Type {
        ogre,
        dragon,
        orc,
        giant_spider,
        slime,
    };

    Type type {};
    std::string name {};
    int health {};
};

constexpr std::string_view getMonsterTypeString(Monster::Type type) {
    switch (type) {
        case Monster::ogre: return "Ogre";
        case Monster::dragon: return "Dragon";
        case Monster::orc: return "Orc";
        case Monster::giant_spider: return "Giant Spider";
        case Monster::slime: return "Slime";
        default: return "Unknown";
    }
}

void printMonster(const Monster& monster) {
    std::cout << "This " << getMonsterTypeString(monster.type) 
        << " is named " << monster.name 
        << " and has " << monster.health << " health\n";
}

int main() {
    Monster ogre { Monster::ogre, "Torg", 145 };
    Monster slime { Monster::slime, "Blurp", 23 };
    
    printMonster(ogre);
    printMonster(slime);

    return 0;
}