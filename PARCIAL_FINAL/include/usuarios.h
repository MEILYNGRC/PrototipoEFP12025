#ifndef USUARIO_H
#define USUARIO_H

struct Usuario {
    char carnet[10];
    char nombre[50];
    char username[20];
    char password[20];
};

void listarUsuarios();
bool buscarUsuario(const char* username);

#endif
