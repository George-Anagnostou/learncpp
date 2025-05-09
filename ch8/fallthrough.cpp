#include <iostream>

int main()
{
    switch(2)
    {
        case 1:
	    std::cout << 1 << '\n';
	case 2:
	    std::cout << 2 << '\n';
	    [[fallthrough]];
	case 3:
	    std::cout << 3 << '\n';
	    break;
	case 4:
	    std::cout << 4 << '\n';
    }

    return 0;
}
