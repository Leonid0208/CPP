#include <iostream>
#include <cmath>
using namespace std;
int main() {
	setlocale(LC_ALL, "RUSSIAN");
	int i;
	double a, b, Xs, Xe, Dx, x, par, min, max;
	cout << "Введите a" << endl;
	cin >> a;
	cout << "Введите b" << endl;
	cin >> b;
	cout << "Введите Xs" << endl;
	cin >> Xs;
	cout << "Введите Xe" << endl;
	cin >> Xe;
	cout << "Введите Dx" << endl;
	cin >> Dx;
	
	x = Xs;
	i = 1;
	min = 100;
	max = exp(x) / (3 + sin(x));
	while (x <= Xe || abs(Xe-x)<0.0001) {
		if (x <= a || abs(a-x)<0.0001) {
			par = exp(x);
		}
		else if (a < x && x < b) {
			par = exp(x) + cos(x);
		}
		else {
			par = tan(x);
		}
		if (par < min) {
			min = par;
		}
		if (par > max) {
			max = par;
		}
		cout << "x = " << x << " y = " << par << endl;
		i += 1;
		x += Dx;
	}
	cout << "max = " << max << endl;
	cout << "min = " << min << endl;
		



}
