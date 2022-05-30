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
    Alamos->addCarsInventary();
    Alamos->showCarsInventary();
    Alamos->addCarsInventaryType();
    Alamos->bookCars();
    cout << endl
         << endl;
    Alamos->addCarsInventary();
    Alamos->showCarsInventary();
};