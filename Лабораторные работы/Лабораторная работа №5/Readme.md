МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>

### Отчёт по лабораторной работе № 5<br/> по дисциплине "Программирование"
<br/>

студента 1 курса группы ПИ-б-о 191(2)
Емельяненко Леонида Алексеевича
направления подготовки 09.03.04 "Программная инженерия"
<br/>

<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>

Симферополь, 2019

#### Цель: Научиться работать с текстовыми файлами. Закрепить навыки работы со структурами.

Напишем программу для выполнения поставленной задачи:

```cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct passanger {
    int PassengerId;
    bool Survived;
    int Pclass;
    string Name;
    string Sex;
    int Age;
    int SibSp;
    int Parch;
    string Ticket;
    double Fare;
    string Cabin;
    char Embarked;
};


std::vector<passanger> Read() {
    std::ifstream file("train.csv");
    vector<passanger> storage;
    string line, data;
    getline(file, line, '\r');
    int i = 0;

    while (file){
    storage.push_back(passanger());
    getline(file, line, '\r');
    stringstream Separate(line);
    int number = 0;

    while (Separate) {
        getline(Separate, data, ',');
        std::stringstream now(data);
        stringstream now2(data);
        switch (number)
        {
        case 0:
            now >> storage[i].PassengerId;
            break;
        case 1:
            now >> storage[i].Survived;
            break;
        case 2:
            now >> storage[i].Pclass;
            break;
        case 3:
            getline(Separate, data, ',');
            now2 << data;
            storage[i].Name = now.str() + ',' + now2.str();
            break;
        case 4:
            now >> storage[i].Sex;
            break;
        case 5:
            now >> storage[i].Age;
            break;
        case 6:
            now >> storage[i].SibSp;
            break;
        case 7:
            now >> storage[i].Parch;
            break;
        case 8:
            now >> storage[i].Ticket;
            break;
        case 9:
            now >> storage[i].Fare;
            break;
        case 10:
            now >> storage[i].Cabin;
            break;
        case 11:
            now >> storage[i].Embarked;
            break;


        }
        number += 1;
    }
    i++;
    }
    
    file.close();
    return storage;
}
void Analysis(std::vector<passanger> storage) {
    int count_passangers,
        survived = 0,
        survived1 = 0,
        survived2 = 0,
        survived3 = 0,
        survived_men = 0,
        survived_women = 0,
        average_age_passanger = 0,
        average_age_men = 0,
        average_age_women = 0,
        state = 0,
        embarkedS = 0,
        embarkedC = 0,
        embarkedQ = 0,
        count_Men = 0,
        count_Women = 0,
        count_for_age = 0;

        
    vector<int> id_of_young;
    count_passangers = size(storage);
    for (int i = 0; i < count_passangers; i++) {
        if (storage[i].Survived) {
            survived += 1;
            if (storage[i].Pclass == 1) {
                survived1 += 1;
            }
            else if (storage[i].Pclass == 2) {
                survived2 += 1;
            }
            else if (storage[i].Pclass == 3) {
                survived3 += 1;
            }
            if (storage[i].Sex == "male") {
                survived_men += 1;
                count_Men += 1;
            }
            else if (storage[i].Sex == "female") {
                survived_women += 1;
                count_Women += 1;
            }
        }
        if (storage[i].Age > 0) {
            average_age_passanger += storage[i].Age;
            count_for_age += 1;
            if (storage[i].Sex == "male") {
                average_age_men += storage[i].Age;
            }
            else if (storage[i].Sex == "female") {
                average_age_women += storage[i].Age;
            }
            if (storage[i].Age < 18) {
                id_of_young.push_back(storage[i].PassengerId);
            }
        }
        if (storage[i].Embarked == 'S'){
            embarkedS += 1;
        }
        else if (storage[i].Embarked == 'C') {
            embarkedC += 1;
        }
        else if (storage[i].Embarked == 'Q') {
            embarkedQ += 1;
        }
    }
    char best_embarked;
    average_age_men = average_age_men / count_Men;
    average_age_women = average_age_women / count_Women;
    average_age_passanger = average_age_passanger / count_for_age;
    if (embarkedS > embarkedC && embarkedS > embarkedQ) {
        best_embarked = 'S';
    }
    else if (embarkedC > embarkedS && embarkedC > embarkedQ) {
        best_embarked = 'C';
    }
    else {
        best_embarked = 'Q';
    }
    cout << embarkedC << " " << embarkedS << " " << embarkedQ;
    std::ofstream out;
    out.open("results.txt");
    out << "Общее число выживших: " << survived << endl;
    out << "Число выживших из 1 класса: " << survived1 << endl;
    out << "Число выживших из 2 класса: " << survived2 << endl;
    out << "Число выживших из 3 класса: " << survived3 << endl;
    out << "Количество выживших женщин: " << survived_women << endl;
    out << "Количество выживших мужчин: " << survived_men << endl;
    out << "Средний возраст пассажира/женский/мужской: " << average_age_passanger << '\\' << average_age_men << '\\' << average_age_women << endl;
    out << "Штат, в котором село больше всего пассажиров: " << best_embarked << endl;
    out << "Список идентификаторов несовершеннолетних (младше 18) пассажиров: ";
    for (int i = 0; i < id_of_young.size(); i++) {
        if (i == (id_of_young.size() - 1)) {
            out << id_of_young[i];
        }
        out << id_of_young[i] << ", ";

    }




}

int main()
{
    setlocale(LC_ALL, "Russian");
    vector<passanger> storage;
    storage = Read();
    Analysis(storage);
}
```
В результате получаем файл со следующими данными: [Файл](https://github.com/Leonid0208/CPP/blob/master/%D0%9B%D0%B0%D0%B1%D0%BE%D1%80%D0%B0%D1%82%D0%BE%D1%80%D0%BD%D1%8B%D0%B5%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D1%8B/%D0%9B%D0%B0%D0%B1%D0%BE%D1%80%D0%B0%D1%82%D0%BE%D1%80%D0%BD%D0%B0%D1%8F%20%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D0%B0%20%E2%84%965/Laba5/results.txt "Файл")
| Характеристика | Результат |
|---|---|
| Общее число выживших | 342 |
|Число выживших из 1 класса| 136 |
| Число выживших из 2 класса | 87 |
| Число выживших из 3 класса | 119 |
| Количество выживших женщин | 233 |
| Количество выживших мужчин | 109 |
| Средний возраст пассажира/женский/мужской | 29/28/31 |
| Штат, в котором село больше всего пассажиров | S |
| Список идентификаторов несовершеннолетних (младше 18) пассажиров | 8, 10, 11, 15, 17, 23, 25, 40, 44, 51, 59, 60, 64, 69, 72, 85, 87, 112, 115, 120, 126, 139, 148, 157, 164, 165, 166, 172, 173, 183, 184, 185, 194, 206, 209, 221, 234, 238, 262, 267, 279, 283, 298, 308, 330, 334, 341, 349, 353, 375, 382, 387, 390, 408, 420, 434, 436, 446, 447, 449, 480, 481, 490, 501, 505, 531, 533, 536, 542, 543, 550, 551, 575, 619, 635, 643, 684, 687, 690, 692, 721, 722, 732, 747, 751, 752, 765, 778, 781, 782, 788, 789, 792, 803, 814, 820, 825, 828, 831, 842, 845, 851, 853, 854, 870, 876


#### Вывод: попрбовал обработать csv формат в C++, поработал с файлами и структурами.
