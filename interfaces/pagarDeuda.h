#ifndef PAGARDEUDA_H
#define PAGARDEUDA_H

#include "../librerias/csv/modulosControlCSV.h"
#include "../librerias/tablas/modulosGenerales.h"
#include "../librerias/tablas/modulosTabla.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

string mes = "05";

string subirNuevosDatos (vector <vector <string>> vectorCSV, string stringCSVNuevaLinea, int lineaNueva, string identificador) {
    string textoCSV; 
    for (int i = 0; i < vectorCSV.size(); i++) {
        if (i != lineaNueva) {
            for (string dato : vectorCSV[i]) {
                textoCSV += dato + ";"; 
            }
            textoCSV.erase(textoCSV.end()-1);
            textoCSV += "\n";
        } else {
            for (string dato : vectorCSV[i]) {
                if (dato == identificador) {
                    dato = "Cancelado";
                }
                textoCSV += dato + ";"; 
            }
            textoCSV.erase(textoCSV.end()-1);
            textoCSV += "\n";
        }
        
    }
    return textoCSV;
}

string convertirACSV (vector <vector <string>> vectorCSV) {
    string textoCSV; 
    for (int i = 0; i < vectorCSV.size(); i++) {
        for (string dato : vectorCSV[i]) {
            textoCSV += dato + ";"; 
        }
        textoCSV.erase(textoCSV.end()-1);
        textoCSV += "\n";
    }
    return textoCSV;
}

string convertirACSVMini (vector <string> vectorCSV) {
    string textoCSV; 
        for (string dato : vectorCSV) {
            textoCSV += dato + ";"; 
        }
        textoCSV.erase(textoCSV.end()-1);
        textoCSV += "\n";
    return textoCSV;
}

string convertirAMeses (string fecha) {
    return fecha.substr(3, 2);
}

void pagarDeuda (string rutaArchivo, vector <vector <string>> deudaSeleccionada, vector <vector <string>> vectorTodo, vector <string> USUARIO) {
    string respuesta, stringCSVNuevaLinea, cuota;
    cout << "Desea cancelar la cuota de este mes? (s/n): ";
    cin >> respuesta;
    if (respuesta == "s") {
        ofstream archivo(rutaArchivo);
        stringCSVNuevaLinea = convertirACSV(deudaSeleccionada);
        archivo << subirNuevosDatos(vectorTodo, stringCSVNuevaLinea, stoi(deudaSeleccionada[0][0]), "Pendiente");
        cout << "Cuota de este mes cancelada exitosamente" << endl << endl;
    } else if (respuesta == "n") {

    } else {
        cout << "Respuesta no valida, intentalo nuevamente";
    }
}

bool impresionCuota (string rutaArchivo, vector <vector <string>>& vectorDeudaSeleccionada) {
    vector <string> cabeceras {"Mes", "Vencimiento", "Comision", "Descuento", "Cuota", "Estado"};
    vector <int> filtros {0, 1, 4, 5, 6, 8};
    vectorDeudaSeleccionada = cargarCuotaPendiente(rutaArchivo, filtros);
    string mesDeuda = convertirAMeses(vectorDeudaSeleccionada[0][1]);

    if (mesDeuda == mes) {
        imprimirTabla(vectorDeudaSeleccionada, cabeceras, 15);
        cout << endl;
        return true;
    } else {
        return false;
    }
}

void pagarDeuda (vector <vector <string>> vectorDeuda, vector <string> USUARIO) {
    int i = 0;
    string id;
    vector <vector <string>> deudaSeleccionada;
    bool encontrado = false;
    system("cls");
    while (encontrado==false) {
        i = 0;
        cout << "Escribe el id de la deuda a pagar (Retroceder: b): "; cin >> id;
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
                vector <vector <string>> vectorTodo = cargarCronogramaCompleto(rutaArchivo);
                cout << endl;
                bool pagar = impresionCuota(rutaArchivo, deudaSeleccionada);
                if (pagar) {
                    pagarDeuda(rutaArchivo, deudaSeleccionada, vectorTodo, USUARIO);
                } else {
                    cout << "No tienes cuotas pendientes por pagar" << endl << endl;
                }
                system("pause");
        } else {
            cout << "Id no encontrado, intenta nuevamente" << endl;
            system("pause");
            system("cls");
        }
    }
    system("cls");
}

#endif