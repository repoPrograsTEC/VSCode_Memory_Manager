//
// Created by daniel on 31/5/20.
//

#include <cstdlib>
#include <cstdio>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <unistd.h>


using json= nlohmann::json;


int main() {

    struct sockaddr_in diServidor{};
    diServidor.sin_family = AF_INET;
    diServidor.sin_addr.s_addr = INADDR_ANY;
    diServidor.sin_port = htons(8080);

    int servidor = socket(AF_INET, SOCK_STREAM, 0);

    int activado = 1;
    setsockopt(servidor, SOL_SOCKET, SO_REUSEADDR, &activado, sizeof(activado));

    if (bind(servidor, reinterpret_cast<const sockaddr *>(&diServidor), sizeof(diServidor)) != 0) {
        perror("Falló el bind");
        return 1;
    }

    printf("Iniciando\n");
    listen(servidor, 100);

    //------------------------------

    struct sockaddr_in direccionCliente{};
    unsigned int tamanoDireccion;
    int cliente = accept(servidor, reinterpret_cast<sockaddr *>(&direccionCliente), &tamanoDireccion);

    std::string saludo = "Hola del servidor";
    printf("Recibí una conexión en %d!!\n", cliente);

    send(cliente, saludo.c_str(), saludo.length(), 0);
    //------------------------------

    char* buffer ;
    buffer = static_cast<char *> (malloc(1000));

    while (true) {

        //free(buffer);
        int bytesRecibidos = recv(cliente, buffer, 1000, 0);
        if (bytesRecibidos <= 0) {
            perror("Desconectado");
            return 1;
        }


        buffer[bytesRecibidos] = '\0';

        json datos;
        std::map<std::string , std::string> m1;

        std::string verificacion = buffer;

        if (verificacion == ("EnviandoDatos")){

            std::cout << "Enviando datos Datos" << std::endl;

            int cont = 1;
            bool ciclo = true;

            while(ciclo){
                if (verificacion == ("TermDatos")){

                    std::cout << "Terminando Datos" << std::endl;
                    ciclo = false;
                    std::ofstream ob("/home/daniel/CLionProjects/testServer/data.json");
                    ob << std::setw(4) << datos << std::endl;
                }

                bytesRecibidos = recv(cliente, buffer, 1000, 0);
                if (bytesRecibidos <= 0) {
                    perror("Desconectado");
                    return 1;
                }
                buffer[bytesRecibidos] = '\0';
                verificacion = buffer;

                std::string direccion, id, referencia, tipo, valor;


                if (cont == 1) {
                    //direccion = buffer;

                    m1.insert({"Direccionmemoria", std::string(buffer)});
                    cont++;
                    //std::cout << direccion << std::endl;
                }
                else if (cont == 2) {
                    //id = buffer;
                    m1.insert({"ID", buffer});
                    cont++;
                    //std::cout << id << std::endl;
                }
                else if (cont == 3) {
                    //referencia = buffer;
                    m1.insert({"Referencias", std::string(buffer)});
                    cont++;
                    //std::cout << referencia << std::endl;
                }
                else if (cont == 4) {
                    //tipo = buffer;
                    m1.insert({"Tipodedato", std::string(buffer)});
                    cont++;
                    //std::cout << tipo << std::endl;
                }
                else if (cont == 5) {
                    //valor = buffer;
                    cont = 1;
                    //std::cout << valor << std::endl;
                    m1.insert({"Valor", std::string(buffer)});
                    datos["Lista"] += m1;
                    m1.clear();
                }
                //std::cout << m1.size() << std::endl;
                std::cout << datos << std::endl;

            }

        }

        else if (verificacion == ("RecibirDatos")){

            std::cout << "Recibiendo datos Datos" << std::endl;

            std::ifstream dataArchive("/home/daniel/CLionProjects/testServer/data.json", std::ifstream::binary);

            json data;

            dataArchive >> data;


            for (auto &x : data["Lista"]) {

                auto *ra = &x;

                for (auto element = (*ra).begin(); element != (*ra).end(); element++) {

                    //send(cliente, std::string(element.key()).c_str(), std::string(element.key()).length(), 0);
                    //sleep(1);

                    send(cliente, (element.value().dump()).c_str(),
                         (element.value().dump()).length(), 0);
                    sleep(1);
                }
            }

            send (cliente, "TermDatos", 13, 0);

        }

        printf("Me llegaron %d bytes con %s\n", bytesRecibidos, buffer);

    }

    free(buffer);

    return 0;
}

