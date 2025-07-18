#include <iostream>

template <typename T>
class Auto_ptr3 {
	T* m_ptr {};

public:
	Auto_ptr3(T* ptr = nullptr)
	: m_ptr { ptr }
	{}

	~Auto_ptr3() {
		delete m_ptr;
	}

	// Copy constructor
	// deep copy of a.m_ptr to m_ptr
	Auto_ptr3(const Auto_ptr3& a) {
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	// Copy assignment
	// deep copy of a.m_ptr to m_ptr
	Auto_ptr3& operator=(const Auto_ptr3& a) {
		// self-assignment detection
		if (&a == this) {
			return *this;
		}

		delete m_ptr;

		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};

class Resource {
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

Auto_ptr3<Resource> generateResource() {
	Auto_ptr3<Resource> res { new Resource };
	return res; // invoke copy constructor
}

int main() {
	Auto_ptr3<Resource> mainres;
	mainres = generateResource(); // invoke copy assignment

	return 0;
}
