#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include"BoardGame.h"

using namespace std;

four_in_row_Board :: four_in_row_Board() {
    n_rows = 6;
    n_cols = 7;
    board = new char* [n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool four_in_row_Board :: update_board(int x, int y, char mark) {
    // Only update if move is valid
    // this while loop to put the move on the top of the column
    while (x) {
        if (board[x][y] != 0) {
            x--;
        }
        else break;
    }
    if (!(x < 0 || x > 5 || y < 0 || y > 6) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

void four_in_row_Board :: display_board() {
    for (int i = 0; i < n_rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < n_cols; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n-----------------------------------------------------------------";
    }
    cout << endl;
}

bool four_in_row_Board :: is_winner() {
    //check all horizontally
    for(int i = 0; i < 6; i++){
        for (int j = 0; j < 4; ++j) {
            bool checker_h = board[i][j] & board[i][j+1] & board[i][j+2] & board[i][j+3];
            if(checker_h){
                if(board[i][j] ==  board[i][j+1] &&  board[i][j+1] == board[i][j+2] &&  board[i][j+2] == board[i][j+3]){
                    return true;
                }
            }
        }
    }
    //check all vertically
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 7; ++j) {
            bool checker_v = board[i][j] & board[i+1][j] & board[i+2][j] & board[i+3][j];
            if(checker_v){
                if(board[i][j] == board[i+1][j] && board[i+1][j] == board[i+2][j] && board[i+2][j] == board[i+3][j]){
                    return true;
                }
            }
        }
    }
    //check all right diagonally
    for(int i=0; i<3; i++){
        for (int j = 3; j<7; j++){
            bool checker_dr = board[i][j] & board[i+1][j-1] & board[i+2][j-2] & board[i+3][j-3];
            if(checker_dr){
                if(board[i][j] == board[i+1][j-1] && board[i+1][j-1] == board[i+2][j-2] && board[i+2][j-2] == board[i+3][j-3]){
                    return true;
                }
            }
        }
    }
    //check all left diagonally
    for(int i=0; i<3; i++){
        for (int j = 2; j >= 0; j--){
            bool checker_dl = board[i][j] & board[i+1][j+1] & board[i+2][j+2] & board[i+3][j+3];
            if(checker_dl){
                if(board[i][j] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j+2] && board[i+2][j+2] == board[i+3][j+3]){
                    return true;
                }
            }
        }
    }

    return false;
}

bool four_in_row_Board :: is_draw() {
    return (n_moves == 42 && !is_winner());
}
bool four_in_row_Board :: game_is_over() {
    return n_moves >= 42;
}
