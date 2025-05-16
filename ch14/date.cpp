#include <iostream>

struct Date {
    int year {};
    int month {};
    int day {};

    void print() const {
        std::cout << year << '/' << month << '/' << day <<'\n';
    }
    
    // can overload functions
    void print(std::string_view prefix) const {
        std::cout << prefix << year << '/' << month << '/' << day <<'\n';
    }
};

int main() {
    const Date today { 2025, 05, 15 };
    // today.day = 16; // not possible, since today is const
    today.print();
    
    today.print("Today is: ");

    return 0;
}