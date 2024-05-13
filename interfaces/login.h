#include "../librerias/csv/modulosControlCSV.h"

#include <iostream>
#include <vector>

vector <vector <string>> cargarUsuarios () {
    vector <vector <string>> vectorUsuarios;
    vector <int> filtros = {0,1,2,3,4,5,6,7,8};
    cargarDatos("datos/csvUsuario/DatosUsuario.csv", vectorUsuarios, filtros);
    return vectorUsuarios;
}

vector <string> login () {
    string claveDigital, correoElectronico;
    bool permiso = false;

    vector <vector <string>> vectorUsuarios = cargarUsuarios();
    vector <string> USUARIO;
    vectorUsuarios.erase(vectorUsuarios.begin());

    while(permiso==false) {
        cout << "Deuda Cero" << endl << endl;
        cout << "------------------" << endl;
        cout << "Inicio de sesión |" << endl;
        cout << "------------------" << endl;
        cout << endl;
        cout << "Ingrese su correo electronico: ";
        cin >> correoElectronico;

        cout << "Ingrese su clave digital: ";
        cin >> claveDigital;

        for (vector <string> usuario : vectorUsuarios) {
            if (claveDigital == usuario[8] && correoElectronico == usuario[2]) {
                permiso = true;
                USUARIO = usuario;
                break;
            }
        }

        if (permiso == true) {
            cout << endl << "Acceso permitido" << endl;
            system("PAUSE");
            system("CLS");
            return USUARIO;
        } else {
            cout << endl << "Acceso denegado, intentelo de nuevo porfavor" << endl;
            system("PAUSE");
            system("CLS");
        }
    }
    return vector <string> {};
}