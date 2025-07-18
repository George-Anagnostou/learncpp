#include <algorithm>
#include <chrono>
#include <cstddef> // for std::size_t
#include <iostream>

template <typename T>
class DynamicArray {
private:
	T* m_array {};
	int m_length {};

	void alloc(int length) {
		m_array = new T[static_cast<std::size_t>(length)];
		m_length = length;
	}

public:
	DynamicArray(int length) {
		alloc(length);
	}

	~DynamicArray() {
		delete[] m_array;
	}

	// Copy constructor
	// DynamicArray(const DynamicArray &arr) {
	// 	alloc(arr.m_length);
	// 	std::copy_n(arr.m_array, m_length, m_array);
	// }
	DynamicArray(const DynamicArray& arr) = delete; // explicitly delete copy constructor

	// Copy assignment
	// DynamicArray& operator=(const DynamicArray& arr) {
	// 	if (&arr == this) {
	// 		return *this;
	// 	}
	//
	// 	delete[] m_array;
	//
	// 	alloc(arr.m_length);
	// 	std::copy_n(arr.m_array, m_length, m_array);
	//
	// 	return *this;
	// }
	DynamicArray& operator=(const DynamicArray& arr) = delete; // explicitly delete copy assignment
	
	// Move constructor
	DynamicArray(DynamicArray&& arr) noexcept
	: m_array { arr.m_array }
	, m_length { arr.m_length }
	{
		arr.m_length = 0;
		arr.m_array = nullptr;
	}

	// Move assignment
	DynamicArray& operator=(DynamicArray&& arr) noexcept {
		if (&arr == this) {
			return *this;
		}

		delete[] m_array;

		m_length = arr.m_length;
		m_array = arr.m_array;
		arr.m_length = 0;
		arr.m_array = nullptr;

		return *this;
	}

	int getLength() const { return m_length; }
	T& operator[](int index) { return m_array[index]; }
	const T& operator[](int index) const { return m_array[index]; }
};

class Timer {
private:
	using Clock = std::chrono::high_resolution_clock;
	using Second = std::chrono::duration<double, std::ratio<1>>;

	std::chrono::time_point<Clock> m_beg { Clock::now() };

public:
	void reset() {
		m_beg = Clock::now();
	}

	double elapsed() const {
		return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
	}
};

// Return a copy of arr with all values doubled
DynamicArray<int> cloneArrayDouble(const DynamicArray<int>& arr) {
	DynamicArray<int> dbl(arr.getLength());
	for (int i = 0; i < arr.getLength(); ++i) {
		dbl[i] = arr[i] * 2;
	}

	return dbl;
}

int main() {
	Timer t;

	DynamicArray<int> arr(1000000);

	for (int i = 0; i < arr.getLength(); ++i) {
		arr[i] = i;
	}

	arr = cloneArrayDouble(arr);

	std::cout << t.elapsed();

	return 0;
}
