#include <iostream>
using namespace std;


double BMI(double weight, double height) {
	height = height / 100;
	return (weight / height / height);

}

void printBMI(double BMI) {
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
	double weight, height;
	setlocale(LC_ALL, "RUSSIAN");
	while (true) {
		cout << "Введите массу тела и рост" << endl;
		cin >> weight;
		cin >> height;
		printBMI(BMI(weight, height));
	}
}
