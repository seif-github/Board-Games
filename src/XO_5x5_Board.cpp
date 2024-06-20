#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include"BoardGame.h"

using namespace std;

XO_5x5_Board :: XO_5x5_Board() {
    n_rows = n_cols = 5;
    board = new char* [n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool XO_5x5_Board :: update_board(int x, int y, char mark) {
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

void XO_5x5_Board :: display_board() {
    for (int i = 0; i < n_rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < n_cols; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n-----------------------------------------------";
    }
    cout << endl;
}

bool XO_5x5_Board :: is_winner() {
    int counter_x=0 , counter_o = 0;
    if(n_moves == 24){
        // check vertically
        for(int i=0; i<3; i++){
            for (int j = 0; j<5; j++){
                bool checker_v = board[i][j] & board[i+1][j] & board[i+2][j];
                if(checker_v){
                    if((board[i][j] == board[i+1][j] && board[i+1][j] == board[i+2][j])){
                        if(board[i][j] == 'X'){
                            counter_x++;
                        }
                        if(board[i][j] == 'O'){
                            counter_o++;
                        }
                    }
                }
            }
        }

        // check horizontally
        for(int i=0; i<5; i++){
            for (int j = 0; j<3; j++){
                bool checker_h = board[i][j] & board[i][j+1] & board[i][j+2];
                if(checker_h){
                    if((board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2])){
                        if(board[i][j] == 'X'){
                            counter_x++;
                        }
                        if(board[i][j] == 'O'){
                            counter_o++;
                        }
                    }
                }
            }
        }

        //check diagonally right
        for(int i=0; i<3; i++){
            for (int j = 2; j<5; j++){
                bool checker_dr = board[i][j] & board[i+1][j-1] & board[i+2][j-2];
                if(checker_dr){
                    if(board[i][j] == board[i+1][j-1] && board[i+1][j-1] == board[i+2][j-2]){
                        if(board[i][j] == 'X'){
                            counter_x++;
                        }
                        if(board[i][j] == 'O'){
                            counter_o++;
                        }
                    }
                }
            }
        }

        // check diagonally left
        for(int i=0; i<3; i++){
            for (int j = 2; j >= 0; j--){
                bool checker_dl = board[i][j] & board[i+1][j+1] & board[i+2][j+2];
                if(checker_dl){
                    if(board[i][j] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j+2]){
                        if(board[i][j] == 'X'){
                            counter_x++;
                        }
                        if(board[i][j] == 'O'){
                            counter_o++;
                        }
                    }
                }
            }
        }

        if(counter_x > counter_o){
            cout << "X wins" << endl;
            return false;
        }
        else if(counter_o > counter_x){
            cout << "O wins" << endl;
            return false;
        }
        else{ // counter_o == counter_x
            cout << "Draw!" << endl;
            return false;
        }
    }
    else {// n_moves != 24
        return false;
    }
}

bool XO_5x5_Board :: is_draw() {
    return false;
}
bool XO_5x5_Board :: game_is_over() {
    return n_moves >= 24;
}
