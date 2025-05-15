#include <iostream>

template<typename T>
struct Triad {
    T one {};
    T two {};
    T three {};
};

template<typename T>
Triad(T, T, T) -> Triad<T>;

template<typename T>
void print(const Triad<T>& t) {
    std::cout << '[' << t.one << ", " << t.two << ", " << t.three << ']';
}

int main() {
    Triad t1{ 1, 2, 3 };
    print(t1);

    Triad t2{ 1.2, 3.4, 5.6 };
    print(t2);

    std::cout << __cplusplus <<std::endl;

    return 0;
};