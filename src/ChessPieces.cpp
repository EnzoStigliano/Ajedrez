#include <iostream>

class ChessPiece {
    public: 
    int x;
    int y;
    int id[3]; //Tipo de pieza, color, id (sacar de la clase y agregar posición)

    //Calcular casillas a las que se puede mover cada pieza
    void calcularCasillas(int tablero[8][8], int id) {};
};

class Pawn: public ChessPiece {
    int movs;
};

class Tower: public ChessPiece {
    int movs;
};

class King: public ChessPiece {
    int movs;
};