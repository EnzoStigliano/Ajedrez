#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>

int main() {
    WSADATA wsa;
    int puerto = 20;
    char ip[30];
    char mensajes[200];
    char mensajer[200];
    int sock;
    struct sockaddr_in direccion;

    WSAStartup(MAKEWORD(2, 0), &wsa);

    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    printf("Ip del chat: ");
    scanf("%s", ip);

    direccion.sin_family = AF_INET;
    direccion.sin_port = htons(puerto);
    direccion.sin_addr.s_addr = inet_addr(ip);

    while (1) {
        recv(sock, mensajer, sizeof(mensajer), 0);
        printf("\nMensaje recibido: %s", mensajer);

        printf("\nMensaje a enviar: ");
        scanf("%s", &mensajes);
        send(sock, mensajes, strlen(mensajes), 0);
    }

    closesocket(sock);

    return 0;
}