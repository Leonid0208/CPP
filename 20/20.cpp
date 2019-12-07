#include <iostream>
#include <vector>
using namespace std;
using std::vector;
void bubble(vector<int>& arr, int size) {
	int trade = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size; j++) {
			if (arr[j - 1] > arr[j]) {
				trade = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = trade;
			}
		}
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int> arr;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	bubble(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	
}

