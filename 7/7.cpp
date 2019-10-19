
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, c, Ax, Bx, Cx, Ay, By, Cy, S, input, p;
	while (true) {
		cout << "Каким способом хотите найти площадь треугольника?" << endl;
		cout << "1 - через длины сторон a, b, c" << endl;
		cout << "2 - через координаты вершин A, B, C" << endl << endl;
		cin >> input;
		if ((input != 1) && (input != 2)) { //исключение других значений при выборе способа
			cout << "Недопустимое значение" << endl;
			continue;
		}
		else if (input == 1) { //первый сопособ
			cout << "a = ";
			cin >> a;
			cout << "b = ";
			cin >> b;
			cout << "c = ";
			cin >> c;
			if (((a + b) < c) or ((a + c) < b) or ((c + b) < a)) { //исключение
				cout << "Недопустимое значение" << endl;
				continue;
			}
			p = (a + b + c) / 2;
			S = sqrt(p*(p-a)*(p-b)*(p-c)); //вычисление площади
			cout << "S = ";
			cout << S << endl << endl;
		}
		else { //второй способ
			cout << " A(x;y) = ";
			cin >> Ax;
			cin >> Ay;
			cout << " B(x;y) = ";
			cin >> Bx;
			cin >> By;
			cout << " C(x;y) = ";
			cin >> Cx;
			cin >> Cy;
			S = abs((Bx-Ax)*(Cy-Ay)-(Cx-Ax)*(By-Ay))/2; //вычисление площади
			cout << S << endl << endl;
		}


	}
}

