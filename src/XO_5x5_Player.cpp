#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include"BoardGame.h"

using namespace std;

XO_5x5_Player :: XO_5x5_Player(int order, char symbol) :Player(order, symbol) {}

void XO_5x5_Player :: get_move(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
}
