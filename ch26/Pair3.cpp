#include <iostream>
#include <string>
#include <string_view>

template<typename T, typename S>
class Pair {
private:
	T m_first {};
	S m_second {};

public:
	Pair(const T& first, const S& second)
	: m_first { first }
	, m_second { second }
	{}

	T& fisrt() { return m_first; }
	S& second() { return m_second; }
	const T& first() const { return m_first; }
	const S& second() const { return m_second; }
};

template<typename S>
class StringValuePair : public Pair<std::string, S> {
public:
	StringValuePair(std::string_view string, const S& second)
	: Pair<std::string, S>{ static_cast<std::string>(string), second }
	{}
};

int main() {
	StringValuePair<int> svp { "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}
