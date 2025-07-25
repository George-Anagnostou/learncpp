#include <iostream>

class Base {
private:
	int m_id {};

public:
	Base(int id=0)
	: m_id { id }
	{
		std::cout << "Base constructed\n";
	}

	int getId() const { return m_id; }
};

class Derived : public Base {
private:
	double m_cost {};

public:
	// how to set m_id in Base? call the constructor explicitly
	Derived(double cost=0.0, int id=0)
	: Base { id }
	, m_cost { cost }
	{
		std::cout << "Derived constructed\n";
	}

	double getCost() const { return m_cost; }
};

int main() {
	Base base { 5 };

	Derived derived { 1.3, 5 };

	std::cout << "Id: " << derived.getId() << '\n';
	std::cout << "Cost: " << derived.getCost() << '\n';

	return 0;
}
