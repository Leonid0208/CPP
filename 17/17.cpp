#include <iostream>
using namespace std;
double weight, height;
double BMI(double weight, double height) {
	return weight;
	return height;
};

void printBMI(double BMI) {
	BMI = weight / (height / 100 * height / 100);
	if (BMI < 18.5)
		cout << "Underweight " << endl;
	else if (18.5 <= BMI  && BMI < 25.0)
		cout << "Normal weight" << endl;
	else if (25.0 <= BMI && BMI < 30.0)
		cout << "Overweight" << endl;
	else
		cout << "Obesity" << endl;
};
int main(){
	setlocale(LC_ALL, "RUSSIAN");
	while (true) {
		cout << "Введите массу тела и рост" << endl;
		cin >> weight;
		cin >> height;
		printBMI(BMI(weight, height));
	}

    
}
