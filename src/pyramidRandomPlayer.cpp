#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include"BoardGame.h"

using namespace std;

pyramidRandomPlayer :: pyramidRandomPlayer(char symbol, int dimensionX, int dimensionY) :Player(symbol){
    this->dimensionX = dimensionX;
    this->dimensionY = dimensionY;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

void pyramidRandomPlayer :: get_move(int& x, int& y) {
        x = (int)(rand() / (RAND_MAX + 1.0) * dimensionX);
        y = (int)(rand() / (RAND_MAX + 1.0) * dimensionY);
    }
