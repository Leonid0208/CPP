#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int ch, col;
	while (true) {
		col = 0;
		cout << "Введите простое или составное число" << endl;
		cin >> ch;
		for (int i = 2; i < ch; i++) {
			if (ch % i == 0) {
				col += 1;
				break;
			}
		}
		if (col == 0)
			cout << "Простое" << endl;
		else if (col > 0)
			cout << "Составное" << endl;
		else
			cout << "Недопустимое значение" << endl;
	}
    
}