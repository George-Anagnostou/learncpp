#include <iostream>
#include <string>
#include <string_view>

class Ball {
private:
    std::string m_color { "none" };
    double m_radius { 0.0 };

public:
    Ball(std::string_view c, double r)
        : m_color { c }
        , m_radius { r } 
        {}
    
    const std::string& getColor() const { return m_color; }
    double getRadius() const { return m_radius; }
};

void print(const Ball& ball) {
    std::cout << "Ball(" << ball.getColor() << ", " << ball.getRadius() << ")\n";
}

int main() {
    Ball ballBlue { "blue", 10 };
    Ball ballRed { "red", 12 };

    print(ballBlue);
    print(ballRed);

    return 0;
}