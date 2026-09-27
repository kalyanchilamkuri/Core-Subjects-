
// Design a chess system 

// Functional requirements 

// --> okay ... so what i thought was , chess game should allow: 1)two players can play 2)chess biaard (8*8) 3)Different pieces (king , queen , rook) 4)valid moves only 5)alternate turns 6)Detect check and checkmate 7)restart

// Non-Functional requirements

// --> system should be simple and correct --> 1)moves must be valid 2)no wrong move allowed 3)Fast response 4)Game state should be correct 

// Board will be 8*8 grid 

// each pirce like king , queen will have its own move function 

// Game will control :  

// 1) player turn 2)move validation 3)check/check mate 

// if valid move -> update board else reject move 





























#include <iostream>
#include <vector>
using namespace std;

// enum for piece color
enum Color {
    WHITE,
    BLACK
};

// base class for chess piece
class Piece {
public:
    Color color;   // piece color

    Piece(Color c){
        color = c;
    }

    // virtual function for valid move
    virtual bool isValidMove(int sx,int sy,int dx,int dy){
        return false;
    }
};

// King class
class King : public Piece {
public:
    King(Color c) : Piece(c) {}

    // king moves 1 step
    bool isValidMove(int sx,int sy,int dx,int dy){
        if(abs(dx-sx)<=1 && abs(dy-sy)<=1)
            return true;
        return false;
    }
};

// Rook class
class Rook : public Piece {
public:
    Rook(Color c) : Piece(c) {}

    bool isValidMove(int sx,int sy,int dx,int dy){
        if(sx==dx || sy==dy)
            return true;
        return false;
    }
};

// Board class
class Board {
public:
    Piece* grid[8][8];   // 8x8 board

    Board(){
        // initialize empty
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                grid[i][j] = NULL;
            }
        }

        // place kings
        grid[0][4] = new King(BLACK);
        grid[7][4] = new King(WHITE);

        // place rooks
        grid[0][0] = new Rook(BLACK);
        grid[7][0] = new Rook(WHITE);
    }

    // move piece
    bool movePiece(int sx,int sy,int dx,int dy){
        Piece* p = grid[sx][sy];

        if(p==NULL){
            cout<<"No piece\n";
            return false;
        }

        // check valid move
        if(p->isValidMove(sx,sy,dx,dy)){
            grid[dx][dy] = p;
            grid[sx][sy] = NULL;
            return true;
        }

        cout<<"Invalid move\n";
        return false;
    }
};

// Player class
class Player {
public:
    string name;
    Color color;

    Player(string n, Color c){
        name = n;
        color = c;
    }
};

// Game class
class Game {
public:
    Board board;
    Player p1;
    Player p2;
    bool whiteTurn;

    Game(Player a, Player b) : p1(a), p2(b){
        whiteTurn = true;
    }

    // play move
    void makeMove(int sx,int sy,int dx,int dy){
        if(board.movePiece(sx,sy,dx,dy)){
            whiteTurn = !whiteTurn;
            cout<<"Move successful\n";
        }else{
            cout<<"Try again\n";
        }
    }
};

int main(){

    Player p1("Kalyan",WHITE);
    Player p2("Rahul",BLACK);

    Game game(p1,p2);

    // move white rook
    game.makeMove(7,0,5,0);

    return 0;
}
