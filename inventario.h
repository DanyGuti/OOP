/*
 *
 * Proyecto hecho por Daniel Gutiérrez Gómez
 * A01068056
 * Esta es el documento de la clase inventary::
 * composición con Car hereda a 3 subclases:
 * Suv, allTerrain, Luxury
 * Clase que sirve para hacer manipulación de
 * los objetos de tipo Carro y sus hijos
 * (Suv, allTerrain, Luxury)
 */
#ifndef INVENTARIO_H_
#define INVENTARIO_H_
#include <string>
#include <vector>
#include <iostream>
#include "carro.h" // Biblioteca con los objetos a usar

using namespace std;

// Constante de tamaño máx de arreglo
const int num_max_cars = 100;

// Declaración de clase Inventary
class Inventary
{
    // Variable privada de instancia
private:
    unsigned int id;
    /*
     * Declaro métodos públicos y declaro el apuntador de tipo Carro para
     * acceder a los métodos de Car con memoria dinámica y apuntadores.
     */
public:
    Car *cars[num_max_cars];
    Inventary() : id(0){}; // Constructor por default
    void addCars();
    bool searchCar(string brand, float performance, string color, bool transmission, unsigned int seats, string type, unsigned int price);
    void countCarsbyType();
    void deleteCar(unsigned int iden);
    void changePrices();
    void showCars();
    bool showByPrice();
    unsigned int identifier(int num);
    void constructSuv(string brand, float performance, string color, unsigned int price);
    void constructLuxury(string brand, float performance, string color, unsigned int price);
    void constructAllTerrain(string brand, float performance, string color, unsigned int price);
    void showCar(int iterator);
};

/**
 * Método que crea SUV con memoria dinámica y hace append
 * en cars[].
 * Se crea el objeto en tiempo de ejecución para usar polimorfismo
 * en otros métodos de esta misma clase Inventary.
 *
 * @param string marca
 * @param float rendimiento
 * @param string color
 * @param unsignedint precio
 * @return
 */
void Inventary::constructSuv(string brand, float performance, string color, unsigned int price)
{
    cars[id] = new Suv(brand, performance, color, id, price);
    id++;
    cout << "Se ha agregado al inventario tu 'SUV': " << endl;
    Inventary::showCars();
};

/**
 * Método que crea Luxury con memoria dinámica y hace append
 * en cars[].
 * Se crea el objeto en tiempo de ejecución para usar polimorfismo
 * en otros métodos.
 *
 * @param string marca
 * @param float rendimiento
 * @param string color
 * @param unsignedint precio
 * @return
 */
void Inventary::constructLuxury(string brand, float performance, string color, unsigned int price)
{
    cars[id] = new Luxury(brand, performance, color, id, price);
    id++;
    cout << "Se ha agregado al inventario tu 'Luxury': " << endl;
    Inventary::showCars();
};

/**
 * Método que crea allTerrain con memoria dinámica y hace append
 * en cars[].
 * Se crea el objeto en tiempo de ejecución para usar polimorfismo
 * en otros métodos.
 *
 * @param string marca
 * @param float rendimiento
 * @param string color
 * @param unsignedint precio
 * @return
 */
void Inventary::constructAllTerrain(string brand, float performance, string color, unsigned int price)
{
    cars[id] = new allTerrain(brand, performance, color, id, price);
    id++;

    cout << "Se ha agregado al inventario tu 'allTerrain': " << endl;
    Inventary::showCars();
};

/**
 * Método que enseña los carros
 * y se utiliza en método bookCars()
 * para poder reservar un carro con
 * ciertas especificaciones
 * Iteración de cars[] e imprime especificaciones.
 *
 * @param
 * @return bool si se hace match con especificaciones dadas
 * por usuario
 */
bool Inventary::showByPrice()
{
    float perform;
    string brand, color, type;
    unsigned int price, idDel, seats;
    bool flag = false;
    bool transm;
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
        if (cars[i]->getPrice() == price && cars[i]->getColor() == color && cars[i]->getBrand() == brand && cars[i]->getPerform() == perform)
        {
            Inventary::showCar(i);
            idDel = Inventary::identifier(i);
            Inventary::deleteCar(idDel);
            flag = true;
        }
    }
    return flag;
};

/**
 * Método que recibe ID de iteración de método
 * showByPrice()
 * en el que se haya encontrado un precio del input
 * coincidiendo con el inventario esto
 * para poder eliminar ese carro de acuerdo a ese ID
 * llamando al método deleteCar y al destructor.
 *
 * @param int numero que coincide con posición de cierto carro
 * especificado
 * @return unsigned int id que sirve para eliminar carro[id]
 */
unsigned int Inventary::identifier(int num)
{
    return cars[num]->getId();
};

/**
 * Creación de cars en memoria dinámica con "new"
 * se hace append en cars[]
 *
 * Genera objetos de tipo Suv, Luxury y allTerrain
 * para poder hacer pruebas (hardcodeado).
 * No se usará en un programa de verdad.
 *
 * @param
 * @return
 */
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

/**
 * Método que busca un carro en cars[]
 * y ve si coincide con datos recibidos.
 *
 * @param string marca
 * @param float rendimiento
 * @param string color
 * @param bool transmisión
 * @param unsignedint asientos
 * @param string tipo: "lujo", "suv", "todoterreno"
 * @param unsigned int precio
 * @return bool que si coincide con valores recibidos regresa true
 */
bool Inventary::searchCar(string brand, float performance, string color, bool transmission, unsigned int seats, string type, unsigned int price)
{
    bool flag = false;
    for (int i = 0; i < id; i++)
    {
        if (cars[i]->getPerform() == performance && cars[i]->getBrand() == brand && cars[i]->getColor() == color && cars[i]->getTransm() == transmission && cars[i]->getType() == type && cars[i]->getPrice() == price && cars[i]->getSeats() == seats)
            flag = true;
    }
    return flag;
};

/**
 * Método que imprime la cantidad de carros
 * dados por tipo: Suv, allTerrainn y Luxury.
 *
 * @param
 * @return
 */
void Inventary::countCarsbyType()
{
    unsigned int suv = 0;
    unsigned int all_terrain = 0;
    unsigned int luxury = 0;
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

/**
 * Método que elimina un carro de cars[]
 * se elimina cada vez que se reserva un carro
 * en bookCars().
 * Esto con el ID y se llama al destructor virtual
 * de Car.
 *
 * @param unsignedint identificador dado por método identifier(int num)
 * @return
 */
void Inventary::deleteCar(unsigned int iden)
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

/**
 * Método que cambia el precio de algún carro
 * de cars[] mediante las especificaciones.
 *
 * @param
 * @return
 */
void Inventary::changePrices()
{
    string type, color, brand;
    unsigned int new_price, price, seats;
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
    }
};

/**
 * Método que muestras las características
 * de los carros disponibles en inventario (cars[]).
 *
 * @param
 * @return
 */
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
                 << "automático"
                 << " tipo: "
                 << cars[i]->getType() << " precio: " << cars[i]->getPrice() << " asientos: " << cars[i]->getSeats() << " id: " << cars[i]->getId() << endl;
        }
    }
};

/**
 * Método que muestras las características
 * del carro disponible en inventario (cars[i])
 * dado un iterador de un for loop.
 *
 * @param
 * @return
 */
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
             << "automático"
             << " tipo: "
             << cars[i]->getType() << " precio: " << cars[i]->getPrice() << " asientos: " << cars[i]->getSeats() << " id: " << cars[i]->getId() << endl;
    }
};

#endif // INVENTARIO_H_