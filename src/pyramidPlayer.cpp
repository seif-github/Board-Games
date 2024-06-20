#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include"BoardGame.h"

using namespace std;

pyramidPlayer :: pyramidPlayer(int order, char symbol) :Player(order, symbol) {}


// Get desired move x y on pyramid
void pyramidPlayer :: get_move(int& x, int& y) {
    cout << "\nPlease enter your move in this pyramid : ";
    cin >> x >> y;
}


