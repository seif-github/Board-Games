#ifndef BOARDGAME_H
#define BOARDGAME_H

using namespace std;

class Board {
protected:
   int n_rows, n_cols;
   char** board;
   int  n_moves = 0;

public:
   // Return true  if move is valid and put it on board
   // within board boundaries in empty cell
   // Return false otherwise
   virtual bool update_board (int x, int y, char symbol) = 0;
   // Returns true if there is any winner
   // either X or O
   // Written in a complex way. DO NOT DO LIKE THIS.
   virtual bool is_winner() = 0;
   // Return true if all moves are done and no winner
   virtual bool is_draw() = 0;
   // Display the board and the pieces on it
   virtual void display_board() = 0;
   // Return true if game is over
   virtual bool game_is_over() = 0;

};

///////////////////////////////////////////
// This class represents a 3 x 3 board
// used in X_O game
class X_O_Board:public Board {
public:
   X_O_Board ();
   bool update_board (int x, int y, char mark);
   void display_board();
   bool is_winner();
   bool is_draw();
   bool game_is_over();
};

// This class represents a pyramid board
class PYRAMID_XO_Board :public Board {
public:
    PYRAMID_XO_Board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    int what_about_now();
    int AI(int& x ,int& y, bool first_time , bool isMax);
};
// this class represents four in a row board
class four_in_row_Board :public Board {
public:
    four_in_row_Board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};

// this class represents 5*5 board
class XO_5x5_Board :public Board {
public:
    XO_5x5_Board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();

};

///////////////////////////////////////////
// This class represents a player who has
// a name and a symbol to put on board
class Player {
    protected:
        string name;
        char symbol;
    public:
        // Two constructors to initiate player
        // Give player a symbol to use in playing
        // It can be X or O or others
        // Optionally, you can give him ID or order
        // Like Player 1 and Player 2
        Player (char symbol); // Needed for computer players
        Player (int order, char symbol);
        // Get desired move: x y (each between 0 and 2)
        // Virtual (can change for other player types)
        virtual void get_move(int& x, int& y);
        // Give player info as a string
        string to_string();
        // Get symbol used by player
        char get_symbol();
};
///////////////////////////////////////////
class pyramid_AI_Player : public Player{
private:
    PYRAMID_XO_Board* board;
public:
    pyramid_AI_Player(char symbol, PYRAMID_XO_Board* board);
    void get_move (int& x, int& y);
};

///////////////////////////////////////////
// This class represents a random computer player
// that generates random positions x y (0 to 2)
// If invalid, game manager asks to regenerate
class RandomPlayer: public Player {
    protected:
        int dimension;
    public:
        // Take a symbol and pass it to parent
        RandomPlayer (char symbol, int dimension);
        // Generate a random move
        void get_move(int& x, int& y);
};

///////////////////////////////////////////

class pyramidPlayer :public Player {

public:
    pyramidPlayer(int order, char symbol);
    // Get desired move x y on pyramid
    void get_move(int& x, int& y);
};

class pyramidRandomPlayer : public Player {
protected:
    int dimensionX;
    int dimensionY;
public:
    // Take a symbol and pass it to parent
    pyramidRandomPlayer(char symbol, int dimensionX, int dimensionY);
    // Generate a random move
    void get_move(int& x, int& y);
};
///////////////////////////////////////////
class four_in_row_Player : public Player {
public:
    // Take a symbol and pass it to parent
    four_in_row_Player(int order, char symbol);
    // Get desired move: y (between 0 and 6)
    void get_move(int& x, int& y);
};

class four_in_row_RandomPlayer : public Player {
protected:
    int dimensionY;
public:
    // Take a symbol and pass it to parent
    four_in_row_RandomPlayer(char symbol, int dimensionY);
    // Generate a random move
    void get_move(int& x, int& y);
};
///////////////////////////////////////////
class XO_5x5_Player :public Player {

public:
    XO_5x5_Player(int order, char symbol);
    // Get desired move x y on pyramid
    void get_move(int& x, int& y);
};

// XO_5x5_RandomPlayer same as Random Player Class but with dimension = 5



///////////////////////////////////////////
class GameManager {
    private:
        Board* boardPtr;
        Player* players[2];
    public:
        GameManager(Board*, Player* playerPtr[2]);
        void run();
        // This method creates board and players
        // It displays board
        // While True
        //   For each player
        //      It takes a valid move as x, y pair (between 0 - 2)
        //      It updates board and displays on it
        //      If winner, declare so and end
        //      If draw, declare so and end

};

#endif // BOARDGAME_H
