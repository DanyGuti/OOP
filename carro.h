/*
Proyecto hecho por Daniel Gutiérrez Gómez
A01068056
Esta es el documento de la clase Car
hereda a 3 subclases: Suv, allTerrain, Luxury
*/
#ifndef CARRO_H_
#define CARRO_H_
#include <string>

using namespace std;
class Car
{

protected: // Atributos que se usarán en clases heredadas
    string brand;
    float performance;
    string color;
    bool transmission; // True si es automático
    uint seats;
    uint id;
    string type;

public:
    Car() : brand(""), performance(0.0), color(""),
            transmission(false), seats(0), id(0), type(""){}; // Constructor por default

    Car(string brand_s, float performance_s, string color_s,
        bool transmission_s, uint seats_s, uint id_s, string type_s) : brand(brand_s), performance(performance_s), color(color_s),
                                                                       transmission(transmission_s), seats(seats_s), id(id_s), type(type_s){};
    virtual ~Car(){}; // Destructor de clase car
    string getBrand() { return brand; }
    float getPerform() { return performance; }
    string getColor() { return color; }
    bool getTransm() { return transmission; }
    uint getSeats() { return seats; }
    uint getId() { return id; }
    string getType() { return type; }
    virtual uint getPrice() = 0; // Método abstracto que es sobreescrito
    void setPrice(uint price){}; // Sobreescritura de setPrice
    void setBrand(string brand_s) { brand = brand_s; }
    void setPerform(float performance_s) { performance = performance_s; }
    void setColor(string color_s) { color = color_s; }
    void setTransm(bool transmission_s) { transmission = transmission_s; }
};

class Suv : public Car
{

private:
    uint price;

public: // brand, rend, color, trans, seats, id, type
    Suv() : Car("", 0.0, "", true, 4, 0, "suv"){};
    Suv(string brand, float performance, string color, uint id, uint price_s) : Car(brand, performance, color, true, 4, id, "suv"), price(price_s){};
    ~Suv(){};                                        // Destructor de Suv
    void setPrice(uint price_s) { price = price_s; } // Sobreescritura de setPrice
    uint getPrice() { return price; }                // Método abstracto sobreescrito
};

class allTerrain : public Car
{

private:
    uint price;

public: // brand, rend, color, trans, seats, id, type
    allTerrain() : Car("", 0.0, "", false, 5, 0, "todoterreno"){};
    allTerrain(string brand, float performance, string color, uint id, uint price_s) : Car(brand, performance, color, false, 5, id, "todoterreno"), price(price_s){};
    ~allTerrain(){};                                 // Destructor de allTerrain
    void setPrice(uint price_s) { price = price_s; } // Sobreescritura de setPrice
    uint getPrice() { return price; }                // Método abstracto sobreescrito
};

class Luxury : public Car
{

private:
    uint price;

public: // brand, rend, color, trans, seats, id, type
    Luxury() : Car("", 0.0, "", true, 2, 0, "lujo"){};
    Luxury(string brand, float performance, string color, uint id, uint price_s) : Car(brand, performance, color, true, 2, id, "lujo"), price(price_s){};
    ~Luxury(){};                                     // Destructor de Luxury
    void setPrice(uint price_s) { price = price_s; } // Sobreescritura de setPrice
    uint getPrice() { return price; }                // Método abstracto sobreescrito
};

#endif