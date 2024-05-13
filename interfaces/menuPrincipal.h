#include "../librerias/csv/modulosControlCSV.h"
#include "../librerias/tablas/modulosGenerales.h"
#include "../librerias/tablas/modulosTabla.h"
#include "visualizacionCompleta.h"
#include "pagarDeuda.h"

#include <iostream>
#include <vector>



void impresionDeudas (string rutaArchivo, vector <vector <string>>& vectorDeuda,string numTarjeta) {
    vector <string> cabeceraPorDefecto = {"Id", "Producto", "Importe solicitado", "Institucion", "Cuota", "Fecha de vencimiento"};
    vector <int> filtros {1, 2, 3, 4, 5, 8};
    vectorDeuda = cargarDeudasUsuario(rutaArchivo, numTarjeta, filtros);
    imprimirTabla(vectorDeuda, cabeceraPorDefecto, 23);
}

void menuPrincipal (string rutaArchivo, vector <string> USUARIO) {
    int opc;
    bool continuar = true;
    string guion (40, '-');
    vector <vector <string>> vectorDeudas;

    while (continuar) {
        cout << "Deuda Cero" << endl << endl;
        cout << USUARIO[1] << ", Bienvenido/a a Deuda Cero" << endl << endl;
        impresionDeudas(rutaArchivo, vectorDeudas, USUARIO[5]);
        cout << endl;
        cout << "¿Qué desea hacer hoy?" << endl << endl;
        cout << "1. Visualizar deuda completa" << endl;
        cout << "2. Pagar una deuda" << endl;
        cout << "3. Salir de Deuda Cero" << endl << endl;
        cout << "Seleccione una opción: "; cin >> opc;

        switch (opc) {
            case 1:
                visualizacionCompleta(vectorDeudas);
                break;

            case 2:
                pagarDeuda(vectorDeudas, USUARIO);
                break;

            case 3:
                continuar = false;
                break;

            default:
                cout << "Opción no valida" << endl;
                system("pause");
                system("cls");
                break;
        }
    }
    
    cout << endl <<  "Saliendo de Deuda Cero, nos vemos luego" << endl;
    system("pause");
}