
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int randomC;
	int chislo;
	int n = 101;
	int popitki = 0;
	int i;
	int answer = 1;
	while (answer == 1) {
		bool win = false;
		srand(time(NULL));
		randomC = rand() % n;
		cout << "Добро пожаловать в игру 'Отгадайте число от 1 до 100'" << endl;
		cout << "Введите число от 1 до 100" << endl;
		for (i = 0; i < 5; i += 1) {
			cin >> chislo;
			if (chislo == randomC) {
				cout << "Поздравляю! Вы угадали" << endl;
				win = true;
				break;
			}
			else if (chislo < randomC) {
				cout << "Загаданное число больше" << endl;
			}
			else  if (chislo > randomC){
				cout << "Загаданное число меньше" << endl;
			}
			else {
				cout << "Недопустимое значение";
				i -= 1;
			}

		}
		if (i == 5 and win == false) {
			cout << "Вы проиграли. Было загадано: " << randomC << endl;
		}
		cout << "Хотите начать сначала? (1 - ДА )"<< endl;
		cin >> answer;
	
	}



	
}
