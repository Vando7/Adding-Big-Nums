///
/// Old OOP project from the second semester.
///
#include<iostream>
#include"bint.h"

int main() {
	bint a;
	char buffer[1000];
	std::cout << "Input A: ";
	std::cin >> buffer;
	a.setValue(buffer);

	bint b;
	std::cout << "Input B: ";
	std::cin >> buffer;
	b.setValue(buffer);

	std::cout << "\n";

	std::cout << "A + B = ";
	bint c = b + a;
	c.print();

	std::cout << "\n";

	return 0;
}