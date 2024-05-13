#ifndef MODULOSGENERALES_H
#define MODULOSGENERALES_H
#include <string>
#include <sstream>
using namespace std;

//Funciones contenidas en esta librería
string trim (string cadena);
string conseguirCadena (string dato, int espacioCabecera, bool sobrante);

/*
Función que quita espacios en blanc0 al final de un string
Args:
    1. string: Cadena que necesita que le quiten espacios en blanco
*/
string trim (string cadena) {
    while (*(cadena.end()-1) == ' ') {
        cadena = cadena.substr(0, (cadena.length()-1));
    }
    return cadena;
}

/*
Funcion necesaria para detectar los saltos de linea en la generación de filas de la función imprimirLineaCuerpo de la libreria modulosTabla.h1
Args:
    1. string: Cadena a ser evaludada
    2. int espacioCabecera: Espacio de la cabecera de la tabla actual
    3. bool:
        true: Devuelve la parte cortada de la cadena, lo que se almacenará en el vector auxiliar
        false: Devuelve la parte que se queda en la fila actual
*/
string conseguirCadena (string dato, int espacioCabecera, bool sobrante) {
    stringstream cadena;
    cadena << dato;
    string parteCortada;
    string resultado;
    string pedazo;
    int indicador {0};

    while ( getline(cadena, pedazo, ' ') ) {
        indicador += pedazo.length()+1;
        if (indicador > espacioCabecera-2) {
            parteCortada += pedazo + " ";
        } else { resultado += pedazo + " "; }
    } 

    return (sobrante) ? parteCortada : resultado;
}

#endif