#include <iostream>

class Average {
private:
	std::int32_t m_sum_seen{ 0 };
	int m_num_seen{ 0 };

public:
	Average() {}

	friend std::ostream& operator<<(std::ostream& out, const Average& avg) {
		if (avg.m_num_seen == 0) {
			out << 0;
			return out;
		}
		out << static_cast<double>(avg.m_sum_seen) / avg.m_num_seen;
		return out;
	}

	Average& operator+=(std::int32_t x) {
		m_sum_seen += x;
		++m_num_seen;
		return *this;
	}
};

int main() {
	Average avg{};
	std::cout << avg << '\n';

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}
