#include "descuentoc.h"

DescuentoC::DescuentoC() {}

double DescuentoC::aplicar(int cant, float monto){
    double dCant = calcularPorCantidad(cant);
    double dMonto = calcularPorMonto(monto);
    return std::max(dCant,dMonto);
}
DescuentoC::~DescuentoC(){}
