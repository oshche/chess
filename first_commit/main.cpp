#include "mainwindow.h"
#include <QApplication>
#include <figure.h>
#include <iostream>

using namespace std;

void board_maker(int board[8][8]){
    //int board[8][8];
        for (int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                board[i][j] = 0;
}

void board_maker2(Square board2[8][8]){
    //int board[8][8];
        for (int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                board2[i][j].freedom = 0;
}

void start_state(Square board2[8][8]){
    int i;
    for (i=0;i<8;i++){
        board2[i][1].figure = new Figure(PawnType,WhiteType,i,1,board2);
        board2[i][6].figure = new Figure(PawnType,BlackType,i,6,board2);
        board2[i][1].freedom = 1;
        board2[i][6].freedom = 1;

    }
   board2[0][0].figure = new Figure(RookType,WhiteType,0,0,board2);
   //board2[0][0].figure = new Figure(RookType,WhiteType,0,0,board2);

   Figure white_rook2(RookType,WhiteType,7,0,board2);
   board2[7][0].figure = &(white_rook2);
   Figure white_knight1(KnightType,WhiteType,1,0,board2);
   board2[1][0].figure = &(white_knight1);
   Figure white_knight2(KnightType,WhiteType,6,0,board2);
   board2[6][0].figure = &(white_knight2);
   Figure white_bishop1(BishopType,WhiteType,2,0,board2);
   board2[2][0].figure = &(white_bishop1);
   Figure white_bishop2(BishopType,WhiteType,5,0,board2);
   board2[5][0].figure = &(white_bishop2);
   Figure white_queen(QueenType,WhiteType,3,0,board2);
   board2[3][0].figure = &(white_queen);
   Figure white_king(KnightType,WhiteType,4,0,board2);
   board2[4][0].figure = &(white_king);

   Figure black_rook1(RookType,WhiteType,0,7,board2);
   board2[0][7].figure = &(black_rook1);
   Figure black_rook2(RookType,WhiteType,7,7,board2);
   board2[7][7].figure = &(black_rook2);
   Figure black_knight1(KnightType,WhiteType,1,7,board2);
   board2[1][7].figure = &(black_knight1);
   Figure black_knight2(KnightType,WhiteType,6,7,board2);
   board2[6][7].figure = &(black_knight2);
   Figure black_bishop1(BishopType,WhiteType,2,7,board2);
   board2[2][7].figure = &(black_bishop1);
   Figure black_bishop2(BishopType,WhiteType,5,7,board2);
   board2[5][7].figure = &(black_bishop2);
   Figure black_queen(QueenType,WhiteType,3,7,board2);
   board2[3][7].figure = &(black_queen);
   Figure black_king(KnightType,WhiteType,4,7,board2);
   board2[4][7].figure = &(black_king);

   for(i=0;i<8;i++){
       board2[i][0].freedom =1;
       board2[i][7].freedom =1;
   }*/
}



using namespace  std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    int board[8][8];
    board_maker(board);
    Square board2[8][8];
    board_maker2(board2);
    start_state(board2);
    //std::cout<<"freedom: "<<board2[2][3].freedom<<endl;
    Figure pawn1(PawnType, WhiteType, 3, 4, board2);
    Figure pawn(PawnType, WhiteType, 3, 3, board2);
    std::cout<<"Coordinati: "<<pawn.x<<" "<<pawn.y<<endl;
    pawn.future(board2);
    std::cout << "Hello!" << endl;
    pawn.show_future();
    cout<<"x "<<pawn.y<<endl;
    if (pawn.color == WhiteType)
        cout<<"Yes "<<endl;
    else if (pawn.color == BlackType)
        cout<<"No"<<endl;
    std::cout<<"x = : "<<board2[0][1].figure->y<<endl;
    //std::cout<<"x: "<<board2[0][0].figure->x;*/


    return a.exec();
}
