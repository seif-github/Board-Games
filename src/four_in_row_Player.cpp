#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include"BoardGame.h"

using namespace std;

four_in_row_Player :: four_in_row_Player(int order, char symbol) :Player(order, symbol) {}

void four_in_row_Player :: get_move(int& x, int& y) {
    cout << "\nPlease enter your move column (0 to 6) : ";
    cin >> y;
    x = 5;
}
