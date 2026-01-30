#ifndef DESCUENTOA_H
#define DESCUENTOA_H
#include <estrategiadescuento.h>
#include <iostream>
using namespace std;

class DescuentoA: public EstrategiaDescuento
{

public:
    DescuentoA();
    ~DescuentoA();
    double aplicar(int cant, float monto) override{
        return calcularPorCantidad(cant) + calcularPorMonto(monto);
    }
};

#endif // DESCUENTOA_H
