
#include <iostream>
using namespace std;
int main(){
	setlocale(LC_ALL, "Russian");
	int a, b;
	cout << "Введите по очереди два целочисленных числа " << endl;
	cin >> a;
	cin >> b;
	cout << a + b << endl << a - b << endl << a * b << endl << a / b << endl;

	double c, d;
	cout << "Введите по очереди два числа " << endl;
	cin >> c;
	cin >> d;
	cout << c + d << endl << c - d << endl << c * d << endl << c / d << endl;

	int e;
	double f;
	cout << "Введите по очереди два числа " << endl;
	cin >> e;
	cin >> f;
	cout << e + f << endl << e - f << endl << e * f << endl << e / f << endl;

	double g;
	int h;
	cout << "Введите по очереди два числа " << endl;
	cin >> g;
	cin >> h;
	cout << g + h << endl << g - h << endl << g * h << endl << g / h;

}
