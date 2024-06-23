#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board {
    public: 
    int functionalBoard[8][8];
    int piecesBoard[8][8];
    int menaceWhiteBoard[8][8];
    int menaceBlackBoard[8][8];
    int i;
    int j;
    string pieza;
    Pawn p1();
    Pawn p2();
    Pawn p3();
    Pawn p4();
    Pawn p5();
    Pawn p6();
    Pawn p7();
    Pawn p8();
    Pawn p9();
    Pawn p10();
    Pawn p11();
    Pawn p12();
    Pawn p13();
    Pawn p14();
    Pawn p15();
    Pawn p16();
    Tower t1();
    Tower t2();
    Tower t3();
    Tower t4();
    King kg1();
    King kg2();

    //Poner patrón de 0 y 1 en functionalBoard y rellenar de 2 piecesBoard
    void generateBoard();

    //Poner las id de las piezas en piecesBoard
    void colocatePieces();

    //Imprimir tablero
    void printBoard();

    void menacePositions(int color);

    //Verificar si el rey de un color está en jaque
    int verificarJaque(int color);

    int verificarMate(int color);

    void moverPieza(int tablero[8][8], int id);
};

#endif 