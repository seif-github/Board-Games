#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include"BoardGame.h"

using namespace std;

pyramid_AI_Player :: pyramid_AI_Player(char symbol, PYRAMID_XO_Board* board) : Player(symbol), board(board){
    this->name = "AI Player";
    cout << "My names is " << name << endl;
}

void pyramid_AI_Player :: get_move (int& x, int& y){
    board->AI(x,y, true, false);
}
