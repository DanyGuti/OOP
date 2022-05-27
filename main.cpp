/*
Proyecto hecho por Daniel Gutiérrez Gómez
A01068056
*/
#include <iostream>
#include "CarRental.h"

using namespace std;

int main()
{
    CarRental *Alamos = new CarRental();
    Alamos->añadirCarros();
    Alamos->muestraCarros();
    Alamos->añadirCarrosTipo();
    Alamos->reservarCarro();
    cout << endl
         << endl;
    Alamos->muestraCarros();
    Alamos->añadirCarrosTipo();
    Alamos->muestraCarros();
};