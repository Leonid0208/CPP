
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double xt, x0, v0, t, a, g;
	g = -9.8;
	a = g;
	cout << "x0 = "; // просим пользователя ввести x0
	cin >> x0;
	cout << "v0 = "; // просим пользователя ввести v0
	cin >> v0;
	cout << "t = "; // просим пользователя ввести t
	cin >> t;
	while (t < 0) {	//добавляем ограничение, чтобы t не был отрицательным
		cout << "Недопустимое значение t" << endl;
		cout << "t = ";
		cin >> t;
	}
		
	xt = x0 + v0 * t + a * t * t / 2; //считаем результат
	cout << "x(t) = " << xt; //выводим ответ
}
