#include <iostream>

int main()
{
    int count { 1 };
    while (count <= 10)
    {
        std::cout << count << ' ';
        ++count;
    }
    
    std::cout << "done!\n";
    
    count = 1;
    
    while (count <= 50)
    {
        if (count < 10)
        {
            std::cout << '0';
        }
        
        std::cout << count << ' ';

        if (count % 10 == 0)
        {
            std::cout << '\n';
        }
        ++count;
    }
    
    while (true)
    {
        std::cout << "Loop again (y/n)? ";
        char c{};
        std::cin >> c;

        if (c == 'n')
            return 0;
    }

    return 0;
}