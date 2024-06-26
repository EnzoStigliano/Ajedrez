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
