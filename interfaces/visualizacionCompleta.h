#ifndef VISUALIZACIONCOMPLETA_H
#define VISUALIZACIONCOMPLETA_H

#include "../librerias/csv/modulosControlCSV.h"
#include "../librerias/tablas/modulosGenerales.h"
#include "../librerias/tablas/modulosTabla.h"

#include <vector>
#include <string>
#include <iostream>
using namespace std;

void imprimirDetalles (vector <string> vectorDeuda) {
    cout << "Producto: " << vectorDeuda[1] << endl;
    cout << "Importe: " << vectorDeuda[2] << endl;
    cout << "institucion: " << vectorDeuda[3] << endl;
    cout << "Cuota: " << vectorDeuda[4] << endl;
    cout << "Fecha de vencimiento: " << vectorDeuda[5] << endl;
    cout << endl;
}

void impresionCronograma (string rutaArchivo, vector <vector <string>>& vectorDeudaSeleccionada) {
    vectorDeudaSeleccionada = cargarDeudaSeleccionada(rutaArchivo);
    vector <string> cabeceras = vectorDeudaSeleccionada[0];
    vectorDeudaSeleccionada.erase(vectorDeudaSeleccionada.begin());
    imprimirTabla(vectorDeudaSeleccionada, cabeceras, 15);
    cout << endl;
}

void visualizacionCompleta (vector <vector <string>> vectorDeuda) {
    int i = 0;
    string id;
    vector <vector <string>> deudaSeleccionada;
    bool encontrado = false;
    system("cls");

        while (encontrado==false) {
            i = 0;
            cout << "Escribe el id de la deuda a mostrar (Retroceder: b): "; cin >> id;
            if (id == "b") {
                system("cls");
                break;}
            for (vector <string> deuda : vectorDeuda) {
                i++;
                if (id == deuda[0]) {
                    encontrado = true;
                    break;
                }   
            }
            if (encontrado) {
                string rutaArchivo = "datos/csvDatosDeuda/" + id + ".csv";
                cout << endl;
                imprimirDetalles(vectorDeuda[i-1]);
                impresionCronograma(rutaArchivo, deudaSeleccionada);
                system("pause");
                system("cls");
            } else {
                cout << "Id no encontrado, intenta nuevamente" << endl;
                system("pause");
                system("cls");
            }
        }
        
    }
    

#endif