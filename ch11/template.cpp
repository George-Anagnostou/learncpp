#include <iostream>
#include <string>

template <typename T>
T addOne(T x) {
    return x + 1;
}

// Use function template specialization to
// tell the compiler that using addOne(const char*)
// is not allowed
template <>
const char* addOne(const char* x) = delete;

template<>
std::string addOne(std:string x) = delete;

int main() {
    std::cout << addOne(1) << '\n'; // ok
    std::cout << addOne(1.0) << '\n'; // ok
    std::cout << addOne("hello") << '\n'; // function deleted
    std::cout << addOne(std::string("hello")) << '\n'; // ok

    return 0;
}