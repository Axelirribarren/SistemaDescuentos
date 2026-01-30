#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
using namespace std;
#include <estrategiadescuento.h>

class Cliente
{
private:
    string nombres;
    int cantAcumulada;
    float montoAcumulado;
    char tipo;
    EstrategiaDescuento * estrategia;
public:
    Cliente(string n, int c, float m, char t, EstrategiaDescuento* e);
    double obtenerDescuento(){
        return estrategia->aplicar(cantAcumulada,montoAcumulado);
    }
    ~Cliente();
    string getNombres() const;
    void setNombres(const string &newNombres);
    int getCantAcumulada() const;
    void setCantAcumulada(int newCantAcumulada);
    float getMontoAcumulado() const;
    void setMontoAcumulado(float newMontoAcumulado);
    char getTipo() const;
    void setTipo(char newTipo);
    void setEstrategia(EstrategiaDescuento *newEstrategia);
};

#endif // CLIENTE_H
