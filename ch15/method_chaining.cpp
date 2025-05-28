#include <iostream>

// no method chaining
class Calc1 {
private:
    int m_value{};

public:
    void add(int value) { m_value += value; }
    void sub(int value) { m_value -= value; }
    void mult(int value) { m_value *= value; }

    int getValue() const { return m_value; }
};

// method chaining by returning `*this`
class Calc2 {
private:
    int m_value{};

public:
    Calc2& add(int value) { m_value += value; return *this; }
    Calc2& sub(int value) { m_value -= value; return *this; }
    Calc2& mult(int value) { m_value *= value; return *this; }
    
    int getValue() const { return m_value; }
    
    void reset() { *this = {}; } // reset the object to its default state
                                 // you don't want to call constructors directly, so instead reasign the value of the implicit object
};

int main() {
    Calc1 calc1{};
    calc1.add(5);
    calc1.sub(3);
    calc1.mult(4);
    
    std::cout << "Calc1 value: " << calc1.getValue() << '\n';

    Calc2 calc2 {};
    calc2.add(5).sub(3).mult(4); // method chaining
                                 //
    std::cout << "Calc2 value: " << calc2.getValue() << '\n';
    
    calc2.reset();

    std::cout << "Calc2 value after reset: " << calc2.getValue() << '\n';
    
    return 0;
}