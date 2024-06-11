#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>

int main() {
    WSADATA wsa;
    int puerto = 20;
    char mensaje[200];
    int client_sockets[2]; 
    int sock;
    struct sockaddr_in direccion;
    struct sockaddr_in client_addr;
    int client_addr_len = sizeof(client_addr);

    WSAStartup(MAKEWORD(2, 0), &wsa);
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    direccion.sin_family = AF_INET;
    direccion.sin_port = htons(puerto);
    direccion.sin_addr.s_addr = INADDR_ANY;

    bind(sock, (struct sockaddr*)&direccion, sizeof(direccion));
    listen(sock, 2);

    for (int i = 0; i < 2; i++) {
        client_sockets[i] = accept(sock, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_sockets[i] == INVALID_SOCKET) {
            printf("Error al aceptar cliente\n");
            return 1;
        }
    }

    while (1) {
        memset(mensaje, 0, sizeof(mensaje)); 
        int recv_size = recv(client_sockets[0], mensaje, sizeof(mensaje) - 1, 0);
        if (recv_size > 0) {
            mensaje[recv_size] = '\0';
            send(client_sockets[1], mensaje, recv_size, 0);
        } else if (recv_size <= 0) {
            break;
        }

        memset(mensaje, 0, sizeof(mensaje)); 
        recv_size = recv(client_sockets[1], mensaje, sizeof(mensaje) - 1, 0);
        if (recv_size > 0) {
            mensaje[recv_size] = '\0';
            send(client_sockets[0], mensaje, recv_size, 0);
        } else if (recv_size <= 0) {
            break;
        }
    }

    closesocket(client_sockets[0]);
    closesocket(client_sockets[1]);
    closesocket(sock);

    WSACleanup();

    return 0;
}