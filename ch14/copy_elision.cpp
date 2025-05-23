#include <iostream>

class Something {
    int m_x{};

public:
    Something (int x)
        : m_x { x } {
            std::cout << "Normal constructor\n";
        }
    
    Something(const Something& s)
        : m_x { s.m_x } {
            std::cout << "Copy constructor\n";
        }
    
    void print() const { std::cout << "Something(" << m_x << ")\n"; }
};

int main() {
    // should make a call to the normal constructor and copy constructor, but copy elision eliminates the unnecessary call to the copy constructor
    Something s { Something { 5 } }; 
    s.print();

    return 0;
}