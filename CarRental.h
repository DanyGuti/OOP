/*
Proyecto hecho por Daniel Gutiérrez Gómez
A01068056
Esta es el documento de la clase Car Rental
composición con Inventario
*/
#ifndef CARRENTAL_H_
#define CARRENTAL_H_
#include <string>
#include <iostream>
#include "inventario.h"
using namespace std;

class CarRental
{
private:
    uint id;

public:
    Inventario *inventarioCarros = new Inventario();
    CarRental() : id(0){};
    void muestraCarros();
    void reservarCarro();
    void añadirCarrosTipo();
    void añadirCarros();
};
// Método que añade carros a la empresa de renta de carros
void CarRental::añadirCarros()
{
    inventarioCarros->agregarCarros();
}

// Método que añade carros a la empresa por tipo de carro
void CarRental::añadirCarrosTipo()
{
    string tipo;
    string marca, color;
    float rendim;
    uint precio;
    bool flag = true;
    cout << "Hola jefe, por favor escribe que tipo de carro deseas agregar al inventario: suv, lujo o todoterreno: " << endl
         << endl;
    while (flag)
    {
        cin >> tipo;
        if (tipo == "suv")
        {
            cout << "Escribe una marca de SUV: " << endl;
            cin >> marca;
            cout << "Escribe el rendimiento del SUV: " << endl;
            cin >> rendim;
            cout << "Escribe el color del SUV: " << endl;
            cin >> color;
            cout << "Escribe el precio del SUV para su renta: " << endl;
            cin >> precio;
            inventarioCarros->construirSuv(marca, rendim, color, precio);
            flag = false;
        }
        if (tipo == "todoterreno")
        {
            cout << "Escribe una marca de todoTerreno: " << endl;
            cin >> marca;
            cout << "Escribe el rendimiento del todoTerreno: " << endl;
            cin >> rendim;
            cout << "Escribe el color del todoTerreno: " << endl;
            cin >> color;
            cout << "Escribe el precio del todoTerreno para su renta: " << endl;
            cin >> precio;
            inventarioCarros->construirTodoTerreno(marca, rendim, color, precio);
            flag = false;
        }
        if (tipo == "lujo")
        {
            cout << "Escribe una marca de lujo: " << endl;
            cin >> marca;
            cout << "Escribe el rendimiento del lujo: " << endl;
            cin >> rendim;
            cout << "Escribe el color del lujo: " << endl;
            cin >> color;
            cout << "Escribe el precio del lujo para su renta: " << endl;
            cin >> precio;
            inventarioCarros->construirLujo(marca, rendim, color, precio);
            flag = false;
        }
        else
        {
            cout << "Por favor escribe 'suv', 'lujo' o 'todoterreno': " << endl;
            flag = true;
        }
    }
}
// Mostrar inventario actual de carros
void CarRental::muestraCarros()
{
    inventarioCarros->mostrarCarros();
}
// Reservar carro por precio ingresado
void CarRental::reservarCarro()
{
    bool flag = true;
    while (flag)
    {
        if (inventarioCarros->mostrarPorPrecio() == true)
        {
            flag = false;
        }
        else
            flag = true;
    }
};
#endif