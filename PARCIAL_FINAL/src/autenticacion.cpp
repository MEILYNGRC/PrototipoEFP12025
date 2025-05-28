#include "autenticacion.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

bool autenticar(Usuario &usuarioActual) {
    char usuario[20], clave[20];
    cout << "Usuario: ";
    cin >> usuario;
    cout << "Clave: ";
    cin >> clave;

    ifstream archivo("usuarios.dat", ios::binary);
    Usuario u;
    while (archivo.read(reinterpret_cast<char*>(&u), sizeof(Usuario))) {
        if (strcmp(u.username, usuario) == 0 && strcmp(u.password, clave) == 0) {
            usuarioActual = u;
            archivo.close();
            return true;
        }
    }
    archivo.close();
    cout << "Credenciales inválidas.\n";
    return false;
}

void crearUsuario() {
    Usuario u;
    cout << "Carné: "; cin >> u.carnet;
    cin.ignore();
    cout << "Nombre completo: "; cin.getline(u.nombre, 50);
    cout << "Nombre de usuario: "; cin >> u.username;
    cout << "Contraseña: "; cin >> u.password;

    ofstream archivo("usuarios.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<char*>(&u), sizeof(Usuario));
    archivo.close();

    cout << "Usuario creado.\n";
}
