#include "Random.h"
#include <iostream>
#include <string>
#include <string_view>

class Monster {
public:
    enum Type {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        maxMonsterTypes,
    };

private:
    Type m_type{};
    std::string m_name{"???"};
    std::string m_roar{"???"};
    int m_hitPoints{};
    
public:
    Monster(Type type, const std::string_view name, const std::string_view roar, int hitPoints)
        : m_type{type}
        , m_name{name}
        , m_roar{roar}
        , m_hitPoints{hitPoints} {}
        
    constexpr std::string_view getTypeString() const {
        switch (m_type) {
            case dragon:   return "dragon";
            case goblin:   return "goblin";
            case ogre:     return "ogre";
            case orc:      return "orc";
            case skeleton: return "skeleton";
            case troll:    return "troll";
            case vampire:  return "vampire";
            case zombie:   return "zombie";
            default:       return "???";
        }
    }
    
    void print() const {
        std::cout << m_name << " the " << getTypeString();
        if (m_hitPoints <= 0) {
            std::cout << " is dead.\n";
        } else {
            std::cout << " has " << m_hitPoints << " hit points and says " << m_roar << ".\n";
        }
    }
};

namespace MonsterGenerator {
    std::string_view getName(int n) {
        switch(n) {
            case 0: return "Bones";
            case 1: return "Fang";
            case 2: return "Claw";
            case 3: return "Spike";
            default: return "???";
        }
    }
    
    std::string_view getRoar(int n) {
        switch(n) {
            case 0: return "*rattle*";
            case 1: return "*growl*";
            case 2: return "*roar*";
            case 3: return "*screech*";
            default: return "???";
        }
    }

    Monster generate() {
        return Monster { 
            Monster::Type(Random::get(0, Monster::maxMonsterTypes - 1)),
            getName(Random::get(0, 3)),
            getRoar(Random::get(0, 3)),
            Random::get(0, 100) 
        };
    }
    
};

int main() {
    Monster m { MonsterGenerator::generate() };
    m.print();
    
    return 0;
}