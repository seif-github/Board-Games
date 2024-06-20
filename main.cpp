#include <iostream>
#include"BoardGame.h"

using namespace std;

int main()
{
    Player* players[2];
    cout << "Welcome to FCAI X-O Game. :)\n";

    cout << "Please Choose which game you want to play." << endl;
    cout << "1- 3 x 3 Tic Tac Toe. (Professor Version)" << endl;
    cout << "2- Pyramic Tic-Tac-Toe." << endl;
    cout << "3- Four-in-a-row." << endl;
    cout << "4- 5 x 5 Tic Tac Toe." << endl;

    int menu;
    cin >> menu;
    if (menu == 1){
        players[0] = new Player(1, 'o');
        cout << "Press 1 if you want to play with computer: ";
        int choice;
        cin >> choice;
        if (choice != 1)
            players[1] = new Player(2, 'x');
        else // with computer
            //Player pointer points to child
            players[1] = new RandomPlayer('x', 3);

        GameManager x_o_game(new X_O_Board(), players);
        x_o_game.run();
    }
    else if (menu == 2){
        players[0] = new pyramidPlayer(1, 'o');
        cout << "Press 1 if you want to play with computer: ";
        int choice;
        cin >> choice;
        if (choice != 1)
            players[1] = new pyramidPlayer(2, 'x');
        else // with computer
            //Player pointer points to child
            players[1] = new pyramidRandomPlayer('x', 3, 5);

        GameManager x_o_game(new PYRAMID_XO_Board(), players);
        x_o_game.run();
    }
    else if (menu == 3){
        players[0] = new four_in_row_Player(1, 'o');
        cout << "Press 1 if you want to play with computer: ";
        int choice;
        cin >> choice;
        if (choice != 1)
            players[1] = new four_in_row_Player(2, 'x');
        else // with computer
            //Player pointer points to child
            players[1] = new four_in_row_RandomPlayer('x', 5);

        GameManager x_o_game(new four_in_row_Board(), players);
        x_o_game.run();
    }
    else if (menu == 4){
        players[0] = new XO_5x5_Player(1, 'o');
        cout << "Press 1 if you want to play with computer: ";
        int choice;
        cin >> choice;
        if (choice != 1)
            players[1] = new XO_5x5_Player(2, 'x');
        else // with computer
            //Player pointer points to child
            players[1] = new RandomPlayer('x', 5);

        GameManager x_o_game(new XO_5x5_Board(), players);
        x_o_game.run();
    }


    system("pause");
}
