#include <iostream>

class Simple {
private:
    int m_id{};

public:
    Simple(int id)
        : m_id { id } {}

    int getID() const { return m_id; }
    void setID(int id) { m_id = id; }
    // this gets rewritten as:
    // static void setID(Simple* const this, int id) { this->m_id = id; }
    
    void print() const { std::cout << this->m_id; } // use `this` pointer to access the implicit object and operator-> to select m_id
};

int main() {
    Simple simple{ 1 };
    simple.setID(2);

    simple.print();
    // this actually gets rewritten as:
    // Simple::setID(&simple, 2);

    return 0;
}