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
    double aplicar(int cant, float monto) override;
};

#endif // DESCUENTOC_H
