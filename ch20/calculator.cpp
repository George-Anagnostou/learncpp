#include <functional>
#include <iostream>

int getInteger() {
	std::cout << "Enter an integer: ";
	int num {};
	std::cin >> num;
	return num;
}

char getOperator() {
	while (true) {
		std::cout << "Enter an arithmetic operation: ";
		char op {};
		std::cin >> op;

		switch (op) {
		case '+':
		case '-':
		case '*':
		case '/':
			return op;
		default:
			continue;
		}
	}
}

int add(int x, int y) {
	return x + y;
}

int subtract(int x, int y) {
	return x - y;
}

int multiply(int x, int y) {
	return x * y;
}

int divide(int x, int y) {
	return x / y;
}

using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char op) {
	switch (op) {
	case '+':
		return &add;
	case '-':
		return &subtract;
	case '*':
		return &multiply;
	case '/':
		return &divide;
	}

	return nullptr;
}

int main() {
	int x { getInteger() };
	char op { getOperator() };
	int y { getInteger() };

	ArithmeticFunction func { getArithmeticFunction(op) };

	if (func) {
		std::cout << x << ' ' << op << ' ' << y << " = " << func(x, y) << '\n';
	}

	return 0;
}
