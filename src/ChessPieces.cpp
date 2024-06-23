#include <iostream>

class ChessPiece {
    public: 
    int x;
    int y;
    int id[3]; //Tipo de pieza, color, id

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

class Queen: public ChessPiece {
    int movs;
};

class Knight: public ChessPiece {
    int movs;
};

class Bishop: public ChessPiece {
    int movs;
};