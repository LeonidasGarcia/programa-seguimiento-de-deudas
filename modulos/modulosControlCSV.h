#ifndef MODULOSCONTROLCSV_H
#define MODULOSCONTROLCSV_H
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void cargarCabeceras (string nombreArchivo, vector <string>& vectorCabeceras,vector <int>& filtros ,vector <string> cabeceraPorDefecto);
void cargarDeudas (string nombreArchivo, vector <vector <string>>& vectorDeudas, vector <int> filtros);

//Funcion que lee los datos de un archivo csv y llena el vectorCabeceras
void cargarCabeceras (string nombreArchivo, vector <string>& vectorCabeceras,vector <int>& filtros ,vector <string> cabeceraPorDefecto = {}) {
    int j = 0;
    ifstream archivo (nombreArchivo);
    string linea;
    while ( getline(archivo, linea, ';') ) {
        vectorCabeceras.push_back(linea);
    }

    archivo.close();

    if (cabeceraPorDefecto.size() != 0) {
        for (int i = 0; i < vectorCabeceras.size(); i++) {
            if (vectorCabeceras[i] == cabeceraPorDefecto[j]) {
                filtros.push_back(i);
                j++;
            }
        }
        vectorCabeceras = cabeceraPorDefecto;
    }
} 

//Funcion que lee los datos de un archivo csv y llena el vectorDeudas
void cargarDeudas (string nombreArchivo, vector <vector <string>>& vectorDeudas, vector <int> filtros) {
    ifstream archivo(nombreArchivo);
    string linea;
    while ( getline(archivo, linea) ) {
        int i = 0, j = 0;
        stringstream sso;
        sso << linea;
        string dato;
        vector <string> nuevaDeuda;
        while ( getline(sso, dato, ';') ) {
            if (i == filtros[j]) { 
                nuevaDeuda.push_back(dato); 
                i++;
                j++;
            } else {
                i++;
            }
        }
        vectorDeudas.push_back(nuevaDeuda);      
    }

    archivo.close();
} 

#endif