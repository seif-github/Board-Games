#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include"BoardGame.h"

using namespace std;

PYRAMID_XO_Board :: PYRAMID_XO_Board() {
    n_rows = 3;
    n_cols = 5;
    board = new char* [n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool PYRAMID_XO_Board :: update_board(int x, int y, char mark) {
    // Only update if move is valid
    if (((x == 0 && y == 2) || (x == 1 && y == 1) || (x == 1 && y == 2) || (x == 1 && y == 3) || (x == 2 && y == 0) || (x == 2 && y == 1) || (x == 2 && y == 2) || (x == 2 && y == 3) || (x == 2 && y == 4)) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

void PYRAMID_XO_Board :: display_board() {
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            if ((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 0 && j == 3) || (i == 0 && j == 4) || (i == 1 && j == 0) || (i == 1 && j == 4)) {
                cout << "         ";
                continue;
            }
            if ((i == 0 && j == 2) || (i == 1 && j == 1) || (i == 2 && j == 0)) {
                cout << "|(" << i << "," << j << ")";
                cout << setw(2) << board[i][j] << " |";
            }
            else {
                cout << "(" << i << "," << j << ")";
                cout << setw(2) << board[i][j] << " |";
            }
        }
        if (i == 0) cout << "\n                  ----------                   \n";
        if (i == 1) cout << "\n         ----------------------------          \n";
        if (i == 2) cout << "\n---------------------------------------------- \n";
    }
    cout << endl;
}

bool PYRAMID_XO_Board :: is_winner() {
    /*
     making array of integer to the probabilities of winning
     every move will check all 7 probabilities to win (4 horizontal, 2 diagonal, 1 vertical)
     by ANDing every possibility if it has three strike of Xs and Os (gives number) or not (gives zero)
     then if it is not zero then check if the strike is the same character X or O or not.
     */
    int horizontal_win[4];
    int vertical_win[1];
    int diagonal_win[2];

    horizontal_win[0] = ((int)board[1][1]) & ((int)board[1][2]) & ((int)board[1][3]);
    horizontal_win[1] = ((int)board[2][0]) & ((int)board[2][1]) & ((int)board[2][2]);
    horizontal_win[2] = ((int)board[2][1]) & ((int)board[2][2]) & ((int)board[2][3]);
    horizontal_win[3] = ((int)board[2][2]) & ((int)board[2][3]) & ((int)board[2][4]);

    vertical_win[0] = ((int)board[0][2]) & ((int)board[1][2]) & ((int)board[2][2]);

    diagonal_win[0] = ((int)board[0][2]) & ((int)board[1][3]) & ((int)board[2][4]);
    diagonal_win[1] = ((int)board[0][2]) & ((int)board[1][1]) & ((int)board[2][0]);

    if (horizontal_win[0]) {
        if ((((int)board[1][1]) == ((int)board[1][2])) && (((int)board[1][2]) == ((int)board[1][3]))) {
            return true;
        }
    }
    if (horizontal_win[1]) {
        if ((((int)board[2][0]) == ((int)board[2][1])) && (((int)board[2][1]) == ((int)board[2][2]))) {
            return true;
        }
    }
    if (horizontal_win[2]) {
        if ((((int)board[2][1]) == ((int)board[2][2])) && (((int)board[2][2]) == ((int)board[2][3]))) {
            return true;
        }
    }
    if (horizontal_win[3]) {
        if ((((int)board[2][2]) == ((int)board[2][3])) && (((int)board[2][3]) == ((int)board[2][4]))) {
            return true;
        }
    }

    if (vertical_win[0]) {
        if ((((int)board[0][2]) == ((int)board[1][2])) && (((int)board[1][2]) == ((int)board[2][2]))) {
            return true;
        }
    }

    if (diagonal_win[0]) {
        if ((((int)board[0][2]) == ((int)board[1][3])) && (((int)board[1][3]) == ((int)board[2][4]))) {
            return true;
        }
    }
    if (diagonal_win[1]) {
        if ((((int)board[0][2]) == ((int)board[1][1])) && (((int)board[1][1]) == ((int)board[2][0]))) {
            return true;
        }
    }
    return false;
}

bool PYRAMID_XO_Board :: is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool PYRAMID_XO_Board :: game_is_over() {
    return n_moves >= 9;
}

// return 100 -> X wins
// return -100 -> O wins
// return 0 -> Draw
// return -1 -> game didn't finish
int PYRAMID_XO_Board :: what_about_now(){
    int horizontal_win[4];
    int vertical_win[1];
    int diagonal_win[2];

    horizontal_win[0] = ((int)board[1][1]) & ((int)board[1][2]) & ((int)board[1][3]);
    horizontal_win[1] = ((int)board[2][0]) & ((int)board[2][1]) & ((int)board[2][2]);
    horizontal_win[2] = ((int)board[2][1]) & ((int)board[2][2]) & ((int)board[2][3]);
    horizontal_win[3] = ((int)board[2][2]) & ((int)board[2][3]) & ((int)board[2][4]);

    vertical_win[0] = ((int)board[0][2]) & ((int)board[1][2]) & ((int)board[2][2]);

    diagonal_win[0] = ((int)board[0][2]) & ((int)board[1][3]) & ((int)board[2][4]);
    diagonal_win[1] = ((int)board[0][2]) & ((int)board[1][1]) & ((int)board[2][0]);

    if (horizontal_win[0]) {
        if ((((int)board[1][1]) == ((int)board[1][2])) && (((int)board[1][2]) == ((int)board[1][3]))) {
            if(board[1][1] == 'X') return 100;
            if(board[1][1] == 'O') return -100;
        }
    }
    if (horizontal_win[1]) {
        if ((((int)board[2][0]) == ((int)board[2][1])) && (((int)board[2][1]) == ((int)board[2][2]))) {
            if(board[2][0] == 'X') return 100;
            if(board[2][0] == 'O') return -100;
        }
    }
    if (horizontal_win[2]) {
        if ((((int)board[2][1]) == ((int)board[2][2])) && (((int)board[2][2]) == ((int)board[2][3]))) {
            if(board[2][1] == 'X') return 100;
            if(board[2][1] == 'O') return -100;
        }
    }
    if (horizontal_win[3]) {
        if ((((int)board[2][2]) == ((int)board[2][3])) && (((int)board[2][3]) == ((int)board[2][4]))) {
            if(board[2][2] == 'X') return 100;
            if(board[2][2] == 'O') return -100;
        }
    }

    if (vertical_win[0]) {
        if ((((int)board[0][2]) == ((int)board[1][2])) && (((int)board[1][2]) == ((int)board[2][2]))) {
            if(board[0][2] == 'X') return 100;
            if(board[0][2] == 'O') return -100;
        }
    }

    if (diagonal_win[0]) {
        if ((((int)board[0][2]) == ((int)board[1][3])) && (((int)board[1][3]) == ((int)board[2][4]))) {
            if(board[0][2] == 'X') return 100;
            if(board[0][2] == 'O') return -100;
        }
    }
    if (diagonal_win[1]) {
        if ((((int)board[0][2]) == ((int)board[1][1])) && (((int)board[1][1]) == ((int)board[2][0]))) {
            if(board[0][2] == 'X') return 100;
            if(board[0][2] == 'O') return -100;
        }
    }
    bool isDraw = true;
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            if ((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 0 && j == 3) || (i == 0 && j == 4) || (i == 1 && j == 0) || (i == 1 && j == 4)) {
                continue;
            }
            if(board[i][j] == 0){
                isDraw = false;
            }
        }
    }
    if (isDraw){
        return 0;
    }
    return -1;
}

int PYRAMID_XO_Board :: AI(int& x ,int& y, bool first_time , bool isMax){
    int Status = what_about_now();
    int maxi = -1000, mini = 1000;
    int best_i, best_j;
    if (Status != -1){
        return Status;
    }
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            if ((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 0 && j == 3) || (i == 0 && j == 4) || (i == 1 && j == 0) || (i == 1 && j == 4)) {
                continue;
            }
            if(board[i][j] == 0){
                if(isMax){
                    board[i][j] = 'X';
                    int score = AI(x,y,false, false);
                    board[i][j] = 0;
                    if(score >= maxi){
                        maxi = score;
                        best_i = i;
                        best_j = j;
                    }

                }
                else{
                    board[i][j] = 'O';
                    int score = AI(x,y,false, true);
                    board[i][j] = 0;
                    if(score <= mini){
                        mini = score;
                        best_i = i;
                        best_j = j;
                    }

                }
            }
        }
    }
    if(first_time){
        x = best_i;
        y = best_j;
    }
    return (isMax ? maxi : mini);
}
