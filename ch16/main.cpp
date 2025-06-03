#include <iostream>
#include <vector>
#include "SignedArrayView.h"

int main() {
    std::vector arr { 9, 7, 5, 3, 1 };
    SignedArrayView sarr { arr };

    for (auto index { sarr.ssize() - 1}; index >= 0; --index) {
        std::cout << sarr[index];
    }
    
    return 0;
}