#ifndef ESTRATEGIADESCUENTO_H
#define ESTRATEGIADESCUENTO_H

class EstrategiaDescuento
{
protected:

    double calcularPorMonto(float monto){
        if(monto > 20000.0) return 0.25;
        else if(monto > 10000.0 && monto < 20000.0) return 0.20;
        return 0.0;
    }
    double calcularPorCantidad(int cant){
        return (cant/100) * 0.01;
    }
public:
    EstrategiaDescuento();
    virtual ~EstrategiaDescuento(){}
    virtual double aplicar(int cantAcum, float montoAcum) = 0;

};

#endif // ESTRATEGIADESCUENTO_H
