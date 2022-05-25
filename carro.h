/*
Proyecto hecho por Daniel Gutiérrez Gómez
A01068056
Esta es el documento de la clase carro
hereda a 3 subclases: Suv, TodoTerreno, Lujo
*/
#ifndef CARRO_H_
#define CARRO_H_
#include <string>

using namespace std;
class Carro
{

protected: // Atributos que se usarán en clases heredadas
    string marca;
    float rendimiento;
    string color;
    bool transmision; // True si es automático
    uint asientos;
    uint id;
    string tipo;

public:
    Carro() : marca(""), rendimiento(0.0), color(""),
              transmision(false), asientos(0), id(0), tipo(""){}; // Constructor por default

    Carro(string marca_s, float rendimiento_s, string color_s,
          bool transmision_s, uint asientos_s, uint id_s, string tipo_s) : marca(marca_s), rendimiento(rendimiento_s), color(color_s),
                                                                           transmision(transmision_s), asientos(asientos_s), id(id_s), tipo(tipo_s){};
    virtual ~Carro(){}; // Destructor de clase carro
    string getMarca() { return marca; }
    float getRendim() { return rendimiento; }
    string getColor() { return color; }
    bool getTransm() { return transmision; }
    uint getAsientos() { return asientos; }
    uint getId() { return id; }
    string getTipo() { return tipo; }
    virtual uint getPrecio() = 0;
    void setPrecio(uint precio){}; // Sobreescritura de setPrecio
    void setMarca(string marca_s) { marca = marca_s; }
    void setRendim(float rendim_s) { rendimiento = rendim_s; }
    void setColor(string color_s) { color = color_s; }
    void setTransm(bool transmision_s) { transmision = transmision_s; }
};

class Suv : public Carro
{

private:
    uint precio;

public: // marca, rend, color, trans, asientos, id, tipo
    Suv() : Carro("", 0.0, "", true, 4, 0, "suv"){};
    Suv(string marca, float rendimiento, string color, uint id, uint precio_s) : Carro(marca, rendimiento, color, true, 4, id, "suv"), precio(precio_s){};
    ~Suv(){};
    // Sobreescritura de setPrecio
    void setPrecio(uint precio_s) { precio = precio_s; }
    uint getPrecio() { return precio; }
};

class TodoTerreno : public Carro
{

private:
    uint precio;

public: // marca, rend, color, trans, asientos, id, tipo
    TodoTerreno() : Carro("", 0.0, "", false, 5, 0, "todoterreno"){};
    TodoTerreno(string marca, float rendimiento, string color, uint id, uint precio_s) : Carro(marca, rendimiento, color, false, 5, id, "todoterreno"), precio(precio_s){};
    ~TodoTerreno(){};                                    // Destructor de TodoTerreno
    void setPrecio(uint precio_s) { precio = precio_s; } // Sobreescritura de setPrecio
    uint getPrecio() { return precio; }
};

class Lujo : public Carro
{

private:
    uint precio;

public: // marca, rend, color, trans, asientos, id, tipo
    Lujo() : Carro("", 0.0, "", true, 2, 0, "lujo"){};
    Lujo(string marca, float rendimiento, string color, uint id, uint precio_s) : Carro(marca, rendimiento, color, true, 2, id, "lujo"), precio(precio_s){};
    ~Lujo(){};                                           // Destructor de Lujo
    void setPrecio(uint precio_s) { precio = precio_s; } // Sobreescritura de setPrecio
    uint getPrecio() { return precio; }
};

#endif