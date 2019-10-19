
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int fac, res;
	while (true) {
		res = 1;
		cout << "Введите число, факториал которого вы хотите найти" << endl;
		cin >> fac;
		if (fac >= 1) {
			for (int i = 1; i <= fac; i++) {
				res *= i;
			}
			cout << res << endl;
		}
		else
			cout << "Неверный формат ввода" << endl;
	}
}


