#include "modulos/modulosTabla.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

//Compila aqui owo

//Funcion que imprime las deudas y muestra un submenú dedicado
void administrarDeudas ();

void pagarDeuda ();
    
void visualizarDeudaCompleta ();

//Funcion que imprime en formato tabla la información de las deudas
void impresionDeudas () {
    vector <string> cabeceraPorDefecto = {"Apellidos", "Correo Electronico", "DNI", "Fecha de vencimiento"};
    vector <string> vectorCabeceras;
    vector <vector <string>> vectorDeudas;
    vector <int> filtros;
    cargarCabeceras("datos/cabeceras.csv", vectorCabeceras, filtros, cabeceraPorDefecto);
    cargarDeudas("datos/datos.csv", vectorDeudas, filtros);
    imprimirTabla(vectorDeudas, vectorCabeceras, 30);
}

int main () {
    system("PAUSE");
    impresionDeudas();
    system("PAUSE");
}