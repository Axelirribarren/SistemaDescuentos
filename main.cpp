#include <iostream>
#include <fstream>
#include "gestor.h"
#include <cstring>
using namespace std;


struct strClientes{
    int nro;
    char nombre[200];
    char tipo;
};


struct strVentas{
    int nro_cliente;
    int cantidad;
    double montoTotal;
};

// Función para crear archivo de clientes ficticios
void crearArchivoClientes() {
    ofstream arch("cliente.dat", ios::out | ios::binary);
    if(!arch) {
        cout << "Error al crear archivo de clientes" << endl;
        return;
    }

    strClientes clientes[10];
    
 
    clientes[0].nro = 1;
    strcpy(clientes[0].nombre, "Juan Perez");
    clientes[0].tipo = 'A';
    

    clientes[1].nro = 2;
    strcpy(clientes[1].nombre, "Maria Rodriguez");
    clientes[1].tipo = 'B';
    

    clientes[2].nro = 3;
    strcpy(clientes[2].nombre, "Carlos Gomez");
    clientes[2].tipo = 'C';
    
    
    clientes[3].nro = 4;
    strcpy(clientes[3].nombre, "Ana Martinez");
    clientes[3].tipo = 'A';
    
 
    clientes[4].nro = 5;
    strcpy(clientes[4].nombre, "Pedro Lopez");
    clientes[4].tipo = 'B';
    
    
    clientes[5].nro = 6;
    strcpy(clientes[5].nombre, "Laura Fernandez");
    clientes[5].tipo = 'C';
    
    // Cliente 7 - Tipo A (nombre repetido para probar)
    clientes[6].nro = 7;
    strcpy(clientes[6].nombre, "Juan Perez");
    clientes[6].tipo = 'A';
    
    
    clientes[7].nro = 8;
    strcpy(clientes[7].nombre, "Sofia Garcia");
    clientes[7].tipo = 'B';
    
   
    clientes[8].nro = 9;
    strcpy(clientes[8].nombre, "Diego Silva");
    clientes[8].tipo = 'C';
    
    // Cliente 10 - Tipo A (nombre repetido para probar)
    clientes[9].nro = 10;
    strcpy(clientes[9].nombre, "Maria Rodriguez");
    clientes[9].tipo = 'A';
    
    for(int i = 0; i < 10; i++) {
        arch.write((char*)&clientes[i], sizeof(strClientes));
    }
    
    arch.close();
    cout << "Archivo cliente.dat creado con 10 clientes ficticios" << endl;
}

// Función para crear archivo de ventas ficticias
void crearArchivoVentas() {
    ofstream arch("ventas.dat", ios::out | ios::binary);
    if(!arch) {
        cout << "Error al crear archivo de ventas" << endl;
        return;
    }

    strVentas ventas[20];
    
    // Ventas para diferentes clientes con distintas cantidades y montos
    ventas[0] = {1, 15, 1500.50};
    ventas[1] = {2, 8, 800.00};
    ventas[2] = {3, 25, 2500.75};
    ventas[3] = {1, 10, 1000.00};  // Cliente 1 compra de nuevo
    ventas[4] = {4, 30, 3000.00};
    ventas[5] = {5, 5, 500.25};
    ventas[6] = {6, 12, 1200.50};
    ventas[7] = {2, 7, 700.00};    // Cliente 2 compra de nuevo
    ventas[8] = {7, 20, 2000.00};
    ventas[9] = {8, 18, 1800.30};
    ventas[10] = {9, 22, 2200.80};
    ventas[11] = {10, 9, 900.00};
    ventas[12] = {3, 14, 1400.60}; // Cliente 3 compra de nuevo
    ventas[13] = {1, 5, 500.00};   // Cliente 1 compra de nuevo (3ra vez)
    ventas[14] = {4, 11, 1100.00}; // Cliente 4 compra de nuevo
    ventas[15] = {6, 16, 1600.00}; // Cliente 6 compra de nuevo
    ventas[16] = {7, 13, 1300.00}; // Cliente 7 compra de nuevo
    ventas[17] = {9, 8, 800.00};   // Cliente 9 compra de nuevo
    ventas[18] = {10, 19, 1900.50};// Cliente 10 compra de nuevo
    ventas[19] = {4, 25, 2500.00}; // Cliente 4 compra de nuevo (3ra vez)
    
    
    for(int i = 0; i < 20; i++) {
        arch.write((char*)&ventas[i], sizeof(strVentas));
    }
    
    arch.close();
    cout << "Archivo ventas.dat creado con 20 registros de ventas ficticias" << endl;
}

int main()
{
    cout << "========================================" << endl;
    cout << "  SISTEMA DE DESCUENTOS - PRUEBA" << endl;
    cout << "========================================" << endl << endl;
    
    
    cout << "PASO 1: Creando archivos de datos ficticios..." << endl;
    crearArchivoClientes();
    crearArchivoVentas();
    cout << endl;
    
    
    cout << "PASO 2: Cargando datos en el sistema..." << endl;
    Gestor gestor;
    gestor.leerArchivos();
    cout << "Clientes cargados desde cliente.dat" << endl;
    gestor.procesarVentas();
    cout << "Ventas procesadas desde ventas.dat" << endl;
    cout << endl;
    
   
    cout << "========================================" << endl;
    cout << "PASO 3: Resultados de las consultas" << endl;
    cout << "========================================" << endl << endl;
    
    cout << "1. Cliente con mayor cantidad acumulada:" << endl;
    cout << "   ----------------------------------------" << endl;
    cout << "   ";
    gestor.obtenerMayorCantidad();
    cout << endl;
    
    cout << "2. Monto total de todas las ventas:" << endl;
    cout << "   ----------------------------------------" << endl;
    cout << "   ";
    gestor.obtenerMontoTotal();
    cout << endl;
    
    cout << "3. Clientes con nombres repetidos:" << endl;
    cout << "   ----------------------------------------" << endl;
    gestor.obtenerClientesRepetidos();
    cout << endl;
    
    cout << "========================================" << endl;
    cout << "  PRUEBA COMPLETADA EXITOSAMENTE" << endl;
    cout << "========================================" << endl;
    
    return 0;
}
