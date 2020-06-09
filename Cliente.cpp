//
// Created by daniel on 31/5/20.
//

#include <cstdio>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>

/*
int main() {
    struct sockaddr_in diServidor{};
    diServidor.sin_family = AF_INET;
    diServidor.sin_addr.s_addr = inet_addr("127.0.0.1");
    diServidor.sin_port = htons(8080);
    int cliente = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(cliente, reinterpret_cast<const sockaddr *>(&diServidor), sizeof(diServidor)) != 0) {
        perror("No se pudo conectar");
        return 1;
    }
    while (true) {
        char mensaje[1000];
        scanf("%s", mensaje);
        if (strlen(mensaje) != 1) {
            send(cliente, mensaje, strlen(mensaje), 0);
        }
        else{
            break;
        }
    }
    return 0;
}
 */
