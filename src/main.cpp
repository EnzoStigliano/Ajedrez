#include "clearScreen.h"
#include "ChessPieces.h"
#include "Board.h"
#include <iostream>
#include <array>
#include <string>

using namespace std;

int main(void) {
    int color;
    Board b;
    b.generateBoard();
    b.colocatePieces();
    b.printBoard();

    //verificarMate(color){};
    b.verificarJaque(color);
    //calcularCasillas(id);
    //moverPieza();
    /*
    int color = 1;
    bool game_over = false;

    //Turnos
    do {
        clearScreen();
        b.printBoard();
        int startX, startY, endX, endY;
        cout << "Turno del jugador " << turn << " (Formato: posicionx1 posiciony1 posicionx2 posiciony2): ";
        cin >> startX >> startY >> endX >> endY;

        if (b.movePiece(startX, startY, endX, endY, color)) {
            clearScreen();
            b.printBoard();
            cout << "El rey ha sido capturado. Jugador " << color << " gana!" << endl;
            game_over = true;
        } else {
            color = (color == 1) ? 2 : 1;
        }
    } while (!game_over);
    */
    return 0;
};