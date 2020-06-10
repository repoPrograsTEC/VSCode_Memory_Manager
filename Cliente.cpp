//
// Created by daniel on 31/5/20.
//
#include <cstdio>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <unistd.h>
using json = nlohmann::json ;

class Cliente {

private:

    int cliente = socket(AF_INET, SOCK_STREAM, 0);
    char* buffer = static_cast<char *>(malloc(1000));

public:

    Cliente(const char * ip, int host){

        struct sockaddr_in diServidor{};
        diServidor.sin_family = AF_INET;
        diServidor.sin_addr.s_addr = inet_addr(ip);
        diServidor.sin_port = htons(host);

        if (connect(cliente, reinterpret_cast<const sockaddr *>(&diServidor), sizeof(diServidor)) != 0) {
            perror("No se pudo conectar");
        }

    }

    Cliente(){

        struct sockaddr_in diServidor{};
        diServidor.sin_family = AF_INET;
        diServidor.sin_addr.s_addr = inet_addr("127.0.0.1");
        diServidor.sin_port = htons(8080);

        if (Verificar(diServidor)){
            printf("Conectado correctamente");
        }
    }

    std::string Clear (std::string stri){



    }

    int Verificar2(){

        int bytesRecibidos = recv(cliente, buffer, 1000, 0);

        if (bytesRecibidos <= 0) {
            perror("Desconectado.");
            return 0;
        } else {
            buffer[bytesRecibidos] = '\0';
            printf("Conexion correcta\n");
            printf("Me llegaron %d bytes con %s\n", bytesRecibidos, buffer);
            return 1;
        }

    }

    int Verificar (sockaddr_in diServidor){

        if (connect(cliente, reinterpret_cast<const sockaddr *>(&diServidor), sizeof(diServidor)) != 0) {
            perror("No se pudo conectar");
            return 1;
        }
        return 0;
    }

    void RecvData(const std::string& path){
        free(buffer);

        send(cliente, "RecibirDatos", 12, 0);


        std::cout << "Enviando datos Datos" << std::endl;

        int bytesRecibidos = recv(cliente, buffer, 1000, 0);

        json datos;
        std::map<std::string , std::string> m1;

        std::string verificacion = buffer;

        int cont = 1;
        bool ciclo = true;

        while(ciclo){

            if (verificacion == ("TermDatos")){

                std::cout << "Terminando Datos" << std::endl;
                ciclo = false;
                std::ofstream ob(path);
                ob << std::setw(4) << datos << std::endl;
                break;
            }

            bytesRecibidos = recv(cliente, buffer, 1000, 0);
            if (bytesRecibidos <= 0) {
                perror("Desconectado");
                break;
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

    void SendData(const std::string& path) {

        send (cliente, "EnviandoDatos", 13, 0);
        std::cout << "Enviando datos Datos" << std::endl;

        std::ifstream dataArchive(path, std::ifstream::binary);

        json data;

        dataArchive >> data;


        for (auto &x : data["Lista"]) {

            auto *ra = &x;

            for (auto element = (*ra).begin(); element != (*ra).end(); element++) {

                //send(cliente, std::string(element.key()).c_str(), std::string(element.key()).length(), 0);
                //sleep(1);

                send(cliente, std::string(element.value().dump()).c_str(),
                        std::string(element.value().dump()).length(), 0);
                sleep(1);
            }
        }

        std::cout << "Terminando Datos" << std::endl;
        send (cliente, "TermDatos", 13, 0);


    }

    void SendMessage(){

        while (true) {

            //int bytesRecibidos = recv(cliente, buffer, 1000, 0);

            std::string mensaje;


            //std::cout << data << std::endl;


            std::cin >> mensaje;


            if (mensaje.length() != 1) {
                send(cliente, mensaje.c_str(), mensaje.length(), 0);

            }
            else{
                break;
            }

        }

    }

};


int main() {

    auto *cliente = new Cliente("127.0.0.1", 8080);

    //cliente->Verificar2();

    //cliente->SendMessage();

    //cliente -> SendData("/home/daniel/CLionProjects/prueba/cmake-build-debug/List.json");

    cliente->RecvData("/home/daniel/Desktop/data.json");

    return 0;
}