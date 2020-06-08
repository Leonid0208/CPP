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