// SNAKE GAME 

// functional requirements 

// 1) snake moves on board 2)user controls direction 3)snake eats food 4)snake grows after eating 5)score increases 6)game over if snake hits wall 7)game over if snake hits itself 8)restart game 

// Non functional requirements 

// system should be fast and smooth 1)movement should be fast 2)collision detection correct 3)No lag 4)correct score 5)real-time response 

// Database choice 

// for snake game no database is needed 

// if online board (SQL or firebase)

// to interviewer 

// --> Main classes 1)game 2)snake 3)food 4)board 

// board will store grid , snake will store body , game will control movement and collision 

// when snake eats : 1)grow , increase score

// snake body can be stored in queue or deque


// Entities ==> point(x,y) , snake , food , game 


#include <iostream>
#include <deque>
#include <cstdlib>
using namespace std;

// position class
class Point {
public:
    int x;
    int y;

    Point(){
        x=0;
        y=0;
    }

    Point(int a,int b){
        x=a;
        y=b;
    }
};


// snake class
class Snake {
public:
    deque<Point> body;     // snake body
    string direction;      // current direction

    Snake(){
        body.push_back(Point(5,5)); // initial position
        direction="RIGHT";
    }

    // change direction
    void changeDirection(string d){
        direction=d;
    }

    // move snake
    Point getNewHead(){
        Point head = body.front();

        if(direction=="UP") head.x--;
        else if(direction=="DOWN") head.x++;
        else if(direction=="LEFT") head.y--;
        else if(direction=="RIGHT") head.y++;

        return head;
    }

    void move(Point newHead, bool grow){
        body.push_front(newHead); // add new head

        if(!grow){
            body.pop_back(); // remove tail
        }
    }

    // check self collision
    bool checkSelfCollision(Point head){
        for(auto &p : body){
            if(p.x==head.x && p.y==head.y)
                return true;
        }
        return false;
    }
};

// food class
class Food {
public:
    Point pos;

    Food(){
        generate();
    }

    void generate(){
        pos.x = rand()%10;
        pos.y = rand()%10;
    }
};

// game class
class Game {
public:
    int width=10;
    int height=10;
    Snake snake;
    Food food;
    bool gameOver=false;
    int score=0;

    void update(){

        Point newHead = snake.getNewHead();

        // wall collision
        if(newHead.x<0 || newHead.y<0 || newHead.x>=height || newHead.y>=width){
            gameOver=true;
            cout<<"Hit wall. Game Over\n";
            return;
        }

        // self collision
        if(snake.checkSelfCollision(newHead)){
            gameOver=true;
            cout<<"Hit itself. Game Over\n";
            return;
        }

        bool grow=false;

        // food eaten
        if(newHead.x==food.pos.x && newHead.y==food.pos.y){
            grow=true;
            score+=10;
            cout<<"Food eaten. Score: "<<score<<endl;
            food.generate();
        }

        snake.move(newHead,grow);
    }
};

int main(){

    Game game;

    while(!game.gameOver){
        game.update();
    }

    return 0;
}
