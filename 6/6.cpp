
#include <iostream>
using namespace std;
#include <math.h> // подключаем билиотеку 
int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, c, x, d, x1, x2, s;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	d = b * b - 4 * a * c;
	if (d > 0 && a != 0 && b != 0) {
		s = sqrt(d);
		x1 = (-b - s) / 2 / a;
		x2 = (-b + s) / 2 / a;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2;

	}
	else if (d == 0)
		cout << "x = " << (-b / 2 / a);
	else if (a == 0 && b != 0)
		cout << "x = " << (-c / b);
	else if (a != 0 && b == 0)
		cout << "x = " << (sqrt(-c / a));
	else if (a == 0 && b == 0 && c == 0)
		cout << "x - любое число";
	else
		cout << "Решений нет";



}