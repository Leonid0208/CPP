#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int x, n;
	while (true) {
		x = 0;
		cout << "Введите 'n'" << endl;
		cin >> n;
		for (int i = 1; i <= n; i *= 2) {
			if (i <= n)
				x += 1;
		}
		if (n == 1)
			cout << 1 << endl;
		else if (n > 1)
			cout << x << endl;
		else if (n == 0)
			cout << 0 << endl;

	}
}

