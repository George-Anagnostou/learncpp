#include <iostream>

class Accumulator {
private:
    int m_value { 0 };

public:
    void add(int value) { m_value += value; }
    
    friend void print(const Accumulator& accumulator);
};

void print(const Accumulator& accumulator) {
    std::cout << accumulator.m_value;
}

class Value {
private:
    int m_value {};

public:
    explicit Value(int v) : m_value { v } {}
    
    bool isEqualToMember(const Value& v) const;
    friend bool isEqualToNonMember(const Value& v1, const Value& v2);
};

bool Value::isEqualToMember(const Value& v) const {
    return m_value == v.m_value;
}

bool isEqualToNonMember(const Value& v1, const Value& v2) {
    return v1.m_value == v2.m_value;
}

class Humidity; // forward declaration

class Temperature {
private:
    int m_temp { 0 };
public:
    explicit Temperature(int temp) : m_temp { temp } {}

    friend void printWeather(const Temperature& temperature, const Humidity& humidity);
};

class Humidity {
private:
    int m_humidity { 0 };
public:
    explicit Humidity(int humidity) : m_humidity { humidity } {}

    friend void printWeather(const Temperature& temperature, const Humidity& humidity);
};

// since this function is used by both Temperature and Humidity, it doesn't make sense to have it be a member of either class
// better have it be a non-member function that is a friend of both classes, so it can access their private members
void printWeather(const Temperature& temperature, const Humidity& humidity) {
    std::cout << "Temperature: " << temperature.m_temp << "°C, Humidity: " << humidity.m_humidity << "%\n";
}

int main() {
    Accumulator acc{};
    acc.add(5);

    print(acc);
    
    std::cout << '\n';
    
    Value v1 { 5 };
    Value v2 { 6 };

    std::cout << v1.isEqualToMember(v2) << '\n';
    std::cout << isEqualToNonMember(v1, v2) << '\n';
    
    Humidity hum { 10 };
    Temperature temp { 12 };
    printWeather(temp, hum);
    
    return 0;
}