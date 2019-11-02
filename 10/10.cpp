
#include <iostream>
using namespace std;
int main()
{
	LC_ALL(setlocale, "RUSSIAN");
	double a, res, minus;
	int b;
	while (true) {
		res = 1;
		cin >> a;
		cin >> b;

		
		for (int i = 0; i < abs(b); i++) {
			res = res * a;
		}
		if (b < 0) {
			if (res != 0)
				cout << 1 / res << endl;
			else
				cout << "Ошибка" << endl;
		}
		else if (b > 0)
			cout << res << endl;
		else
			cout << 1 << endl;
	}
}
