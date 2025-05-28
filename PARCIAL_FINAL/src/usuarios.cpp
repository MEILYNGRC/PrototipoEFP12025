#include "usuarios.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void listarUsuarios() {
    ifstream archivo("usuarios.dat", ios::binary);
    if (!archivo) {
        cout << "No se pudo abrir el archivo de usuarios.\n";
        return;
    }

    Usuario u;
    cout << "--- Lista de Usuarios ---\n";
    while (archivo.read(reinterpret_cast<char*>(&u), sizeof(Usuario))) {
        cout << "Carné: " << u.carnet << "\n";
        cout << "Nombre: " << u.nombre << "\n";
        cout << "Usuario: " << u.username << "\n";
        cout << "-------------------------\n";
    }
    archivo.close();
}

bool buscarUsuario(const char* username) {
    ifstream archivo("usuarios.dat", ios::binary);
    if (!archivo) return false;

    Usuario u;
    while (archivo.read(reinterpret_cast<char*>(&u), sizeof(Usuario))) {
        if (strcmp(u.username, username) == 0) {
            archivo.close();
            return true;
        }
    }
    archivo.close();
    return false;
}
