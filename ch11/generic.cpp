#include <iostream>

// use auto for return type to deduce return
// and prevent type conversion / narrowing
template <typename T, typename U>
auto max(T x, U y) {
    return (x < y) ? y : x;
}

template <int N>
void print() {
    std::cout << N << '\n';
}

int main() {
    std::cout << max(2, 3.5) << '\n';

    print<5>(); // non-type template argument (like std::bitset)

    return 0;
}