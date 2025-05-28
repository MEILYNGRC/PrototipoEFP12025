#include "bitacora.h"
#include <fstream>
#include <ctime>
#include <iostream>

using namespace std;

void registrarAccion(const string& nombreUsuario, const string& accion, const string& codigoApp) {
    ofstream archivo("bitacora.dat", ios::binary | ios::app);
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);

    string registro = nombreUsuario + " | " + accion + " | " + codigoApp + " | ";
    registro += to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);
    registro += " " + to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + "\n";

    archivo.write(registro.c_str(), registro.size());
    archivo.close();
}

void verBitacora() {
    ifstream archivo("bitacora.dat", ios::binary);
    if (!archivo) {
        cout << "No hay registros.\n";
        return;
    }

    char c;
    while (archivo.get(c)) cout << c;
    archivo.close();
}
