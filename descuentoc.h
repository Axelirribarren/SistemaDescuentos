#ifndef DESCUENTOC_H
#define DESCUENTOC_H
#include <estrategiadescuento.h>
#include <iostream>
#include <algorithm>

class DescuentoC:public EstrategiaDescuento
{
public:
    DescuentoC();
    ~DescuentoC();
    double aplicar(int cant, float monto) override{
        double dCant = calcularPorCantidad(cant);
        double dMonto = calcularPorMonto(monto);
        return std::max(dCant,dMonto);
    }
};

#endif // DESCUENTOC_H
