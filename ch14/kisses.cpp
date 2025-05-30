#include <iostream>
#include <string>

struct Person {
    std::string name {};
    int age {};

    void kisses(const Person& person) {
        std::cout << name << " kisses " << person.name << '\n';
    }
};

int main() {
    Person joe { "Joe", 29 };
    Person jane { "Jane", 28 };

    joe.kisses(jane);

    return 0;
}