class Board {
    public: 
    int piecesBoard[8][8];
    int menaceWhiteBoard[8][8];
    int menaceBlackBoard[8][8];
    int i;
    int j;
    string pieza;

    //Rellenar de 2 piecesBoard
    void generateBoard() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                piecesBoard[i][j] = 2;
            }
        }
    }

    //Poner las id de las piezas en piecesBoard
    void colocatePieces() {
        //Peones blancos
        for (i = 1; i < 9; i++) {
            piecesBoard[6][i-1] = 2100 + 10 * i;
        }

        //Peones negros
        for (i = 1; i < 9; i++) {
            piecesBoard[1][i-1] = 2000 + 10 * i;
        }

        //Reyes
        piecesBoard[0][3] = 700;
        piecesBoard[7][4] = 710;

        //Reinas
        piecesBoard[0][4] = 60;
        piecesBoard[7][3] = 61;

        //Alfiles
        piecesBoard[0][2] = 501;
        piecesBoard[0][5] = 502;
        piecesBoard[7][2] = 511;
        piecesBoard[7][5] = 512;

        //Torres
        piecesBoard[0][0] = 4010;
        piecesBoard[0][7] = 4020;
        piecesBoard[7][0] = 4110;
        piecesBoard[7][7] = 4120;

        //Caballos
        piecesBoard[0][1] = 301;
        piecesBoard[0][6] = 302;
        piecesBoard[7][1] = 311;
        piecesBoard[7][6] = 312;
    }

    //Imprimir tablero
    void printBoard() {
        cout << endl << " +---+---+---+---+---+---+---+---+" << endl;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if(piecesBoard[i][j] != 2) {cout << " | " << piecesBoard[i][j];}
                else {
                    cout << " | ";
                    if ((i + j) % 2 == 0) cout << "1";
                    else cout << "0";
                }
            }
            cout << " |" << endl << " +---+---+---+---+---+---+---+---+" << endl;
        }
    }

    void possibleMovs(int id){

    }

    void menacePositions(int color){

    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            menaceWhiteBoard[i][j] = 0;
            menaceBlackBoard[i][j] = 0;
        }
    }
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            pieza = to_string(piecesBoard[i][j]);
            if(pieza[1] == color){
                switch(pieza[0]){
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 6:
                        break;
                    case 7:
                        break;
                    }
                }
            }
        }
    }

    //Verificar si el rey de un color está en jaque
    int verificarJaque(int color){
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            pieza = to_string(piecesBoard[i][j]);
            if(pieza[0] == 7 && pieza[1] == color && (menaceWhiteBoard[i][j] == 1 || menaceBlackBoard[i][j] == 1)){
                return 1; //Está en jaque el rey
            }
        }
    }

    return 0; //No está en jaque
    }

    //Verificar si el rey del color contrario están en mate
    int verificarMate(int color){
        int check = 0;
        int kr = -1;
        int cr = -1;

        for(i = 0; i < 8; i++){
            for(j = 0; j < 8; j++){
                pieza = to_string(piecesBoard[i][j]);
                if(pieza[0] == 7 && pieza[1] == !color){
                    kr = i;
                    cr = j;
                    break;
                }
            }
            if(k1 != -1) break;
        }

        menacePositions(color);

        if(color){
            if(menaceBlackBoard[kr][kc]) check++;
            else if (kr > 0) {
                if(menaceBlackBoard[kr-1][kc]) check++;
                if (kc > 0) {
                    if(menaceBlackBoard[kr-1][j-1]) check++;
                }
                if (kc < 7) {
                    if(menaceBlackBoard[kr-1][kc+1]) check++;
                    // Fijarse arriba a la derecha
                }
            } else if (kr < 7) {
                if(menaceBlackBoard[kr+1][kc]) check++;
                // Fijarse abajo
                if (kc > 0) {
                    if(menaceBlackBoard[kr+1][kc+1]) check++;
                    // Fijarse abajo a la izquierda
                }
                if (kc < 7) {
                    if(menaceBlackBoard[kr+1][kc+1]) check++;
                    // Fijarse abajo a la derecha
                }
            } else {
                if (kc > 0) {
                    if(menaceBlackBoard[kr][kc-1]) check++;
                    // Fijarse a la izquierda
                }
                if (kc < 7) {
                    if(menaceBlackBoard[kr][kc+1]) check++;
                    // Fijarse a la derecha
                }
            }

        }
        else if(menaceWhiteBoard[kr][j]) check++;
            else if (i > 0) {
                if(menaceWhiteBoard[i-1][j]) check++;
                if (j > 0) {
                    if(menaceWhiteBoard[i-1][j-1]) check++;
                }
                if (j < 7) {
                    if(menaceWhiteBoard[i-1][j+1]) check++;
                    // Fijarse arriba a la derecha
                }
            } else if (i < 7) {
                if(menaceWhiteBoard[i+1][j]) check++;
                // Fijarse abajo
                if (j > 0) {
                    if(menaceWhiteBoard[i+1][j+1]) check++;
                    // Fijarse abajo a la izquierda
                }
                if (j < 7) {
                    if(menaceWhiteBoard[i+1][j+1]) check++;
                    // Fijarse abajo a la derecha
                }
            } else {
                if (j > 0) {
                    if(menaceWhiteBoard[i][j-1]) check++;
                    // Fijarse a la izquierda
                }
                if (j < 7) {
                    if(menaceWhiteBoard[i][j+1]) check++;
                    // Fijarse a la derecha
                }
            }
        if(check == 9) return 1;
        else return 0;
    }

    void moverPieza(int tablero[8][8], int id) {
    };
};
