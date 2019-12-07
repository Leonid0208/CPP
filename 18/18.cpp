#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	srand(time(NULL));
	int arr[20];
	int min, max;
	min = 100;
	max = -100;
	for (int i = 0; i < 20; i++) {
		arr[i] = -100 + rand() % 201;
		cout << arr[i] << " ";
		if (arr[i] < min) {
			min = arr[i];
		}
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	cout << "\n" << min << "\n";
	cout << max << "\n";
	return 0;
}
