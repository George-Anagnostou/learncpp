#include <iostream>

class Simple {
private:
	int m_nID{};

public:
	Simple(int nID)
	: m_nID { nID } {
		std::cout << "Constructing Simple " << nID << '\n';
	}

	~Simple() {
		std::cout << "Destructing Simple " << m_nID << '\n';
	}

	int getID() { return m_nID; }
};

int main() {
	// Allocate a Simple on the stack
	Simple simple { 1 };
	std::cout << simple.getID() << '\n';

	// Allocate a Simple dynamically
	Simple* pSimple { new Simple { 2 } };

	std::cout << pSimple->getID() << '\n';

	delete pSimple;

	return 0;
}
