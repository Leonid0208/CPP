#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	long long s, l1, r1, l2, r2, x2;

	while (true) {
		bool prov = false;
		s = 0;
		cout << "Введите значения s, l1, r1, l2, r2 через пробел" << endl;
		cin >> s >> l1 >> r1 >> l2 >> r2;

		for (; l1 <= r1; l1++) {
			for (x2 = l2; x2 <= r2; x2++) {
				if ((l1 + x2) == s) {
					cout << l1 << " " << x2 << endl;
					prov = true;
					break;
				}
				

			}
			if (prov) {
				break;
			}
		}
		if (!prov)
			cout << -1 << endl;
	}
}

