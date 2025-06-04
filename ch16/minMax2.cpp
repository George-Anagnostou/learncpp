#include <iostream>
#include <vector>

// print vector
template <typename T>
void printArray(const std::vector<T>& arr) {
    std::cout << "With array ( ";
    for (std::size_t i { 0 }; i < arr.size(); ++i) {
        if (i == arr.size() - 1) {
            std::cout << arr[i] << ' ';
        } else {
            std::cout << arr[i] << ", ";
        }
    }
    std::cout << "):\n";
}

// store indicies of min and max values as std::pair
template <typename T>
std::pair<std::size_t, std::size_t> findMinMaxIdx(const std::vector<T>& arr) {
    if (arr.empty()) {
        return { std::pair<T, T>{} }; // return default values if the vector is empty
    }
    
    std::size_t min {};
    std::size_t max {};
    for (std::size_t i { 1 }; i < arr.size(); ++i) {
        if (arr[i] < arr[min]) {
            min = i;
        }
        if (arr[i] > arr[max]) {
            max = i;
        }
    }
    
    return std::pair<std::size_t, std::size_t>{ min, max };
}

template <typename T>
void printPair(const std::pair<size_t, std::size_t>& pair, const std::vector<T>& arr) {
    std::cout << "The min element has index " << pair.first << " and the value " << arr[pair.first] << '\n';
    std::cout << "The max element has index " << pair.second << " and the value " << arr[pair.second] << '\n';
}

std::vector<int> getInput() {
    std::cout << "Enter numbers to add (use -1 to stop): ";
    std::vector<int> input {};
    while (std::cin) {
        int value {};
        std::cin >> value;
        if (value == -1) {
            break;
        }
        input.push_back(value);
    }
    
    return input;
}

int main() {
    std::vector<int> v { getInput() };

    printArray(v);
    printPair(findMinMaxIdx(v), v);
    
    return 0;
}