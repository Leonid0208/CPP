#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, newyork;
	int res[10]{ 0 };
	cout << "Введите колличество чисел" << '\n';
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> newyork;
		res[newyork] += 1;
	}
	for(int i = 0; i < 10; i++) {
		if (res[i] != 0)
			cout << i << ": " << res[i] << "\n";
	}
	

	
}