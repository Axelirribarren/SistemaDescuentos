#include "descuentoa.h"

DescuentoA::DescuentoA() {}


DescuentoA::~DescuentoA() {}

double DescuentoA::aplicar(int cant, float monto){
    return calcularPorCantidad(cant) + calcularPorMonto(monto);
}
