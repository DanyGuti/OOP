/*
Proyecto hecho por Daniel Gutiérrez Gómez
A01068056
*/
#include <iostream>
#include <string>
#include "CarRental.h" // Biblioteca con el objeto a usar

using namespace std;

int main()
{
     char s = ' ';                        // Variable para hacer el menú
     string optionCeo = " ";              // Variable para hacer el menú
     CarRental *Alamos = new CarRental(); // Apuntador de tipo CarRental para acceder con apuntadores\
                                          a métodos de CarRental con memoria dinámica

     /*
      * El menú se puede modificar, solamente se pusieron métodos
      * de agregar carros para la demostración (métodos
      * hardcodeados de crear inventario). En realidad, cada
      * vez que se ingresa como CEO se agregan carros al inventario
      * porque se tiene pensado que la empresa ya tiene un inventario
      * por default y que se cambie el precio del carro seleccionado.

      * De igual manera, si quieres reservar un carro, ya se tiene
      * contemplado un inventario de carros al momento de correr
      * el código.
      */
     cout << "----------- Este es el menú de CarRental -----------" << endl
          << endl;
     cout << "    En este programa tienes dos opciones    " << endl
          << endl;
     cout << "    Puedes ser CEO y agregar carros al inventario " << endl
          << "    o cambiar el precio de un carro " << endl
          << endl;
     cout << "    O ser usuario y rentar un carro de los disponibles " << endl
          << endl;
     cout << "    ¡¡¡Por favor teclea muy bien a la hora de Reservar o ser CEO!!!   " << endl
          << endl;
     while (s != 'R' || s != 'C' || s != 'S')
     {
          cout << "   Teclea R si quieres rentar, C si eres CEO o S para salir   " << endl
               << endl;
          cin >> s;
          if (s == 'R')
          {
               cout << "Nota, a la hora de reservar carro se muy específico y teclea bien el carro que quieres" << endl
                    << endl;
               cout << "¡Escribiendo bien la marca, el rendimiento y el color por favor!" << endl
                    << endl;
               Alamos->addCarsInventary();
               cout << endl
                    << endl;
               Alamos->bookCars();
               // REVISAR CON PROFE Alamos->showCarsInventary();
               break;
          }
          else if (s == 'C')
          {
               while (optionCeo != "stack" || optionCeo != "uno" || optionCeo != "cambiar")
               {
                    cout << "¿Deseas agregar carros por tipo uno por uno? ¿O carros por stack?, o ¿ver el inventario?" << endl;
                    cout << "O, ¿cambiar el precio de un carro?" << endl
                         << endl;
                    cout << "Teclea 'uno' si quieres agregar uno por uno, o 'stack' si deseas agregar por stack, o 'cambiar' para cambiar precio de carros " << endl;
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
                         Alamos->addCarsInventary();
                         Alamos->addCarsInventaryType();
                         cout << "Vuelve pronto CEO..." << endl
                              << endl;
                         break;
                    }
                    else if (optionCeo == "cambiar")
                    {
                         Alamos->addCarsInventary();
                         Alamos->showCarsInventary();
                         Alamos->changePrice();
                         cout << "Se han guardado los cambios, vuelve pronto CEO" << endl
                              << endl;
                         Alamos->showCarsInventary();
                         break;
                    }
                    else
                    {
                         cout << "Solo puedes escribir las opciones antes dichas. " << endl;
                         cout << " 'uno' o 'stack' " << endl;
                         continue;
                    }
                    break;
               }
               break;
          }
          else if (s == 'S')
          {
               cout << "GRACIASSS POR HABER ENTRADO A CAR RENTAL, VUELVE PRONTOOO. " << endl
                    << endl;
               break;
          }
          else
          {
               cout << "Solo puedes escribir las opciones de: 'R, 'S' o 'C' " << endl;
               continue;
          }
     };
};