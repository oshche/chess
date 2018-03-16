#ifndef FIGURE_H
#define FIGURE_H
#include <vector>
#include <iostream>
#include <square.h>
using namespace  std;
enum FigureType{
    PawnType,
    KnightType,
    BishopType,
    RookType,
    QueenType,
    KingType
};

enum ColorType{
    WhiteType,
    BlackType
};



class State{ //координаты фигуры на доске
public:
    int x;
    int y;
    State(int x,int y){
        this->x=x;
        this->y=y;
    }
    State(){}
};

class Square;
class Figure: public State{
public:
    State last_state;
    FigureType type;
    vector<State> future_states;
    ColorType color;

   Figure(FigureType type,ColorType color,int x, int y,Square my_board[8][8]): State(x,y){
     this->color=color;
     this->type=type;
     my_board[x][y].freedom =1;
     my_board[x][y].figure = this;

    }
    void future(Square board[8][8]){
        int x = this->x;
        int y = this->y;
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
        if (type == PawnType){
            if ( (board[x][y+2].freedom == 0 or board[x][y+2].figure->color !=this->color)
                 and y == 1)
                future_states.push_back(State(x,y+2));
            if ( (board[x][y+1].freedom == 0 or board[x][y+1].figure->color !=this->color)
                 and y<7)
                future_states.push_back(State(x,y+1));
            if ( (board[x+1][y+1].freedom != 0 or board[x+1][y+1].figure->color !=this->color)
                 and y<7 and x<7)
                future_states.push_back(State(x+1,y+1));
            if ( (board[x-1][y+1].freedom != 0 or  board[x-1][y+1].figure->color !=this->color)
                and y<7 and x>0)
                future_states.push_back(State(x-1,y+1));
       }
       else if (type == KnightType){
            if ( (board[x-1][y-2].freedom == 0 or board[x-1][y-2].figure->color !=this->color)
                 and x>0 and y>1)
                future_states.push_back(State(x-1,y-2));
            if ( (board[x+2][y+1].freedom == 0 or board[x+2][y+1].figure->color !=this->color)
                 and x<6 and y<7)
                future_states.push_back(State(x+2,y+1));
            if ( (board[x+1][y+2].freedom ==0 or board[x+1][y+2].figure->color != this->color)
                 and x<7 and y<6)
                future_states.push_back((State(x+1,y+2)));
            if ( (board[x+2][y-1].freedom == 0 or board[x+2][y-1].figure->color !=this->color)
                and x<6 and y>0)
                future_states.push_back((State(x+2,y-1)));
            if ( (board[x+2][y-2].freedom == 0 or board[x+2][y-2].figure->color !=this->color)
                and x<7 and y>1)
                future_states.push_back((State(x+1,y-2)));
            if ( (board[x-2][y+1].freedom == 0 or board[x-2][y+1].figure->color !=this->color)
                 and x>1 and y<7)
                future_states.push_back((State(x-2,y+1)));
            if ( (board[x-1][y+2].freedom == 0 or board[x-1][y+2].figure->color !=this->color)
                 and x>0 and y<6)
                future_states.push_back((State(x-1,y+2)));
            if ( (board[x-2][y-1].freedom == 0 or board[x-2][y-1].figure->color !=this->color)
                 and x>1 and y>0)
                future_states.push_back(State(x-2,y-1));
        }
        else if (type == BishopType){
            int x1=x;
            int y1=y;
            while(x1<7 and y1<7){
                if (board[x1+1][y1+1].freedom == 0){
                    future_states.push_back(State(x1+1,y1+1));
                    x1++;
                    y1++;
                }
                else if (board[x1+1][y1+1].figure->color != this->color){
                    future_states.push_back(State(x1+1,y1+1));
                    x1++;
                    y1++;
                    break;
                }
                else {
                    break;
                }
            }
            x1 = x;
            y1 = y;
            while(x1<7 and y1>0){
                if (board[x1+1][y1-1].freedom == 0){
                    future_states.push_back(State(x1+1,y1-1));
                    x1++;
                    y1--;
                }
                 else if (board[x1+1][y1-1].figure->color != this->color){
                    future_states.push_back(State(x1+1,y1-1));
                    x1++;
                    y1--;
                    break;
                }
                else{
                    break;
                }
            }
            x1=x;
            y1=y;
            while(x1>0 and y1<7){
                if (board[x1-1][y1+1].freedom == 0){
                    future_states.push_back(State(x1-1,y1+1));
                    x1--;
                    y1++;
                }
                 else if (board[x1-1][y1+1].figure->color != this->color){
                    future_states.push_back(State(x1-1,y1+1));
                    x1--;
                    y1++;
                    break;
                }
                else{
                    break;
                }
            }
            x1 = x;
            y1 = y;
            while(x1>0 and y1>0){
                if (board[x1-1][y1-1].freedom == 0){
                    future_states.push_back(State(x1-1,y1-1));
                    x1--;
                    y1--;
                }
                 else if (board[x1-1][y1-1].figure->color != this->color){
                    future_states.push_back(State(x1-1,y-1));
                    x1--;
                    y1--;
                    break;
                }
                else{
                    break;
                }
            }
        }
        else if (type == RookType){
            int x1=x;
            int y1=y;
            while(x1<7){
                if (board[x1+1][y1].freedom == 0){
                    future_states.push_back(State(x1+1,y1));
                    x1++;
                }
                else if (board[x1+1][y1].figure->color != this->color){
                    future_states.push_back(State(x1+1,y1));
                    x1++;
                    break;
                }
                else{
                    break;
                }
            }
            x1 = x;
            while(x1>0){
                if (board[x1-1][y1].freedom == 0){
                    future_states.push_back(State(x1-1,y1));
                    x1--;
                }
                 else if (board[x1-1][y1].figure->color != this->color){
                    future_states.push_back(State(x1-1,y1));
                    x1--;
                    break;
                }
                else{
                    break;
                }
            }
            x1=x;
            while(y1<7){
                if (board[x1][y1+1].freedom == 0){
                    future_states.push_back(State(x1,y1+1));
                    y1++;
                }
                 else if (board[x1][y1+1].figure->color != this->color){
                    future_states.push_back(State(x1,y1+1));
                    y1++;
                    break;
                }
                else{
                    break;
                }
            }
            y1 = y;
            while(y1>0){
                if (board[x1][y1-1].freedom == 0){
                    future_states.push_back(State(x1,y1-1));
                    y1--;
                }
                 else if (board[x1][y1-1].figure->color != this->color){
                    future_states.push_back(State(x1,y1-1));
                    y1--;
                    break;
                }
                else{
                    break;
                }
            }
        }
        else if (type == QueenType ){
            int x1=x;
            int y1=y;
            while(x1<7 and y1<7){
                if (board[x1+1][y1+1].freedom == 0){
                    future_states.push_back(State(x1+1,y1+1));
                    x1++;
                    y1++;
                }
                else if (board[x1+1][y1+1].figure->color != this->color){
                    future_states.push_back(State(x1+1,y1+1));
                    std::cout<<"hello "<<board[x1+1][y1+1].figure->x;
                    if (board[x1+1][y1+1].figure->color == BlackType){
                        cout<<"yes"<<endl;
                    }
                    x1++;
                    y1++;
                    break;
                }
                else{
                    break;
                }
            }
            x1 = x;
            y1 = y;
            while(x1<7 and y1>0){
                if (board[x1+1][y1-1].freedom == 0){
                    future_states.push_back(State(x1+1,y1-1));
                    x1++;
                    y1--;
                }
                 else if (board[x1+1][y1-1].figure->color != this->color){
                    future_states.push_back(State(x1+1,y1-1));
                    x1++;
                    y1--;
                    break;
                }
                else{
                    break;
                }
            }
            x1=x;
            y1=y;
            while(x1>0 and y1<7){
                if (board[x1-1][y1+1].freedom == 0){
                    future_states.push_back(State(x1-1,y1+1));
                    x1--;
                    y1++;
                }
                 else if (board[x1-1][y1+1].figure->color != this->color){
                    future_states.push_back(State(x1-1,y1+1));
                    x1--;
                    y1++;
                    break;
                }
                else{
                    break;
                }
            }
            x1 = x;
            y1 = y;
            while(x1>0 and y1>0){
                if (board[x1-1][y1-1].freedom == 0){
                    future_states.push_back(State(x1-1,y1-1));
                    x1--;
                    y1--;
                }
                 else if (board[x1-1][y1-1].figure->color != this->color){
                    future_states.push_back(State(x1-1,y-1));
                    x1--;
                    y1--;
                    break;
                }
                else{
                    break;
                }
            }
            x1=x;
            y1=y;
            while(x1<7){
                if (board[x1+1][y1].freedom == 0){
                    future_states.push_back(State(x1+1,y1));
                    x1++;
                }
                else if (board[x1+1][y1].figure->color != this->color){
                    future_states.push_back(State(x1+1,y1));
                    x1++;
                    break;
                }
                else{
                    break;
                }
            }
            x1 = x;
            while(x1>0){
                if (board[x1-1][y1].freedom == 0){
                    future_states.push_back(State(x1-1,y1));
                    x1--;
                }
                 else if (board[x1-1][y1].figure->color != this->color){
                    future_states.push_back(State(x1-1,y1));
                    x1--;
                    break;
                }
                else{
                    break;
                }
            }
            x1=x;
            while(y1<7){
                if (board[x1][y1+1].freedom == 0){
                    future_states.push_back(State(x1,y1+1));
                    y1++;
                }
                 else if (board[x1][y1+1].figure->color != this->color){
                    future_states.push_back(State(x1,y1+1));
                    y1++;
                    break;
                }
                else{
                    break;
                }
            }
            y1 = y;
            while(y1>0){
                if (board[x1][y1-1].freedom == 0){
                    future_states.push_back(State(x1,y1-1));
                    y1--;
                }
                 else if (board[x1][y1-1].figure->color != this->color){
                    future_states.push_back(State(x1,y1-1));
                    y1--;
                    break;
                }
                else{
                    break;
                }
            }
        }
        else {
            if ( (board[x+1][y].freedom == 0 or board[x+1][y].figure->color!=this->color)
                 and x<7)
                future_states.push_back(State(x+1,y));
            if ( (board[x-1][y].freedom == 0 or board[x-1][y].figure->color!=this->color)
                 and x>0)
                future_states.push_back(State(x-1,y));
            if ( (board[x+1][y+1].freedom == 0 or board[x+1][y+1].figure->color!=this->color)
                 and x<7 and y<7)
                future_states.push_back(State(x+1,y+1));
            if ( (board[x+1][y-1].freedom == 0 or board[x+1][y-1].figure->color!=this->color)
                 and x<7 and y>0)
                future_states.push_back(State(x+1,y-1));
            if ( (board[x-1][y+1].freedom == 0 or board[x-1][y+1].figure->color!=this->color)
                 and x>0 and y<7)
                future_states.push_back(State(x-1,y+1));
            if ( (board[x-1][y-1].freedom == 0 or board[x-1][y-1].figure->color!=this->color)
                 and x>0 and y>0)
                future_states.push_back(State(x-1,y-1));
            if ( (board[x][y+1].freedom == 0 or board[x][y+1].figure->color!=this->color)
                 and y<7)
                future_states.push_back(State(x,y+1));
            if ( (board[x][y-1].freedom == 0 or board[x][y-1].figure->color!=this->color)
                 and y>0)
                future_states.push_back(State(x,y-1));
        }
    }
    void show_future(){
        for(int i=0;i<future_states.size();i++){
            std::cout<<"x y "<<future_states[i].x<<' '<<future_states[i].y<<endl;
        }
    }
};

/*class Square{
public:
    int freedom;
    Figure* figure;

};*/

/*class Board{ //доска
public:
    int board[8][8];
    FigureType figure_type[8][8];

};*/

/*Figure::Figure(FigureType type,ColorType color,int x, int y,Square my_board[8][8]): State(x,y){
    this->color=color;
    this->type=type;
    my_board[x][y].freedom =1;
}

Figure::future(Square board[8][8]){
    int x = this->y;
    int y = this->x;
    if (type == PawnType){
        if (board[x][y+2].freedom == 0  and y == 1)
            future_states.push_back(State(x,y+2));
        if (board[x][y+1].freedom == 0 and y<7)
            future_states.push_back(State(x,y+1));
        if (board[x+1][y+1].freedom != 0 and y<7 and x<7)
            future_states.push_back(State(x+1,y+1));
        if (board[x-1][y+1].freedom != 0 and y<7 and x>0)
            future_states.push_back(State(x-1,y+1));
        this->n=future_states.size();
    }
}

Figure::show_future(){
    for(int i=0;i<future_states.size();i++){
        std::cout<<"x y "<<future_states[i].x<<' '<<future_states[i].y<<endl;
    }
}*/


/*class Figure: public State{
public:
      enum FigureType{
        PawnType,
        KnightType,
        BishopType,
        RookType,
        QueenType,
        KingType
    };
    State current_state;
    State last_state;
    FigureType type;
    Figure(): State(){
        this->type = type;

    }

    vector<State> future(Board board){
        vector <State> future_states;
        int x = this->current_state.x;
        int y = this->current_state.y;
        if (type == PawnType){
            if (board.board[x][y+1] == 0 and y<7)
                future_states.push_back(State(x,y+1));
            if (board.board[x+1][y+1] != 0 and y<7 and x<7)
                future_states.push_back(State(x+1,y+1));
            if (board.board[x-1][y+1] != 0 and y<7 and x>0)
                future_states.push_back(State(x-1,y+1));
       }
       return future_states;
    }

};

*/





#endif // FIGURE_H
