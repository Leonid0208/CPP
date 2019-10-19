#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int n, i, first;
	i = 0;
	int n1, n2, n3, n4, n5;
	n1 = 0;
	n2 = 0;
	n3 = 0;
	n4 = 0;
	n5 = 0;
	cout << "Введите колличество чисел, которые хотите отсортировать" << endl;
	cin >> n;
	if ((n < 1) || (n > 100000)) {
		cout << "Недопустимое колличество чисел" << endl;
	}
	while (i<n){
		i+=1;
		cin >> first;
		if ((first >= n1) && (n5==0)) {
			n5 = n4;
			n4 = n3;
			n3 = n2;
			n2 = n1;
			n1 = first;
		}
		else if ((first >= n2) && (first<n1)) {
			n5 = n4;
			n4 = n3;
			n3 = n2;
			n2 = first;
		}
		else if ((first >= n3) && (first < n2)) {
			n5 = n4;
			n4 = n3;
			n3 = first;
		}
		else if ((first >= n4) && (first < n3)) {
			n5 = n4;
			n4 = first;
		}
		else if ((first >= n5) && (first < n4)) {
			n5 = first;
		}
		else if ((n5!=0) && (first<n5)){
			n1 = n2;
			n2 = n3;
			n3 = n4;
			n4 = n5;
			n5 = first;
		}
		else if ((n5 != 0) && (first < n4) && (first > n5)) {
			n1 = n2;
			n2 = n3;
			n3 = n4;
			n4 = first;
		}
		else if ((n5 != 0) && (first < n3) && (first > n4)) {
			n1 = n2;
			n2 = n3;
			n3 = first;
		}
		else if ((n5 != 0) && (first < n2) && (first > n3)) {
			n1 = n2;
			n2 = first;
		}
		else if ((n5 != 0) && (first < n1) && (first > n2)) {
			n1 = first;
		}
		// вывод
		if ((n2 == 0) && (n1 != 0))
			cout << n1 << endl;
		else if ((n3 == 0) && (n2 != 0))
			cout << n1 << " " << n2 << endl;
		else if ((n4 == 0) && (n3 != 0))
			cout << n1 << " " << n2 << " " << n3 << endl;
		else if ((n5 == 0) && (n4 != 0))
			cout << n1 << " " << n2 << " " << n3 << " " << n4 << endl;
		else
			cout << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << endl;
		
	}
}
