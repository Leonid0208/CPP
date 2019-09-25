#include <iostream>
int main() {
	int a = 3, b = 3.14;
	double c = 3, d = 3.14;
	std::cout << a << std::endl;
	std::cout << b << std::endl; //выведет 3 потому, что переменная b - целочисленная 
	std::cout << c << std::endl;
	std::cout << d; //выведет 3.14 
}
