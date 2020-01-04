#include <iostream>
using namespace std;
void swap(int* x, int* y) {
	int i = *x;
	*x = *y;
	*y = i;
};
int msort(int* x, int*y, int*z) {

	while (*x > *y || *x > *z || *y > *z) {
		if (*x > * y)
			swap(x, y);
		else if (*x > *z)
			swap(x, z);
		else if (*y > *z)
			swap(y, z);
	}
	return *z;
}
void info(const int* a) {
	cout << "Адресс: " << a << "; " << "Значение: " << *a << "\n";
}
	
int* add(int* a, const int* b) {
	*a += *b;
	return a;
};
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int a = 22;
	int b = 11;
	int c = 33;
	info(&a);
	info(&b);
	info(&c);
	cout << msort(&a, &b, &c) << "\n";
	info(add(add(&b, &c), &a));

}

