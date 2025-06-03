#include <iostream>
#include <vector>
#include <limits> // for std::numeric_limits

template <typename T>
T getInput(std::string_view prompt, T low, T high) {
    T val {};
    do {
        std::cout << prompt;
        std::cin >> val;
        
        if (!std::cin) {
            std::cin.clear(); // reset any error flags
        }
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (val < low || val > high);
    
    return val;
}

template <typename T>
void printArray(const T& arr) {
    for (std::size_t index { 0 }; index < arr.size(); ++index) {
        std::cout << arr[index] << ' ';
    }
    
    if (arr.size() > 0) {
        std::cout << '\n';
    }
}

template <typename T>
int findIndex(const std::vector<T>& arr, T num) {
    for (std::size_t index { 0 }; index < arr.size(); ++index) {
        if (arr[index] == num) {
            return static_cast<int>(index);
        }
    }
    return -1;
}

template <typename T>
void search(const std::vector<T>& arr, T low, T high) {
    auto x { getInput("Enter a number between 1 and 9: " , low, high) };
    
    printArray(arr);
    
    int index { findIndex(arr, x) };

    std::cout << "The number " << x;
    if (index == -1) {
        std::cout << " was not found\n";
    } else {
        std::cout << " has index " << index << '\n';
    }
}

// findMax finds the largest value in std::vector
// returns default value if the vector is empty
template <typename T>
T findMax(const std::vector<T>& arr) {
    if (arr.size()==0) {
        return T{};
    }

    T largest {arr[0]};
    for (std::size_t index {0}; index < arr.size(); ++index) {
        if (arr[index] > largest) {
            largest = arr[index];
        }
    }
    return largest;
}

int main() {
    std::vector arr { 4, 5, 7, 3, 8, 2, 1, 9 };
    
    search(arr, 1, 9);
    
    std::vector dblArr { 4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9 };
    
    search(dblArr, 1.0, 9.0);
    
    // find largest value
    std::vector data1 { 84, 92, 76, 81, 56 };
    std::cout << findMax(data1) << '\n';

    std::vector data2 { -13.0, -26.7, -105.5, -14.8 };
    std::cout << findMax(data2) << '\n';

    std::vector<int> data3 {};
    std::cout << findMax(data3) << '\n';
    
    return 0;
}