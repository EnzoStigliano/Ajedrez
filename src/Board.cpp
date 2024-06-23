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
    void generateBoard() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                piecesBoard[i][j] = 2;

                if ((i + j) % 2 == 0) functionalBoard[i][j] = 1;
                else functionalBoard[i][j] = 0;
            }
        }
    }

    //Poner las id de las piezas en piecesBoard
    void colocatePieces() {
        //Peones blancos
        for (i = 1; i < 9; i++) {
            piecesBoard[6][i-1] = 210 + i;
        }

        //Peones negros
        for (i = 1; i < 9; i++) {
            piecesBoard[1][i-1] = 200 + i;
        }

        //Reyes
        piecesBoard[0][3] = 70;
        piecesBoard[7][4] = 71;

        //Reinas
        piecesBoard[0][4] = 60;
        piecesBoard[7][3] = 61;

        //Alfiles
        piecesBoard[0][2] = 501;
        piecesBoard[0][5] = 502;
        piecesBoard[7][2] = 511;
        piecesBoard[7][5] = 512;

        //Torres
        piecesBoard[0][0] = 401;
        piecesBoard[0][7] = 402;
        piecesBoard[7][0] = 411;
        piecesBoard[7][7] = 412;

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
                else cout << " | " << functionalBoard[i][j];
            }
            cout << " |" << endl << " +---+---+---+---+---+---+---+---+" << endl;
        }
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

    int verificarMate(int color){
        int check = 0;

        for(i = 0; i < 8; i++){
            for(j = 0; j < 8; j++){
                pieza = to_string(piecesBoard[i][j]);
                if(pieza[0] == 7 && pieza[1] == !color){
                    break;
                }
            }
        }

        menacePositions(color);

        if(color){
            if(i > 0){
                //Fijarse arriba
                if(j > 0){
                    //Fijarse izquierda
                    //Fijarse arriba a la izquierda
                }
            }
        }
    }

    void moverPieza(int tablero[8][8], int id) {
    };
};