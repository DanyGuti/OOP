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
    Inventary *carInventary = new Inventary();
    CarRental() : id(0){};
    void showCarsInventary();
    void bookCars();
    void addCarsInventaryType();
    void addCarsInventary();
};
// Método que añade carros a la empresa de renta de carros
void CarRental::addCarsInventary()
{
    carInventary->addCars();
};

// Método que añade carros a la empresa por type de carro
void CarRental::addCarsInventaryType()
{
    string type;
    string brand, color;
    float perform;
    uint price;
    bool flag = true;
    cout << "Hola jefe, por favor escribe que tipo de carro deseas agregar al inventario: suv, lujo o todoterreno: " << endl
         << endl;
    while (flag)
    {
        cin >> type;
        if (type == "suv")
        {
            cout << "Escribe una marca de SUV: " << endl;
            cin >> brand;
            cout << "Escribe el rendimiento del SUV: " << endl;
            cin >> perform;
            cout << "Escribe el color del SUV: " << endl;
            cin >> color;
            cout << "Escribe el price del SUV para su renta: " << endl;
            cin >> price;
            carInventary->constructSuv(brand, perform, color, price);
            flag = false;
        }
        if (type == "todoterreno")
        {
            cout << "Escribe una marca de todoTerreno: " << endl;
            cin >> brand;
            cout << "Escribe el rendimiento del todoTerreno: " << endl;
            cin >> perform;
            cout << "Escribe el color del todoTerreno: " << endl;
            cin >> color;
            cout << "Escribe el precio del todoTerreno para su renta: " << endl;
            cin >> price;
            carInventary->constructAllTerrain(brand, perform, color, price);
            flag = false;
        }
        if (type == "lujo")
        {
            cout << "Escribe una marca de lujo: " << endl;
            cin >> brand;
            cout << "Escribe el rendimiento del lujo: " << endl;
            cin >> perform;
            cout << "Escribe el color del lujo: " << endl;
            cin >> color;
            cout << "Escribe el precio del lujo para su renta: " << endl;
            cin >> price;
            carInventary->constructLuxury(brand, perform, color, price);
            flag = false;
        }
        else
        {
            cout << "Por favor escribe 'suv', 'lujo' o 'todoterreno': " << endl;
            flag = true;
        }
    }
};

// Mostrar inventario actual de carros
void CarRental::showCarsInventary()
{
    carInventary->showCars();
};

// Reservar carro
void CarRental::bookCars()
{
    bool flag = true;
    while (flag)
    {
        if (carInventary->showByPrice() == true)
        {
            flag = false;
        }
        else
            flag = true;
    }
};
#endif
