#include <iostream>

template <int N>
constexpr int factorial() {
    static_assert(N >= 0, "N must be non-negative");

    int product { 1 };
    for (int i { 2 }; i <= N; ++i) {
        product *= i;
    }
    
    return product;
}

int main() {
    static_assert(factorial<0>() == 1, "factorial<0>() should be 1");
    static_assert(factorial<3>() == 6, "factorial<3>() should be 6");
    static_assert(factorial<5>() == 120, "factorial<5>() should be 120");

    factorial<-3>(); // should fail to compile

    return 0;
}