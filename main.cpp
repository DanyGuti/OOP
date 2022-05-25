#include <iostream>
#include "CarRental.h"

using namespace std;

int main()
{
    CarRental *Alamos = new CarRental();
    Alamos->añadirCarros();
    Alamos->muestraCarros();
    Alamos->añadirCarrosTipo();
    Alamos->añadirCarrosTipo();
    Alamos->reservarCarroPrecio();
    Alamos->muestraCarros();
};