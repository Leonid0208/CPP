// первый случай
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, c;
	cout << "Введите по очереди два числа" << endl;
	cin >> a;
	cin >> b;
	c = b;
	b = a;
	a = c;
	cout << a << endl << b << endl;
	{
		double a, b;
		cout << "Введите по очереди два числа" << endl;
		cin >> a;
		cin >> b;
		a += b;
		b = a - b;
		a -= b;
		cout << a << endl << b;
	}

}

