#ifndef DESCUENTOB_H
#define DESCUENTOB_H
#include <estrategiadescuento.h>
#include <iostream>

class DescuentoB:public EstrategiaDescuento
{
public:
    DescuentoB();
    ~DescuentoB();
    double aplicar(int cant, float monto) override{
        return calcularPorMonto(monto);
    }
};

#endif // DESCUENTOB_H
