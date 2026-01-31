#include "cliente.h"

string Cliente::getNombres() const
{
    return nombres;
}
// En cliente.cpp
Cliente::Cliente() {
    // Inicialización segura "por defecto"
    this->nombres = "";
    this->cantAcumulada = 0;
    this->montoAcumulado = 0.0;
    this->tipo = ' ';
    this->estrategia = nullptr; // ¡Vital para que no explote el destructor!
}
void Cliente::setNombres(const string &newNombres)
{
    nombres = newNombres;
}

int Cliente::getCantAcumulada() const
{
    return cantAcumulada;
}

void Cliente::setCantAcumulada(int newCantAcumulada)
{
    cantAcumulada = newCantAcumulada;
}

float Cliente::getMontoAcumulado() const
{
    return montoAcumulado;
}

void Cliente::setMontoAcumulado(float newMontoAcumulado)
{
    montoAcumulado = newMontoAcumulado;
}

char Cliente::getTipo() const
{
    return tipo;
}

void Cliente::setTipo(char newTipo)
{
    tipo = newTipo;
}

void Cliente::setEstrategia(EstrategiaDescuento *newEstrategia)
{
    if(this->estrategia != nullptr){
        delete this -> estrategia;
    }

    this->estrategia = newEstrategia;
}

Cliente::Cliente(string n, int c, float m, char t, EstrategiaDescuento* e):nombres(n),
    cantAcumulada(c), montoAcumulado(m), tipo(t),estrategia(e)  {}

Cliente::~Cliente(){
    if(estrategia != nullptr){
        delete estrategia;
        estrategia = nullptr;
    }
}
