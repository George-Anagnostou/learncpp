#ifndef INTARRAY_H
#define INTARRAY_H

#include <algorithm> // for std::copy_n
#include <cassert> // for assert()
#include <cstddef> // for std::size_t
#include <initializer_list> // for std::initializer_list

// will hold value of the data itself
// will be able to change in size (so need dynamic allocation)
class IntArray {
private:
	int m_length {};
	int* m_data {};

public:
	IntArray() = default;

	IntArray(int length)
	: m_length { length }
	, m_data { new int[static_cast<std::size_t>(length)] {} }
	{}

	// Constructor with initializer list
	IntArray(std::initializer_list<int> list)
	: IntArray(static_cast<int>(list.size()))
	{
		std::copy(list.begin(), list.end(), m_data);
	}

	// don't need to set m_data to null, since the object will be destroyed immediately after
	~IntArray() {
		delete[] m_data;
	}

	IntArray(const IntArray&) = delete; // avoid shallow copies
	IntArray& operator=(const IntArray& list) = delete; // avoid shallow copies

	// copy assigment with initializer list
	IntArray& operator=(std::initializer_list<int> list) {
		int length { static_cast<int>(list.size()) };
		if (length != m_length) {
			delete[] m_data;
			m_length = length;
			m_data = new int[list.size()] {};
		}

		std::copy(list.begin(), list.end(), m_data);

		return *this;
	}


	void erase() {
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}

	int& operator[](int index) {
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getLength() const { return m_length; }

	// reallocate resizes the array. any existing elements will be destroyed (fast)
	void reallocate(int newLength) {
		erase();
		if (newLength <= 0) {
			return;
		}

		m_data = new int[static_cast<std::size_t>(newLength)];
		m_length = newLength;
	}

	// resize resizes array. any existing elements will be kept (slow)
	void resize(int newLength) {
		if (newLength == m_length) {
			return;
		}

		if (newLength <= 0) {
			erase();
			return;
		}

		// 1. allocate new array
		// 2. copy elements from old array to new array
		// 3. destroy old array
		int* data { new int[static_cast<std::size_t>(newLength)] };

		// how many elements to copy
		if (m_length > 0) {
			int elementsToCopy { (newLength > m_length) ? m_length : newLength };
			std::copy_n(m_data, elementsToCopy, data);
		}

		delete[] m_data;

		m_data = data;
		m_length = newLength;
	}

	// copy constructor
	// IntArray(const IntArray& a) : IntArray(a.getLength()) {
	// 	std::copy_n(a.m_data, m_length, m_data);
	// }

	// copy assignment
	// IntArray& operator=(const IntArray& a) {
	// 	if (&a == this) {
	// 		return *this;
	// 	}
	//
	// 	reallocate(a.getLength());
	// 	std::copy_n(a.m_data, m_length, m_data);
	//
	// 	return *this;
	// }
	//

	void insertBefore(int value, int index) {
		assert(index >= 0 && index <= m_length);

		// create array one element larger than old array
		int* data { new int[static_cast<std::size_t>(m_length+1)] };

		// copy all elements up to index
		std::copy_n(m_data, index, data);

		// insert new value at index
		data[index] = value;

		// copy all elements after index
		std::copy_n(m_data + index, m_length - index, data + index + 1);

		// delete old array and use new array
		delete[] m_data;
		m_data = data;
		++m_length;
	}

	void remove(int index) {
		assert(index >= 0 && index < m_length);

		if (m_length == 1) {
			erase();
			return;
		}

		// create new array one element smaller than old array
		int* data { new int[static_cast<std::size_t>(m_length-1)] };

		// copy all elements up to index
		std::copy_n(m_data, index, data);

		// copy all values after the removed element
		std::copy_n(m_data + index + 1, m_length - index - 1, data + index);

		// delete old array, use new array
		delete[] m_data;
		m_data = data;
		--m_length;
	}

	void insertAtBeginning(int value) { insertBefore(value, 0); }
	void insertAtEnd(int value) { insertBefore(value, m_length); }
};

#endif
