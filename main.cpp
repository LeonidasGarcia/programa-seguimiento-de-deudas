#include "interfaces/login.h"
#include "interfaces/menuPrincipal.h"
#include "interfaces/visualizacionCompleta.h"

#include <iostream>
#include <vector>
using namespace std;

int main () {
    system("cls");
    vector <string> USUARIO = login();
    menuPrincipal("datos/csvDatosDeuda/DetalleDeudas.csv", USUARIO);
    system("cls");
}