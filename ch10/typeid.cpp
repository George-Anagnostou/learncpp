#include <iostream>
#include <typeinfo>

int main()
{
    int i { 2 };
    std::cout << typeid(i).name() << '\n';

    double d { 3.5 };
    std::cout << typeid(i).name() << '\n';

    std::cout << typeid(i + d).name() << ' ' << i + d << '\n';
    
    short a{ 4 };
    short b{ 5 };
    std::cout << typeid(a + b).name() << ' ' << a + b << '\n';

    return 0;
}