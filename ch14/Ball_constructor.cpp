#include <iostream>
#include <string>
#include <string_view>

class Ball {
private:
    std::string m_color { "black" };
    double m_radius { 10.0 };

public:
    Ball(std::string_view color, double radius)
        : m_color { color }
        , m_radius { radius } {
            print();
        }
    
    Ball(std::string_view color)
        : m_color { color } {
            print();
        }

    Ball(double radius)
        : m_radius { radius } {
            print();
        }

    Ball() {
        print();
    }
    
    void print() const {
        std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
    }
};

int main() {
    Ball def{};
    Ball blue { "blue" };
    Ball twenty { 20.0 };
    Ball bluetwenty { "blue", 20.0 };

    return 0;
}