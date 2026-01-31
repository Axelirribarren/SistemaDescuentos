#include "gestor.h"
#include "descuentoa.h"
#include "descuentob.h"
#include "descuentoc.h"
#include <numeric>

using namespace std;

struct strClientes{
    int nro;
    char nombre[200];
    char tipo;
};
struct strVentas{
    int nro_cliente;
    int cantidad;
    double montoTotal;
};

Gestor::Gestor()  {}
Gestor::~Gestor(){}
void Gestor::leerArchivos(){
    ifstream arch ("cliente.dat", ios::in);
    if(!arch)cout << "error";

    strClientes registro;

    while(arch.read((char*)&registro, sizeof(registro))){
        Cliente nuevoCliente(registro.nombre,0,0,registro.tipo,nullptr);
        switch(registro.tipo){
            case 'A':
            nuevoCliente.setEstrategia(new DescuentoA());
                break;
            case 'B':
                nuevoCliente.setEstrategia(new DescuentoB());
                break;
            case 'C':
                nuevoCliente.setEstrategia(new DescuentoC());
                break;
        }
        cli[registro.nro] = nuevoCliente;
    }
    arch.close();
}
void Gestor::procesarVentas(){
    ifstream arch("ventas.dat", ios::in);
    if(!arch) cout << "ERROR";

    strVentas regVentas;

    while(arch.read((char*)&regVentas,sizeof(regVentas))){
        auto it = cli.find(regVentas.nro_cliente);
        if(it != cli.end()){
            Cliente &clienteEncontrado = it->second;
            int cantVieja = clienteEncontrado.getCantAcumulada();
            int cantVenta = regVentas.cantidad;
            clienteEncontrado.setCantAcumulada(cantVieja + cantVenta);

            float montoViejo = clienteEncontrado.getMontoAcumulado();
            float montoVenta = regVentas.montoTotal;
            clienteEncontrado.setMontoAcumulado(montoViejo+montoVenta);
        }

    }
    arch.close();
}

void Gestor::obtenerMayorCantidad(){
    if(cli.empty()){
        cout << "NO HAY CLIENTES" << endl;
        return;
    }
    auto it = max_element(cli.begin(),cli.end(),[]
                          (const auto&a, const auto&b){
        return a.second.getCantAcumulada() < b.second.getCantAcumulada();
    });
    cout << it ->second.getNombres() << endl;
    cout << it ->second.getCantAcumulada() << endl;
}

void Gestor::obtenerMontoTotal(){
    double total = accumulate(cli.begin(),cli.end(),0.0,[]
                              (double acumulador, const auto&par){
        return acumulador + par.second.getMontoAcumulado();
    });
    cout << "El monto total de la empresa es: " << total << endl;
}

//No se entiende mucho la actividad, lo hago por "nombre" repetido
void Gestor::obtenerClientesRepetidos(){
    map<string, int> conteoNombres;
    for(auto it = cli.begin();it != cli.end();++it){
        string nombreActual = it->second.getNombres();
        conteoNombres[nombreActual]++;
    }
    cout << "-- Clientes con nombres repetidos --" << endl;
    for(auto it = conteoNombres.begin(); it != conteoNombres.end();++it){
        if(it->second > 1){
            cout << "Nombre: " << it ->first
                 << " - Aparece: " << it->second << " veces..." << endl;
        }
    }
}
