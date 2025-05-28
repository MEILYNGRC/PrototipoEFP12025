#include "menu.h"
#include "catalogos.h"
#include "informes.h"
#include "bitacora.h"
#include "usuarios.h"
#include <iostream>

using namespace std;

void menuCatalogo(const Usuario& usuario) {
    int opc;
    do {
        cout << "\n--- Menú Catálogo ---\n";
        cout << "1. Alta\n2. Baja\n3. Modificación\n4. Consulta\n0. Regresar\nOpción: ";
        cin >> opc;

        switch(opc) {
            case 1: altaRegistro(usuario); break;
            case 2: bajaRegistro(usuario); break;
            case 3: modificarRegistro(usuario); break;
            case 4: consultarRegistro(); break;
        }
    } while (opc != 0);
}

void menuPrincipal(const Usuario& usuario) {
    int opc;
    do {
        cout << "\n===== Sistema de Gestión =====\n";
        cout << "Bienvenido: " << usuario.nombre << " | Carné: " << usuario.carnet << "\n";
        cout << "1. Catálogos\n2. Informes\n3. Seguridad\n0. Salir\nOpción: ";
        cin >> opc;

        switch(opc) {
            case 1: menuCatalogo(usuario); break;
            case 2: imprimirInforme(); break;
            case 3: {
                int sub;
                do {
                    cout << "\n--- Menú de Seguridad ---\n";
                    cout << "1. Ver Bitácora\n2. Listar Usuarios\n0. Regresar\nOpción: ";
                    cin >> sub;
                    switch (sub) {
                        case 1: verBitacora(); break;
                        case 2: listarUsuarios(); break;
                    }
                } while (sub != 0);
                break;
            }
        }
    } while (opc != 0);
}
