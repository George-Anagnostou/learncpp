#include <iostream>
#include <string>

int main() {
    // quiz 1
    std::string str { "The rice is cooking" };
    str.erase(4, 11);

    std::cout << str << '\n';

    // quiz 2
    std::string str2 { "I saw a red car yesterday" };
    
    str2.replace(str2.find("red"), std::string("red").length(), "blue");

    std::cout << str2 << '\n';
    
    return 0;
};