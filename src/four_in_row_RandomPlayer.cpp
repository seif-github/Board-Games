#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include"BoardGame.h"

using namespace std;

four_in_row_RandomPlayer :: four_in_row_RandomPlayer(char symbol, int dimensionY) :Player(symbol){
    this->dimensionY = dimensionY;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}


void four_in_row_RandomPlayer :: get_move(int& x, int& y) {
    x = 5;
    y = (int)(rand() / (RAND_MAX + 1.0) * dimensionY);
}
