#include <iostream>

int MAX = 5;
int MIN = 1;

void printLeft(void)
{
    int outer{MAX};
    while (outer >= MIN)
    {
        int inner{ outer };
        while (inner >= MIN)
        {
            std::cout << inner << ' ';
            --inner;
        }
        std::cout << '\n';
        --outer;
    }
}

void printRight()
{
    int outer{ MIN };
    while (outer <= MAX)
    {
        int inner{ MAX };
        while (inner >= MIN)
        {
            if (inner <= outer)
            {
                std::cout << inner << ' ';
            }
            else
            {
                std::cout << "  ";
            }
            --inner;
        }
        std::cout << '\n';
        ++outer;
    }
}

int main()
{
    printLeft();
    printRight();
    
    return 0;
}