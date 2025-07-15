#include <cassert>
#include <iostream>

class IntArray {
private:
	int m_size { 0 };
	int* m_array { nullptr };

	void deepCopy(const IntArray& source) {
		delete[] m_array;
		m_size = source.m_size;

		if (source.m_array) {
			m_array = new int[m_size];

			for (int i { 0 }; i < m_size; ++i) {
				m_array[i] = source.m_array[i];
			}
		} else {
			m_array = nullptr;
		}
	}

public:
	explicit IntArray(int size)
	: m_size { size }
	{
		assert(size > 0 && "IntArray size should be a positive integer");
		m_array = new int[static_cast<std::size_t>(m_size)] {};
	}

	// Copy constructor that does a deep copy
	IntArray(const IntArray& source)
	: m_size { source.m_size }
	{
		m_array = new int[static_cast<std::size_t>(m_size)] {};
		for (int count { 0 }; count < source.m_size; ++count) {
			m_array[count] = source.m_array[count];
		}
	}

	~IntArray() {
		delete[] m_array;
	}

	int& operator[](const int index) {
		assert(index >= 0);
		assert(index < m_size);
		return m_array[index];
	}

	// Assignment operator that does a deep copy
	IntArray& operator=(const IntArray& array) {
		if (this == &array) {
			return *this;
		}

		delete[] m_array;

		m_size = array.m_size;
		m_array = new int[static_cast<std::size_t>(m_size)] {};

		for (int count { 0 }; count < array.m_size; ++count) {
			m_array[count] = array.m_array[count];
		}

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, const IntArray& array);
};

std::ostream& operator<<(std::ostream& out, const IntArray& array) {
	for (int i { 0 }; i < array.m_size; ++i) {
		out << array.m_array[i] << ' ';
	}
	return out;
}

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{ fillArray() };

	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	a[4] = 7;

	std::cout << b << '\n';

	return 0;
}
