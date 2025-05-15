#include <iostream>

struct Ad {
    int num_watched {};
    double percent_clicked {};
    double average_earnings {};
};

void printAd(const Ad& ad) {
    std::cout << "Num watched: " << ad.num_watched << " Percent clicked: " << ad.percent_clicked << " Average earnings: " << ad.average_earnings << '\n';;
    
    std::cout << "Total revenue: " << (ad.num_watched * ad.percent_clicked * ad.average_earnings) << '\n';
}

struct Fraction {
    double numerator {};
    double denominator {};
};

std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
    out << fraction.numerator << '/' << fraction.denominator;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& fraction) {
    char slash {};
    in >> fraction.numerator >> slash >> fraction.denominator;
    return in;
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    return { lhs.numerator * rhs.numerator, lhs.denominator * rhs.denominator };
}

int main() {
    Ad ad1 { 1000, 0.05, 0.10 };
    
    printAd(ad1);
    
    std::cout << "Fraction 1: ";
    Fraction fraction1 {};
    std::cin >> fraction1;

    std::cout << "Fraction 2: ";
    Fraction fraction2 {};
    std::cin >> fraction2;
    
    Fraction fraction3 = fraction1 * fraction2;
    std::cout << fraction3 << '\n';;

    return 0;
}