/*
Proyecto hecho por Daniel Gutiérrez Gómez
A01068056
*/
#include <iostream>
#include <string>
#include "CarRental.h"

using namespace std;

int main()
{
    char s = ' ';                        // Variable para hacer el menú
    string optionCeo = " ";              // Variable para hacer el menú
    CarRental *Alamos = new CarRental(); // Apuntador de tipo CarRental para utilizar polimorfismo
    cout << "----------- Este es el menú de CarRental -----------" << endl
         << endl;
    cout << "    En este programa tienes dos opciones    " << endl
         << endl;
    cout << "    Puedes ser CEO y agregar carros al inventario " << endl
         << endl;
    cout << "    O ser usuario y rentar un carro de los disponibles " << endl
         << endl;
    while (s != 'R' || s != 'C' || s != 'S')
    {
        cout << "   Teclea R si quieres rentar, C si eres CEO o S para salir   " << endl
             << endl;
        cin >> s;
        if (s == 'R')
        {
            cout << "Parece que quieres rentar un carro, este es nuestro inventario actual: " << endl
                 << endl;
            cout << "Nota, a la hora de reservar carro se muy específico y teclea bien el carro que quieres" << endl
                 << endl;
            cout << "¡Escribiendo bien la marca, el rendimiento y el color por favor!" << endl
                 << endl;
            Alamos->addCarsInventary();
            Alamos->showCarsInventary();
            Alamos->bookCars();
            cout << endl
                 << endl;
            Alamos->showCarsInventary();
            break;
        }
        else if (s == 'C')
        {
            while (optionCeo != "stack" || optionCeo != "uno")
            {
                cout << "¿Deseas agregar carros por tipo uno por uno? ¿O carros por stack?, o ¿ver el inventario?" << endl
                     << endl;
                cout << "Teclea 'uno' si quieres agregar uno por uno, o 'stack' si deseas agregar por stack: " << endl;
                cin >> optionCeo;
                if (optionCeo == "stack")
                {
                    Alamos->addCarsInventary();
                    Alamos->showCarsInventary();
                    cout << "Vuelve pronto CEO..." << endl
                         << endl;
                    break;
                }
                else if (optionCeo == "uno")
                {
                    Alamos->addCarsInventaryType();
                    cout << "Vuelve pronto CEO..." << endl
                         << endl;
                    break;
                }
                else
                {
                    cout << "Solo puedes escribir las opciones antes dichas. " << endl;
                    cout << " 'uno' o 'stack' " << endl;
                    continue;
                }
            }
            break;
        }
        else if (s == 'S')
        {
            cout << "GRACIASSS POR HABER ENTRADO A CARENTAL, VUELVE PRONTOOO. " << endl
                 << endl;
            break;
        }
        else
        {
            cout << "Solo puedes escribir las opciones de: 'R, 'S' o 'C' " << endl;
            continue;
        }
    }
};