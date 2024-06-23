#include <iostream>

using namespace std;

//Limpiar la pantalla
void clearScreen() {
    #ifdef _WIN32
    system("cls");
    #else
    int res = system("clear");
    (void)res;
    #endif
}