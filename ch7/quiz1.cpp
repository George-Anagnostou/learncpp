#include <iostream>

int getUserInput()
{
    int x {};
    std::cin >> x;

    return x;
}

void printValue(int x, std::string_view label)
{
    std::cout << "The " << label << " value is " << x << '\n';
}

int main()
{
    std::cout << "Enter an integer: ";
    int smaller { getUserInput() };
    std::cout << "Enter a large integer: ";
    int larger { getUserInput() };
    
    if (smaller > larger) {
        std::cout << "Swapping the values\n";
        {
            int tmp { smaller };
            smaller = larger;
            larger = smaller;
        } // tmp is destroyed
    }
    
    printValue(2, "smaller");
    printValue(4, "larger");

    return 0;
}