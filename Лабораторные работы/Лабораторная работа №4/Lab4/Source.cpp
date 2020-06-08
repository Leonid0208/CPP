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