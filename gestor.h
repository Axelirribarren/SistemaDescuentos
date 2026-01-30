#ifndef GESTOR_H
#define GESTOR_H
#include <cliente.h>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <estrategiadescuento.h>
class Gestor
{
private:
    map<int,Cliente> cli;

public:
    Gestor();
    ~Gestor();
    void leerArchivos();
    void procesarVentas();
    void obtenerMayorCantidad();
    void obtenerMontoTotal();
    void obtenerClientesRepetidos();
};

#endif // GESTOR_H
