
#include <iostream>
using namespace std;
int main()
{
	LC_ALL(setlocale, "RUSSIAN");
	double a, res, minus;
	int b;
	res = 1;
	cin >> a;
	cin >> b;
	if (b < 0) {
		if (b % 2 != 0) {
			minus = -1;
		}
		b = b * (-1);
	}
	if (b == 0) {
		res = 1;
	}
	for (int i = 0; i < b; i++) {
		res = res * a;
	}
	cout << res*minus;
}
