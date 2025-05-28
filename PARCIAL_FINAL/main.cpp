#include "autenticacion.h"
#include "menu.h"
#include <iostream>

using namespace std;

int main() {
    int opcion;
    Usuario usuario;

    cout << "--- Sistema de Inicio ---\n";
    cout << "1. Iniciar sesión\n2. Crear nuevo usuario\nOpción: ";
    cin >> opcion;

    if (opcion == 1) {
        if (!autenticar(usuario)) return 0;
        menuPrincipal(usuario);
    } else if (opcion == 2) {
        crearUsuario();
    }

    return 0;
}
