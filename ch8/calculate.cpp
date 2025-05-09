#include <iostream>

int calculate(int x, int y, char symbol)
{
    switch (symbol)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    case '%':
        return x % y;
    default:
        std::cout << "calculate(): unhandled case\n";
        return 0;
    }
}

int getInteger()
{
    std::cout << "Enter an integer: ";
    int x {};
    std::cin >> x;
    return x;
}

char getOpt()
{
   std::cout << "Enter an operator: ";
   char op {};
   std::cin >> op;
   return op; 
}

bool run()
{
    std::cout << "Continue? (Y/n): ";
    char response {};
    std::cin >> response;
    switch (response) 
    {
    case 'y':
    case 'Y':
        return true;
    case 'n':
    case 'N':
        return false;
    default:
        std::cout << "Invalid response";
        return false;
    }
}

int main()
{
    bool running { true };
    
    while (running)
    {
        int x { getInteger() };
        int y { getInteger() };
        int opt { getOpt() };
        std::cout << calculate(x, y, opt) << '\n';
        
        running = run();
        
        if (std::cin.fail()) {
            std::cout << "Invalid input" << std::endl;
            return 1;
        }
    }

    return 0;
}