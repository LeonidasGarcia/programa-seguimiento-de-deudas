#ifndef MODULOSTABLA_H
#define MODULOSTABLA_H
#include "modulosGenerales.h"
#include "../csv/modulosControlCSV.h"
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

//Funciones contenidas en esta librería
void imprimirLineaCuerpo (vector <string> deuda, int espacioCabecera);
void imprimirTabla (vector <vector <string>> vectorDeudas, vector <string> vectorCabeceras, int espacioCabecera);
void imprimirBorde (vector <string> vectorCabeceras ,int espacioCabecera);

/*
Función que imprime una fila de la tabla
Args:
    1. vector <string>: Vector que será recorrido por la función, dejará espacios dependiendo del número de cabeceras de la tabla actual
    2. int espacioCabecera: Espacio disponible para cada celda generada

Si la función detecta una sobrecarga de espacio por el contenido de cualquier celda, llenará el vector <string> auxiliar para generar otra linea
que contenga los siguientes elementos.  
*/
void imprimirLineaCuerpo (vector <string> deuda, int espacioCabecera) {
    vector <string> auxiliar;
    for (auto dato : deuda) {
        string datoCortado = trim(conseguirCadena(dato, espacioCabecera, false));
        if (conseguirCadena(dato, espacioCabecera, true)!="") { auxiliar.push_back(trim(conseguirCadena(dato, espacioCabecera, true))); }
            string espacioLineaMedia (espacioCabecera-datoCortado.length()-2, ' ');
        if (*deuda.begin() == dato) { 
            string espacioLineaMediaPrimera (espacioCabecera-datoCortado.length()-3, ' ');
            cout << "| " << datoCortado << espacioLineaMediaPrimera << '|'; 
        } else { 
            cout << " " << datoCortado << espacioLineaMedia << '|'; 
        }
    }
    cout << endl;

    if (auxiliar.size() != 0) {
        for (int i = auxiliar.size(); i < deuda.size(); i++) {
            auxiliar.push_back(" ");
        }
        imprimirLineaCuerpo(auxiliar, espacioCabecera);
    }
}

/*
Función que imprime una linea de "-" cuya cantidad depende del espacio de la cabecera que se use
Args:
    1. vector <string>: Se utiliza el tamaño del vector para generar (espacioCabecera x tamaño) "-"
    2. int espacioCabecera: Factor de multiplicacion del tamaño del vector dado
*/
void imprimirBorde (vector <string> vectorCabeceras ,int espacioCabecera) {
    string longitud (espacioCabecera*(vectorCabeceras.size()), '-');
    cout << longitud << endl;
}

/*
Funcion que imprime toda la tabla, combina todas las funciones para crear una tabla dinámica
Args:
    1. vector <vector <string>>: Vector de vectores que contiene todos los datos
    2. vector <string>: Vector de cabeceras
    3. int espacioCabecera: Viejo conocido 🧍
*/
void imprimirTabla (vector <vector <string>> vectorDeudas, vector <string> vectorCabeceras, int espacioCabecera) {
    imprimirBorde(vectorCabeceras, espacioCabecera);
    imprimirLineaCuerpo(vectorCabeceras, espacioCabecera);
    imprimirBorde(vectorCabeceras, espacioCabecera);
    for (auto deuda : vectorDeudas) {
        imprimirLineaCuerpo(deuda, espacioCabecera);
    }
    imprimirBorde(vectorCabeceras, espacioCabecera);
}

#endif