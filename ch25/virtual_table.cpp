#include <iostream>
#include <string_view>

class Base {
public:
	std::string_view getName() const { return "Base"; }
	virtual std::string_view getNameVirtual() const { return "Base"; }
};

class Derived : public Base {
public:
	std::string_view getName() const { return "Derived"; }
	virtual std::string_view getNameVirtual() const override { return "Derived"; }
};

class Base2 {
public:
	virtual void function1() { std::cout << "Base2::function1()" << '\n'; };
	virtual void function2() { std::cout << "Base2::function2()" << '\n'; };
};

class D1 : public Base2 {
public:
	void function1() override { std::cout << "D1::function1()" << '\n'; };
};

class D2 : public Base2 {
public:
	void function2() override { std::cout << "D2::function2()" << '\n';};
};

int main() {
	Derived derived {};
	Base& base { derived };

	std::cout << "base has static type " << base.getName() << '\n';
	std::cout << "base has dynamic type " << base.getNameVirtual() << '\n';


	D1 d1 {};
	Base2* dPtr = &d1;
	dPtr->function1();

	Base2 b {};
	Base2* bPtr = &b;
	bPtr->function1();

	return 0;
}
