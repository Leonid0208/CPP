
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	while (true) {
		double a, b;
		char do_it, space;
		cout << "Введите пример в формате 'x + y', где '+' - может быть '+', '-', '*', '/'." << endl;
		cin >> a >> do_it >> b;
		switch (do_it)
		{
		case '+': cout << a + b << endl; break;
		case '-': cout << a - b << endl; break;
		case '*': cout << a * b << endl; break;
		case '/':
			if (b == 0) cout << "На ноль делить нельзя";
			else cout << a / b << endl;
			break;

		default:
			cout << "Недопустимое значение знака" << endl;
			break;
		}
		
	}
}
