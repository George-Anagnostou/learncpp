#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

class MyString {
private:
	std::string m_string{};

public:
	MyString(std::string_view string={})
	: m_string { string }
	{}

	// MyString operator()(int start, int length);
	std::string_view operator()(int start, int length);

	friend std::ostream& operator<<(std::ostream& out, const MyString& string);
};

std::string_view MyString::operator()(int start, int length) {
	assert(start >= 0);
	assert(start + length <= static_cast<int>(m_string.length()) && "MyString::operator(int, int): Substring is out of range");

	// return MyString { m_string.substr(
	// 	static_cast<std::string::size_type>(start), 
	// 	static_cast<std::string::size_type>(length)
	// )};
	
	return std::string_view(m_string).substr(
		static_cast<std::string_view::size_type>(start),
		static_cast<std::string_view::size_type>(length)
	);
}

std::ostream& operator<<(std::ostream& out, const MyString& string) {
	out << string.m_string;
	return out;
}

int main() {
	MyString s { "Hello, World!" };
	std::cout << s(7, 5) << '\n';

	return 0;
}
