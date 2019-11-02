#include <iostream>
using namespace std;
int main()
{
	///*setlocale(lc_all, "russian");
	//const int pred = 1000001;
	//int n, i, first;
	//i = 0;
	//int n1, n2, n3, n4, n5;
	//n1 = pred;
	//n2 = pred;
	//n3 = pred;
	//n4 = pred;
	//n5 = pred;
	//cout << "введите колличество чисел, которые хотите отсортировать" << endl;
	//cin >> n;*/

	while (i < n) {
		i += 1;
		cin >> first;
		if (n5==PRED){
			if ((first >= n1) && (n5 == PRED)) {
				n5 = n4;
				n4 = n3;
				n3 = n2;
				n2 = n1;
				n1 = first;
			}
			else if ((first >= n2) && (first < n1)) {
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
		}
		if ((n5!=PRED) && (first<n5)){
			n1 = n2;
			n2 = n3;
			n3 = n4;
			n4 = n5;
			n5 = first;
		}
		else if ((n5 != PRED) && (first <= n4) && (first > n5)) {
			n1 = n2;
			n2 = n3;
			n3 = n4;
			n4 = first;
		}
		else if ((n5 != PRED) && (first <= n3) && (first > n4)) {
			n1 = n2;
			n2 = n3;
			n3 = first;
		}
		else if ((n5 != PRED) && (first <= n2) && (first > n3)) {
			n1 = n2;
			n2 = first;
		}
		else if ((n5 != PRED) && (first < n1) && (first > n2)) {
			n1 = first;
		}
		// вывод
		if ((n2 == PRED) && (n1 != PRED))
			cout << n1 << endl;
		else if ((n3 == PRED) && (n2 != PRED))
			cout << n1 << " " << n2 << endl;
		else if ((n4 == PRED) && (n3 != PRED))
			cout << n1 << " " << n2 << " " << n3 << endl;
		else if ((n5 == PRED) && (n4 != PRED))
			cout << n1 << " " << n2 << " " << n3 << " " << n4 << endl;
		else
			cout << n1 << " " << n2 << " " << n3 << " " << n4 << " " << n5 << endl;
		
	}
}
