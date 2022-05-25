/*
Proyecto hecho por Daniel Gutiérrez Gómez
A01068056
Esta es el documento de la clase inventario::
composición con Carro hereda a 3 subclases:
Suv, TodoTerreno, Lujo
*/
#ifndef INVENTARIO_H_
#define INVENTARIO_H_
#include <string>
#include <vector>
#include <iostream>
#include "carro.h"

using namespace std;

const int num_max_carros = 1000;
class Inventario
{
private:
    uint id;

public:
    Carro *carros[num_max_carros];
    Inventario() : id(0){};
    void agregarCarros();
    bool buscarCarro(string marca, float rendimiento, string color, bool transmision, uint asientos, string tipo, uint precio);
    void contarCarrosPorTipo();
    void eliminarCarro(uint iden);
    void cambiarPrecios();
    void mostrarCarros();
    bool mostrarPorPrecio();
    uint identificador(int num);
    void construirSuv(string marca, float rendimiento, string color, uint precio);
    void construirLujo(string marca, float rendimiento, string color, uint precio);
    void construirTodoTerreno(string marca, float rendimiento, string color, uint precio);
};

void Inventario::construirSuv(string marca, float rendimiento, string color, uint precio)
{
    carros[id] = new Suv(marca, rendimiento, color, id, precio);
    id++;
};

void Inventario::construirLujo(string marca, float rendimiento, string color, uint precio)
{
    carros[id] = new Lujo(marca, rendimiento, color, id, precio);
    id++;
};

void Inventario::construirTodoTerreno(string marca, float rendimiento, string color, uint precio)
{
    carros[id] = new TodoTerreno(marca, rendimiento, color, id, precio);
    id++;
};

bool Inventario::mostrarPorPrecio()
{
    uint precio, idElim;
    bool flag = false;
    cout << "Estos son los precios de los carros disponibles: " << endl;
    for (int i = 0; i < id; i++)
    {
        carros[i]->getPrecio();
    }
    cout << "Ahora por favor, escribe el precio del carro que quieres: " << endl;
    cin >> precio;
    for (int i = 0; i < id; i++)
    {
        if (carros[i]->getPrecio() == precio)
        {
            idElim = Inventario::identificador(i);
            Inventario::eliminarCarro(idElim);
            flag = true;
        }
    }
    if (flag == true)
        return true;
    else
        return false;
};

uint Inventario::identificador(int num)
{
    return carros[num]->getId();
}

void Inventario::agregarCarros()
{
    carros[id] = new Lujo("Audi", 13.2, "rojo", id, 1900);
    id++;
    carros[id] = new Lujo("Audi", 13.2, "azul", id, 1900);
    id++;
    carros[id] = new Lujo("Audi", 13.2, "negro", id, 1900);
    id++;
    carros[id] = new Lujo("Audi", 13.2, "blanco", id, 1900);
    id++;
    carros[id] = new Suv("Audi", 10.2, "roja", id, 2200);
    id++;
    carros[id] = new Suv("Audi", 10.2, "azul", id, 2200);
    id++;
    carros[id] = new Suv("Mazda", 14.2, "roja", id, 2000);
    id++;
    carros[id] = new Suv("Mazda", 14.2, "gris", id, 2000);
    id++;
    carros[id] = new TodoTerreno("Jeep", 13.3, "roja", id, 2300);
    id++;
    carros[id] = new TodoTerreno("Jeep", 13.3, "verde", id, 2300);
    id++;
    carros[id] = new TodoTerreno("Ford", 13.3, "azul", id, 2200);
    id++;
    carros[id] = new TodoTerreno("Ford", 13.3, "gris", id, 2200);
    id++;
};
// Iteración en inventario de carros para ver si coincide con
// tipos de datos recibidos
bool Inventario::buscarCarro(string marca, float rendimiento, string color, bool transmision, uint asientos, string tipo, uint precio)
{
    bool flag = false;
    for (int i = 0; i < id; i++)
    {
        if (carros[i]->getRendim() == rendimiento && carros[i]->getMarca() == marca && carros[i]->getColor() == color && carros[i]->getTransm() == transmision && carros[i]->getTipo() == tipo && carros[i]->getPrecio() == precio)
            flag = true;
    }
    if (flag == true)
        return true;
    else
        return false;
};

// Método que imprime la cantidad de carros por tipo
// utilizando apuntadores a métodos por composición
void Inventario::contarCarrosPorTipo()
{
    uint suv = 0;
    uint todo_terreno = 0;
    uint lujo = 0;
    for (int i = 0; i < id; i++)
    {
        if (carros[i]->getTipo() == "suv")
            suv++;
        if (carros[i]->getTipo() == "todoterreno")
            todo_terreno++;
        if (carros[i]->getTipo() == "lujo")
            lujo++;
    }
    cout << "Hay: " << suv << " carros tipo 'SUV' en el inventario." << endl;
    cout << "Hay: " << todo_terreno << " carros tipo 'todoTerreno' en el inventario." << endl;
    cout << "Hay: " << lujo << " carros tipo 'lujo' en el inventario." << endl;
};

void Inventario::eliminarCarro(uint iden)
{
    for (int i = 0; i < id; i++)
    {
        if (carros[i]->getId() == iden)
        {
            delete carros[i];
        }
    }
}

void Inventario::cambiarPrecios()
{
    string tipo;
    int precio_n, ptr_n, ptr_v;
    cout << "Por favor escribe el tipo de carro que deseas cambiarle el precio: " << endl;
    cin >> tipo;
    cout << endl
         << "Ahora, el nuevo precio: " << endl;
    cin >> precio_n;
    for (int i = 0; i < id; i++)
    {
        if (carros[i]->getTipo() == tipo)
        {
            carros[i]->setPrecio(precio_n);
        }
    }
};

void Inventario::mostrarCarros()
{
    for (int i = 0; i < id; i++)
    {
        if (carros[i]->getTransm() == 0)
        {
            cout << "Marca: " << carros[i]->getMarca() << " rendimiento: " << carros[i]->getRendim() << " color: "
                 << carros[i]->getColor() << " transmisión: "
                 << "manual"
                 << " tipo: "
                 << carros[i]->getTipo() << " precio: " << carros[i]->getPrecio() << " id: " << carros[i]->getId() << endl;
        }
        else
        {
            cout << "Marca: " << carros[i]->getMarca() << " rendimiento: " << carros[i]->getRendim() << " color: "
                 << carros[i]->getColor() << " transmisión: "
                 << "automático"
                 << " tipo: "
                 << carros[i]->getTipo() << " precio: " << carros[i]->getPrecio() << " id: " << carros[i]->getId() << endl;
        }
    }
};
#endif
// int main()
// {
//      Lujo audi("Audi", 13.2, "rojo", 0, 1900);
//      cout << audi.getAsientos();

//     Carro *cptr;
//     Lujo audi("Audi", 13.2, "rojo", 0, 1900);
//     cptr = &audi;

//     cout << cptr->getPrecio() << endl;
//     audi.setPrecio(2900);
//     cout << cptr->getPrecio() << endl;

//     Carro *cptr2;
//     Lujo audi2("Audi", 10.1, "negro", 1, 2900);
//     cptr2 = &audi2;

//     cout << cptr2->getRendim() << endl;
// }
