#include <iostream>
using namespace std;
void factorization(int n) {
	int v, i, prev, s;
	i = 2;
	v = n;
	s = 1;
	prev = 0;
	while (true) {
		if (v % i == 0) {
			v = v / i;
			if (prev == i) {
				s += 1;
			}
			if (prev!=i && prev !=0) {
				if (s == 1) {
					cout << prev << " ";
				}
				else {
					cout << prev << "^" << s << " ";
				}
			}
			if (v == 1) {
				if (s == 1) {
					cout << i << endl;
				}
				else if (prev != i && s != 1) {
					cout << i << endl;
				}
				else
					cout << prev << "^" << s << endl;
				break;
			}
			prev = i;
		}
		else {
			i += 1;
		}
	}
}

int main(){
	setlocale(LC_ALL, "RUSSIAN");
	while (true) {
		cout << endl << "Введите число, которое хотите разложить на множители" << endl;
		int x;
		cin >> x;
		factorization(x);
	}


}
