#include "informes.h"
#include <fstream>
#include <iostream>

using namespace std;

struct Producto {
    int id;
    char nombre[30];
    float precio;
};

void imprimirInforme() {
    ifstream f("productos.dat", ios::binary);
    ofstream out("informe_productos.txt");

    Producto p;
    while (f.read(reinterpret_cast<char*>(&p), sizeof(Producto))) {
        out << "ID: " << p.id << ", Nombre: " << p.nombre << ", Precio: Q" << p.precio << "\n";
    }
    f.close();
    out.close();

    cout << "Informe generado: informe_productos.txt\n";
}

