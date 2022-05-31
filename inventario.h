/*
Proyecto hecho por Daniel Gutiérrez Gómez
A01068056
Esta es el documento de la clase inventary::
composición con Car hereda a 3 subclases:
Suv, allTerrain, Luxury
*/
#ifndef INVENTARIO_H_
#define INVENTARIO_H_
#include <string>
#include <vector>
#include <iostream>
#include "carro.h"

using namespace std;

// Constante de tamaño máx de arreglo
const int num_max_cars = 1000;
class Inventary
{
    // Variable privada
private:
    uint id;

    // Declaro métodos públicos y delcaro el apuntador de tipo Carro para usar polimorfismo
    // También constructor por default
public:
    Car *cars[num_max_cars];
    Inventary() : id(0){};
    void addCars();
    bool searchCar(string brand, float performance, string color, bool transmission, uint seats, string type, uint price);
    void countCarsbyType();
    void deleteCar(uint iden);
    void changePrices();
    void showCars();
    bool showByPrice();
    uint identifier(int num);
    void constructSuv(string brand, float performance, string color, uint price);
    void constructLuxury(string brand, float performance, string color, uint price);
    void constructAllTerrain(string brand, float performance, string color, uint price);
    void showCar(int iterator);
};

// Método que crea SUV con memoria dinámica
// se crea el obeto en tiempo de ejecución para usar polimorfismo
// en otros métodos
void Inventary::constructSuv(string brand, float performance, string color, uint price)
{
    cars[id] = new Suv(brand, performance, color, id, price);
    id++;
    cout << "Se ha agregado al inventario tu 'SUV': " << endl;
    Inventary::showCars();
};

// Método que crea Luxury con memoria dinámica
// se crea el obeto en tiempo de ejecución para usar polimorfismo
// en otros métodos
void Inventary::constructLuxury(string brand, float performance, string color, uint price)
{
    cars[id] = new Luxury(brand, performance, color, id, price);
    id++;
    cout << "Se ha agregado al inventario tu 'Luxury': " << endl;
    Inventary::showCars();
};

// Método que crea allTerrain con memoria dinámica
// se crea el obeto en tiempo de ejecución para usar polimorfismo
// en otros métodos
void Inventary::constructAllTerrain(string brand, float performance, string color, uint price)
{
    cars[id] = new allTerrain(brand, performance, color, id, price);
    id++;

    cout << "Se ha agregado al inventario tu 'allTerrain': " << endl;
    Inventary::showCars();
};

// Método que regresa true si de un input se recibe un price
// disponible del inventary
bool Inventary::showByPrice()
{
    float perform;
    string brand, color;
    uint price, idDel;
    bool flag = false;
    cout << "Estos son los datos de los carros disponibles para que puedas reservarlos: " << endl;
    for (int i = 0; i < id; i++)
    {
        cout << "Precio: " << cars[i]->getPrice() << " color: " << cars[i]->getColor() << " marca: " << cars[i]->getBrand() << " rendimiento: " << cars[i]->getPerform() << " asientos: " << cars[i]->getSeats() << endl
             << endl;
    }
    cout << "Ahora por favor, escribe el precio del carro que quieres: " << endl;
    cin >> price;
    cout << "Ahora por favor, escribe el color del carro que quieres: " << endl;
    cin >> color;
    cout << "Ahora por favor, escribe la marca del carro que quieres: " << endl;
    cin >> brand;
    cout << "Ahora por favor, escribe el rendimiento del carro que quieres: " << endl;
    cin >> perform;
    for (int i = 0; i < id; i++)
    {
        if (cars[i]->getPrice() == price && cars[i]->getColor() == color && cars[i]->getBrand() == brand)
        {
            Inventary::showCar(i);
            idDel = Inventary::identifier(i);
            Inventary::deleteCar(idDel);
            flag = true;
        }
        else
        {
            cout << "No has escrito bien todos los datos...." << endl;
            flag = false;
            break;
        }
    }
    if (flag == true)
        return true;
    else
        return false;
};

// Método que recibe ID de iteración de método
// en el que se haya encontrado un price del input
// para poder eliminar ese car de acuerdo a ese ID
// llamando al método eliminar car y el destructor
uint Inventary::identifier(int num)
{
    return cars[num]->getId();
};

// Creación de cars en memoria dinámica con "new"
// que apunta a las clases heredadas de car
// se crea el obeto en tiempo de ejecución para usar polimorfismo
// en otros métodos
void Inventary::addCars()
{
    cars[id] = new Luxury("Audi", 13.2, "rojo", id, 1900);
    id++;
    cars[id] = new Luxury("Audi", 13.2, "azul", id, 1900);
    id++;
    cars[id] = new Luxury("Audi", 13.2, "negro", id, 1900);
    id++;
    cars[id] = new Luxury("Audi", 13.2, "blanco", id, 1900);
    id++;
    cars[id] = new Suv("Audi", 10.2, "roja", id, 2200);
    id++;
    cars[id] = new Suv("Audi", 10.2, "azul", id, 2200);
    id++;
    cars[id] = new Suv("Mazda", 14.2, "roja", id, 2000);
    id++;
    cars[id] = new Suv("Mazda", 14.2, "gris", id, 2000);
    id++;
    cars[id] = new allTerrain("Jeep", 13.3, "roja", id, 2300);
    id++;
    cars[id] = new allTerrain("Jeep", 13.3, "verde", id, 2300);
    id++;
    cars[id] = new allTerrain("Ford", 13.3, "azul", id, 2200);
    id++;
    cars[id] = new allTerrain("Ford", 13.3, "gris", id, 2200);
    id++;
};
// Iteración en inventario de carros para ver si coincide con
// tipos de datos recibidos
bool Inventary::searchCar(string brand, float performance, string color, bool transmission, uint seats, string type, uint price)
{
    bool flag = false;
    for (int i = 0; i < id; i++)
    {
        if (cars[i]->getPerform() == performance && cars[i]->getBrand() == brand && cars[i]->getColor() == color && cars[i]->getTransm() == transmission && cars[i]->getType() == type && cars[i]->getPrice() == price)
            flag = true;
    }
    if (flag == true)
        return true;
    else
        return false;
};

// Método que imprime la cantidad de carros por tipo
// utilizando apuntadores a otros métodos
void Inventary::countCarsbyType()
{
    uint suv = 0;
    uint all_terrain = 0;
    uint luxury = 0;
    for (int i = 0; i < id; i++)
    {
        if (cars[i]->getType() == "suv")
            suv++;
        if (cars[i]->getType() == "allterrain")
            all_terrain++;
        if (cars[i]->getType() == "luxury")
            luxury++;
    }
    cout << "Hay: " << suv << " carros type 'SUV' en el inventario." << endl;
    cout << "Hay: " << all_terrain << " caros type 'allTerrain' en el inventario." << endl;
    cout << "Hay: " << luxury << " carros type 'luxury' en el inventario." << endl;
};

// Se elimina un car cada vez que se reserva
// esto con el ID y se llama al destructor
// de Car
void Inventary::deleteCar(uint iden)
{
    for (int i = 0; i < id; i++)
    {
        if (cars[i]->getId() == iden)
        {
            delete cars[i];
        }
    }
    id--;
};

// Método que cambia el price de algún carro
// por las especificaciones
void Inventary::changePrices()
{
    string type, color, brand;
    uint new_price, price, seats;
    float performance;
    bool transmission;
    cout << "Por favor escribe las especificaciones del tipo de carro que deseas cambiarle el precio: " << endl;
    cout << "El tipo: " << endl;
    cin >> type;
    cout << "El color: " << endl;
    cin >> color;
    cout << "El precio: " << endl;
    cin >> price;
    cout << "La marca: " << endl;
    cin >> brand;
    cout << "El rendimiento: " << endl;
    cin >> performance;
    cout << "La transmisión: (0 si es manual 1 si es automático) " << endl;
    cin >> transmission;
    cout << "Los asientos: " << endl;
    cin >> seats;
    cout << "Ahora, el nuevo precio: " << endl;
    cin >> new_price;

    for (int i = 0; i < id; i++)
    {
        if (Inventary::searchCar(brand, performance, color, transmission, seats, type, price) == true)
        {
            cars[i]->setPrice(new_price);
        }
        else
        {
            cout << "No has escrito bien los datos." << endl
                 << endl;
        }
    }
};

// Método que muestra todas las características
// de los carros disponibles en el inventario
void Inventary::showCars()
{
    for (int i = 0; i < id; i++)
    {
        if (cars[i]->getTransm() == 0)
        {
            cout << "Marca: " << cars[i]->getBrand() << " rendimiento: " << cars[i]->getPerform() << " color: "
                 << cars[i]->getColor() << " transmisión: "
                 << "manual"
                 << " tipo: "
                 << cars[i]->getType() << " precio: " << cars[i]->getPrice() << " asientos: " << cars[i]->getSeats() << " id: " << cars[i]->getId() << endl;
        }
        else
        {
            cout << "Marca: " << cars[i]->getBrand() << " rendimiento: " << cars[i]->getPerform() << " color: "
                 << cars[i]->getColor() << " transmisión: "
                 << "manual"
                 << " tipo: "
                 << cars[i]->getType() << " precio: " << cars[i]->getPrice() << " asientos: " << cars[i]->getSeats() << " id: " << cars[i]->getId() << endl;
        }
    }
};
// Método que muestra todas las características
// del carro en cierto índice (se utilizó para lógica de otro método: showByPrice())
void Inventary::showCar(int i)
{
    cout << "Se te ha reservado tu carro con las siguientes características: " << endl;
    if (cars[i]->getTransm() == 0)
    {
        cout << "Marca: " << cars[i]->getBrand() << " rendimiento: " << cars[i]->getPerform() << " color: "
             << cars[i]->getColor() << " transmisión: "
             << "manual"
             << " tipo: "
             << cars[i]->getType() << " precio: " << cars[i]->getPrice() << " asientos: " << cars[i]->getSeats() << " id: " << cars[i]->getId() << endl;
    }
    else
    {
        cout << "Marca: " << cars[i]->getBrand() << " rendimiento: " << cars[i]->getPerform() << " color: "
             << cars[i]->getColor() << " transmisión: "
             << "manual"
             << " tipo: "
             << cars[i]->getType() << " precio: " << cars[i]->getPrice() << " asientos: " << cars[i]->getSeats() << " id: " << cars[i]->getId() << endl;
    }
};

#endif
