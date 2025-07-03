#include <iostream>
#include <cstdarg> // for ellipsis

double findAverage(int count, ...) {
	int sum { 0 };

	// access ellipsis through va_list
	std::va_list list;

	// initialize va_list through va_start
	// first arg = ellipsis list, second arg = last non-ellipsis
	va_start(list, count);

	for (int arg { 0 }; arg < count; ++arg) {
		// get values out of ellipsis
		// set type of value
		sum += va_arg(list, int);
	}

	// clean up va_list
	va_end(list);

	return static_cast<double>(sum) / count;
}

int main() {
	std::cout << findAverage(5, 1, 2, 3, 4, 5) << '\n';
	std::cout << findAverage(6, 1, 2, 3, 4, 5, 6) << '\n';

	return 0;
}
