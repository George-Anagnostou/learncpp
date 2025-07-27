#include <array>
#include <iostream>
#include <string>
#include <string_view>

class Animal {
protected:
	std::string m_name {};

	// constructor is protected, beacuse derived classes should use it, but Animals shouldn't be created directly
	Animal(std::string_view name, std::string_view speak)
	: m_name { name }
	{}

	// to prevent slicing (covered later)
	Animal(const Animal&) = delete;
	Animal& operator=(const Animal&) = delete;

public:
	std::string_view getName() const { return m_name; }
	virtual std::string_view speak() const { return "???"; }
};

class Cat : public Animal {
public:
	Cat(std::string_view name)
	: Animal { name, "Meow" }
	{}

	virtual std::string_view speak() const { return "Meow"; }
};

class Dog : public Animal {
public:
	Dog(std::string_view name)
	: Animal { name, "Woof" }
	{}

	virtual std::string_view speak() const { return "Woof"; }
};

int main() {
	const Cat fred { "Fred" };
	const Cat misty { "Misty" };
	const Cat zeke { "Zeke" };

	const Dog garbo { "Garbo" };
	const Dog pooky { "Pooky" };
	const Dog truffle { "Truffle" };

	// set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
	const std::array<const Animal*, 6>animals { &fred, &misty, &zeke, &garbo, &pooky, &truffle };

	for (const auto animal : animals) {
		std::cout << animal->getName() << " says " << animal->speak() << '\n';
	}

	return 0;
}
