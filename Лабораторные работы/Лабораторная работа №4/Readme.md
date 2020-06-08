МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>

### Отчёт по лабораторной работе № 4<br/> по дисциплине "Программирование"
<br/>

студента 1 курса группы 191(2)  
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

#### Цель: Закрепить навыки работы с перечислениями. Закрепить навыки работы со структурами. Освоить методы составления многофайловых программ.

Напишем программу для выполнения поставленной задачи в трёх файлах:

Заголовочный файл *Header.h*

```c++
using namespace std;

enum Status {
    PLAY,            // Игра продолжается
    USER_WIN,        // Игрок победил
    BOT_WIN,         // Бот победил
    NOT_WIN          // Ничья. Победителя нет, но и на поле нет свободной ячейки
};
struct Game {
    char bord[3][3];  // Игровое поле
    bool isUserTurn;  // Чей ход. Если пользователя, то isUserTurn = true
    char userChar;    // Символ которым играет пользователь
    char botChar;     // Символ которым играет бот
    Status status;
};

Game initGame(char userChar);

void updateDisplay(const Game game);

void botTurn(Game* game);

void userTurn(Game* game);

bool updateGame(Game* game);
```
Вспомогательный файл *Source.cpp*
```c++
#include "Header.h"
#include <iostream>


Game initGame(char UserChar) {
    Game game;
    game.userChar = UserChar;
    if (game.userChar == 'X') {
        game.botChar = '0';
        game.isUserTurn = false;
    }
    else {
        game.botChar = 'X';
        game.isUserTurn = true;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            game.bord[i][j] = ' ';
        }
    }

    game.status = PLAY;
    updateDisplay(game);
    return game;
};

void updateDisplay(const Game game) {
    system("CLS");
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " | ";
        for (int j = 0; j < 3; j++) {
            cout << " " << game.bord[i][j] << " | ";
        }
        cout << '\n';
    }
}
    

void botTurn(Game* game) {
    int counter = 0;
    for (int i = 0; i < 3; i++) {       // если бот ходит первый
        for (int j = 0; j < 3; j++) {
            if (game->bord[i][j] != ' ')
                counter += 1;
        }
    }
    if (counter == 0) {
        game->bord[1][1] = game->botChar;
        return;
    }

    for (int i = 0; i < 3; i++) {       // проверяем столбцы
        counter = 0;
        for (int j = 0; j < 3; j++) {
            if (game->bord[i][j] == game->botChar)
                counter += 1;
            else if (game->bord[i][j] == game->userChar)
                counter -= 1;
        }
        if (counter == 1) {
            for (int k = 0; k < 3; k++) {
                if (game->bord[i][k] == ' ') {
                    game->bord[i][k] = game->botChar;
                    return;
                }
            }
        }
        else if (counter == 2) {
            for (int k = 0; k < 3; k++) {
                if (game->bord[i][k] == ' ') {
                    game->bord[i][k] = game->botChar;
                    return;
                }
            }
        }
    }

    for (int j = 0; j < 3; j++) {       // проверяем строки
        counter = 0;
        for (int i = 0; i < 3; i++) {
            if (game->bord[i][j] == game->botChar)
                counter += 1;
            else if (game->bord[i][j] == game->userChar)
                counter -= 1;
        }
        if (counter == 1) {
            for (int k = 0; k < 3; k++) {
                if (game->bord[k][j] == ' ') {
                    game->bord[k][j] = game->botChar;
                    return;
                }
            }
        }
        else if (counter == 2) {
            for (int k = 0; k < 3; k++) {
                if (game->bord[k][j] == ' ') {
                    game->bord[k][j] = game->botChar;
                    return;
                }
            }
        }
    }

    counter = 0;
    for (int i = 0; i < 3; i++) {       // основная диагональ
        if (game->bord[i][i] == ' ') {
            counter += 1;
        }
        else if (game->bord[i][i] == game->userChar) {
            counter -= 1;
        }
    }
    if (counter == 2) {
        for (int i = 0; i < 3; i++) {
            if (game->bord[i][i] == ' ') {
                game->bord[i][i] = game->botChar;
                return;
            }
        }
    }

    counter = 0;
    for (int i = 0; i < 3; i++) {       // побочная диагональ
        if (game->bord[i][2-i] == ' ') {
            counter += 1;
        }
        else if (game->bord[i][2-i] == game->userChar) {
            counter -= 1;
        }
    }
    if (counter == 2) {
        for (int i = 0; i < 3; i++) {
            if (game->bord[i][2-i] == ' ') {
                game->bord[i][2-i] = game->botChar;
                return;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game->bord[i][j] == ' ') {
                game->bord[i][j] = game->botChar;
                return;
            }
        }
    }


}


void userTurn(Game* game) {
    int x, y;
    cout << "Your turn: ";
    cin >> x >> y;
    while (x > 3 || y > 3 || x < 1 || y < 1 || game->bord[x - 1][y - 1] != ' ') {
        cout << "Error" << endl << "Try one more: ";
        cin >> x >> y;
    }
    game->bord[x - 1][y - 1] = game->userChar;
};


bool updateGame(Game* game) {
    int counter = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game->bord[i][j] == ' ') {
                counter++;
            }
        }
        if ((game->bord[i][0] == game->bord[i][1] && game->bord[i][1] == game->bord[i][2]) && game->bord[i][0] != ' ') {
            if (game->bord[i][0] == game->botChar) {
                game->status = BOT_WIN;
            }
            else {
                game->status = USER_WIN;
            }
            return true;
        }
        else if ((game->bord[0][i] == game->bord[1][i] && game->bord[1][i] == game->bord[2][i]) && game->bord[0][i] != ' ') {
            if (game->bord[0][i] == game->botChar) {
                game->status = BOT_WIN;
            }
            else {
                game->status = USER_WIN;
            }
            return true;
        }
        else if ((game->bord[0][0] == game->bord[1][1] && game->bord[1][1] == game->bord[2][2]) && game->bord[0][0] != ' ') {
            if (game->bord[0][0] == game->botChar) {
                game->status = BOT_WIN;
            }
            else {
                game->status = USER_WIN;
            }
            return true;
        }
        else if ((game->bord[0][2] == game->bord[1][1] && game->bord[1][1] == game->bord[2][0]) && game->bord[0][2] != ' ') {
            if (game->bord[0][2] == game->botChar) {
                game->status = BOT_WIN;
            }
            else {
                game->status = USER_WIN;
            }
            return true;
        }

    }
    if (counter == 0) {
        game->status = NOT_WIN;
        return true;
    }
    else {
        game->isUserTurn = !game->isUserTurn;
        return false;
    }
    return true;
};
```
Файл с основной программой *Lab4.cpp*
```c++
#include "Header.h"
#include <iostream>
#include <time.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    char choose;
    do {
        cout << "Выберите Х или 0: ";
        cin >> choose;
    } while (choose != 'X' && choose != '0');

    Game game = initGame(choose);
    while (!updateGame(&game))
    {
        if (game.isUserTurn)
            userTurn(&game);
        else
            botTurn(&game);
        updateDisplay(game);
    }
    if (game.status == USER_WIN)
        cout << "Вы победили!";
    else if (game.status == BOT_WIN)
        cout << "Вы проиграли!";
    else
        cout << "Ничья!";
}
```

#### Вывод: научился строить многофайловые программы в C++.
