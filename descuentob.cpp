#include "descuentob.h"

DescuentoB::DescuentoB() {}
double DescuentoB::aplicar(int cant, float monto){
    return calcularPorMonto(monto);
}
DescuentoB::~DescuentoB(){}
