#include <iostream>
#include "Array.hpp"

int main() {
	try {
		Array<int> empty;
		std::cout << "empty size: " << empty.size() << std::endl;
		try {
			(void)empty[0];
		} catch (const std::exception &e) {
			std::cout << "caught exception for empty[0]: " << e.what() << std::endl;
		}

		Array<int> a(5);
		for (unsigned int i = 0; i < a.size(); ++i)
			a[i] = i * 2;
		std::cout << "a: ";
		for (unsigned int i = 0; i < a.size(); ++i)
			std::cout << a[i] << " ";
		std::cout << std::endl;

		Array<int> b(a); // copy constructor
		a[0] = 42;
		std::cout << "after modifying a[0]=42 -> b[0] (should be original 0): " << b[0] << std::endl;

		Array<int> c;
		c = a; // assignment
		c[1] = 99;
		std::cout << "a[1] (should be unchanged): " << a[1] << ", c[1]: " << c[1] << std::endl;

		Array<std::string> s(3);
		s[0] = "hello";
		s[1] = "world";
		s[2] = "!";
		std::cout << "strings: ";
		for (unsigned int i = 0; i < s.size(); ++i)
			std::cout << s[i] << " ";
		std::cout << std::endl;

		Array<int> zeros(3);
		std::cout << "zeros: ";
		for (unsigned int i = 0; i < zeros.size(); ++i)
			std::cout << zeros[i] << " ";
		std::cout << std::endl;

		try {
			std::cout << a[100] << std::endl;
		} catch (const std::exception &e) {
			std::cout << "caught exception for out-of-range access: " << e.what() << std::endl;
		}

	} catch (const std::exception &e) {
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
