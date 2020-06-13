//
// Created by daniel on 12/6/20.
//

#ifndef VSPTR_SOCKET_H
#define VSPTR_SOCKET_H

#include <cstdio>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <unistd.h>
class Socket {
private:
    static Socket* instance;

    int cliente = socket(AF_INET, SOCK_STREAM, 0);

    char* buffer = static_cast<char *>(malloc(1000));

    Socket(const char * ip, int host);

    Socket();


public:

    static Socket* getInstance (const char * ip, int host);

    int coneccion;

    int Verificar2();

    int Verificar(sockaddr_in diServidor);

    void RecvData(const char* path, const char* user);

    void SendData(const char* path, const char* user);
};


#endif //VSPTR_SOCKET_H
