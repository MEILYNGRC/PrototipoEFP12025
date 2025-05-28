#include "catalogos.h"
#include "bitacora.h"
#include <iostream>
#include <fstream>
#include <cstring>//catalogos meilyn

using namespace std;

struct Producto {
    int id;
    char nombre[30];
    float precio;
};

void altaRegistro(const Usuario& u) {
    Producto p;
    cout << "ID: "; cin >> p.id;
    cin.ignore();
    cout << "Nombre: "; cin.getline(p.nombre, 30);
    cout << "Precio: "; cin >> p.precio;

    ofstream f("productos.dat", ios::binary | ios::app);
    f.write(reinterpret_cast<char*>(&p), sizeof(Producto));
    f.close();

    registrarAccion(u.username, "Alta", "CAT001");
}

void bajaRegistro(const Usuario& u) {
    int id;
    cout << "ID del producto a eliminar: ";
    cin >> id;

    ifstream f("productos.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    Producto p;
    bool encontrado = false;
    while (f.read(reinterpret_cast<char*>(&p), sizeof(Producto))) {
        if (p.id != id)
            temp.write(reinterpret_cast<char*>(&p), sizeof(Producto));
        else
            encontrado = true;
    }

    f.close(); temp.close();
    remove("productos.dat");
    rename("temp.dat", "productos.dat");

    if (encontrado) registrarAccion(u.username, "Baja", "CAT002");
}

void modificarRegistro(const Usuario& u) {
    int id;
    cout << "ID del producto a modificar: ";
    cin >> id;

    fstream f("productos.dat", ios::binary | ios::in | ios::out);
    Producto p;

    while (f.read(reinterpret_cast<char*>(&p), sizeof(Producto))) {
        if (p.id == id) {
            cout << "Nuevo nombre: ";
            cin.ignore(); cin.getline(p.nombre, 30);
            cout << "Nuevo precio: ";
            cin >> p.precio;

            f.seekp(-sizeof(Producto), ios::cur);
            f.write(reinterpret_cast<char*>(&p), sizeof(Producto));
            registrarAccion(u.username, "Modificación", "CAT003");
            break;
        }
    }
    f.close();
}

void consultarRegistro() {
    Producto p;
    ifstream f("productos.dat", ios::binary);
    while (f.read(reinterpret_cast<char*>(&p), sizeof(Producto))) {
        cout << "ID: " << p.id << " Nombre: " << p.nombre << " Precio: Q" << p.precio << endl;
    }
    f.close();
}
