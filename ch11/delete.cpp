#include <iostream>

void printInt(int x) {
    std::cout << x << '\n';
}

// delete doesn't delete a function, but
// rather forbids its use
// void printInt(char) = delete;
// void printInt(bool) = delete;

// This function template takes precendence for arguments of other types
// Since this function template is deleted, calls to it halt compliation
template <typename T>
void printInt(T x) = delete;

int main() {
    printInt(97); // ok

    printInt('a'); // function deleted
    printInt(true); // function deleted
    
    printInt(5.0); // ambiguous match

    return 0;
}