#include <iostream>

#include <string>

using namespace std;

void verificarMate(int color){
}

void moverPieza(int tablero[8][8], int id) {};

//Limpiar la pantalla
void clearScreen() {
    #ifdef _WIN32
    system("cls");
    #else
    int res = system("clear");
    (void)res;
    #endif
}

//Clase ChessPiece
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

class King: public ChessPiece {
    int movs;
};

class Board {
    public: int functionalBoard[8][8];
    int nonVisibleBoard[8][8];
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
    King kg1();
    King kg2();

    //Poner patrón de 0 y 1 en functionalBoard y rellenar de 2 nonVisibleBoard
    void generateChessBoard() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                nonVisibleBoard[i][j] = 2;

                if ((i + j) % 2 == 0) functionalBoard[i][j] = 1;
                else functionalBoard[i][j] = 0;
            }
        }
    }

    //Poner las id de las piezas en nonVisibleBoard
    void colocatePiecesInBoard() {
        //Peones blancos
        int i;

        //Peones blancos
        for (i = 1; i < 9; i++) {
            nonVisibleBoard[6][i-1] = 210 + i;
        }

        //Peones negros
        for (i = 1; i < 9; i++) {
            nonVisibleBoard[1][i-1] = 200 + i;
        }

        //Reyes
        nonVisibleBoard[0][3] = 70;
        nonVisibleBoard[7][4] = 71;

        //Reinas
        nonVisibleBoard[0][4] = 60;
        nonVisibleBoard[7][3] = 61;

        //Alfiles
        nonVisibleBoard[0][2] = 501;
        nonVisibleBoard[0][5] = 502;
        nonVisibleBoard[7][2] = 511;
        nonVisibleBoard[7][5] = 512;

        //Torres
        nonVisibleBoard[0][0] = 401;
        nonVisibleBoard[0][7] = 402;
        nonVisibleBoard[7][0] = 411;
        nonVisibleBoard[7][7] = 412;

        //Caballos
        nonVisibleBoard[0][1] = 301;
        nonVisibleBoard[0][6] = 302;
        nonVisibleBoard[7][1] = 311;
        nonVisibleBoard[7][6] = 312;
    }

    //Imprimir tablero
    void printChessBoard() {
        cout << endl << " +---+---+---+---+---+---+---+---+" << endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if(nonVisibleBoard[i][j] != 2) {cout << " | " << nonVisibleBoard[i][j];}
                else cout << " | " << functionalBoard[i][j];
            }
            cout << " |" << endl << " +---+---+---+---+---+---+---+---+" << endl;
        }
    }
};

int main(void) {
    Board b;
    b.generateChessBoard();
    b.colocatePiecesInBoard();
    b.printChessBoard();

    //verificarMate(color){};
    //verificarJaque();
    //calcularCasillas(id);
    //moverPieza();
    /*
    int turn = 1;
    bool game_over = false;

    //Turnos
    do {
        clearScreen();
        b.printChessBoard();
        int startX, startY, endX, endY;
        cout << "Turno del jugador " << turn << " (Formato: posicionx1 posiciony1 posicionx2 posiciony2): ";
        cin >> startX >> startY >> endX >> endY;

        if (b.movePiece(startX, startY, endX, endY, turn)) {
            clearScreen();
            b.printChessBoard();
            cout << "El rey ha sido capturado. Jugador " << turn << " gana!" << endl;
            game_over = true;
        } else {
            turn = (turn == 1) ? 2 : 1;
        }
    } while (!game_over);
    */
    return 0;
};