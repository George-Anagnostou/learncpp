#include <iostream>
#include <string>

template <typename T1, typename T2, typename T3>
class Triad {
private:
    T1 m_first {};
    T2 m_second {};
    T3 m_third {};

public:
    Triad(const T1& first, const T2& second, const T3& third)
        : m_first { first }
        , m_second { second }
        , m_third { third } {}
    
    T1 first() const { return m_first; }
    T2 second() const { return m_second; }
    T3 third() const { return m_third; }
    
    void print() const;
};

template <typename T1, typename T2, typename T3>
void Triad<T1, T2, T3>::print() const {
    std::cout << '[' << m_first << ", " << m_second << ", " << m_third << ']';
}

int main() {
    Triad<int, int, int> t1 { 1, 2, 3 };
    t1.print();
    std::cout << '\n';
    std::cout << t1.first() << '\n';
    
    using namespace std::literals::string_literals;
    const Triad t2 { 1, 2.3, "Hello"s };
    t2.print();
    std::cout << '\n';

    return 0;
}