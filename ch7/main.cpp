#include "add.h"
#include "foo.h"
#include "goo.h"
#include "pi.h" // will include copy of pi() here
#include <iostream>

int doSomething(int x, int y)
{
    return x * y;
}

double circumference(double radius); // forward declaration

int main()
{
    std::cout << Foo::doSomething(4, 3) << '\n';
    std::cout << Goo::doSomething(4, 3) << '\n';
    std::cout << ::doSomething(4, 3) << '\n';
    
    std::cout << BasicMath::add(4, 3) << '\n';
    

    std::cout << pi() << '\n';
    std::cout << circumference(2.0) << '\n';

    return 0;
}