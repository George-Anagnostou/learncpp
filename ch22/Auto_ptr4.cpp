// same as Auto_ptr4, but with move semantics
#include <iostream>

template <typename T>
class Auto_ptr4 {
	T* m_ptr {};

public:
	Auto_ptr4(T* ptr = nullptr)
	: m_ptr { ptr }
	{}

	~Auto_ptr4() {
		delete m_ptr;
	}

	// Copy constructor
	// deep copy of a.m_ptr to m_ptr
	Auto_ptr4(const Auto_ptr4& a) {
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
	}

	// Move constructor
	// transfer ownership from a.m_ptr to m_ptr
	Auto_ptr4(Auto_ptr4&& a) noexcept
	: m_ptr { a.m_ptr } 
	{
		a.m_ptr = nullptr;
	}

	// Copy assignment
	// deep copy of a.m_ptr to m_ptr
	Auto_ptr4& operator=(const Auto_ptr4& a) {
		// self-assignment detection
		if (&a == this) {
			return *this;
		}

		delete m_ptr;

		m_ptr = new T;
		*m_ptr = *a.m_ptr;

		return *this;
	}

	// Move assignment
	// transfer ownership of a.m_ptr to m_ptr
	Auto_ptr4& operator=(Auto_ptr4&& a) noexcept {
		// self assignment detection
		if (&a == this) {
			return *this;
		}

		delete m_ptr;

		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;

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

Auto_ptr4<Resource> generateResource() {
	Auto_ptr4<Resource> res { new Resource };
	return res; // invoke move constructor
}

int main() {
	Auto_ptr4<Resource> mainres;
	mainres = generateResource(); // invoke move assignment

	return 0;
}
