#include <iostream>

template<typename T>
struct Pair {
    T first {};
    T second {};
};

template<typename T>
constexpr T max(Pair<T> p) {
    return (p.first > p.second) ? p.first : p.second;
}

// template with multple type parameters
// can specify default type parameters (int)
template<typename T=int, typename U=int>
struct Pair2 {
    T first {};
    U second {};
};

// template type deduction
// used to deduce the type of the template parameters without
// explicitly specifying them
template<typename T, typename U>
Pair2(T, U) -> Pair2<T, U>;
// when the compiler sees Pair p2 { 1, 2 };, it will 
// deduce it to Pair2<int, int> { 1, 2 };

// works with a single type, too
template<typename T>
Pair(T, T) -> Pair<T>; // Pair p { 1, 2 }; -> Pair<int> { 1, 2 };

template<typename T, typename U>
void printPair2(const Pair2<T, U>& p) {
    std::cout << '[' << p.first << ", " << p.second << "]\n";
}

// a more generic print function
template<typename T>
void print(T p) { // type template parameter will match anything
    std::cout << '[' << p.first << ", " << p.second << "]\n";
}

int main() {
    Pair<int> p1{ 5 , 6 };
    std::cout << p1.first << ' ' << p1.second << '\n';
    
    Pair<double> p2{ 5.5 , 6.6 };
    std::cout << p2.first << ' ' << p2.second << '\n';
    
    Pair<std::string> p3{ "Hello" , "World" };
    std::cout << p3.first << ' ' << p3.second << '\n';
    std::cout << "------------------------\n";
    
    std::cout << max<int>(p1) << " is larger\n"; // explicit call to max<int>
    std::cout << max(p2) << " is larger\n"; // argument deduction to max<double>
    
    
    // Pair2
    Pair2<int, double> p4{ 5 , 6.6 };
    Pair2<double, int> p5{ 5.5 , 6 };
    Pair2<int, int> p6{ 5 , 6 };
    
    printPair2(p5);
    
    print(p1);
    print(p6);
    
    return 0;
}