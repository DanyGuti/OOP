/*
 * Proyecto hecho por Daniel Gutiérrez Gómez
 * A01068056
 * Esta es el documento de la clase Car
 * hereda a 3 subclases: Suv, allTerrain, Luxury
 */
#ifndef CARRO_H_
#define CARRO_H_
#include <string>

using namespace std;

// Declaración de clase Car que es abstracta
class Car
{
    // Declaro atributos que se usarán en clases heredadas
protected:
    string brand;
    float performance;
    string color;
    bool transmission; // True si es automático
    unsigned int seats;
    unsigned int id;
    string type;

    // Declaro métodos públicos que tendrá el objeto
public:
    Car() : brand(""), performance(0.0), color(""),
            transmission(false), seats(0), id(0), type(""){}; // Constructor por default

    Car(string brand_s, float performance_s, string color_s,
        bool transmission_s, unsigned int seats_s, unsigned int id_s, string type_s) : brand(brand_s), performance(performance_s), color(color_s),
                                                                                       transmission(transmission_s), seats(seats_s), id(id_s), type(type_s){};
    virtual ~Car(){}; // Destructor de clase car
    string getBrand() { return brand; }
    float getPerform() { return performance; }
    string getColor() { return color; }
    bool getTransm() { return transmission; }
    unsigned int getSeats() { return seats; }
    unsigned int getId() { return id; }
    string getType() { return type; }
    virtual unsigned int getPrice() = 0;             // Método abstracto que es sobreescrito
    virtual void setPrice(unsigned int new_price){}; // Sobreescritura de setPrice con virtual
    void setBrand(string brand_s) { brand = brand_s; }
    void setPerform(float performance_s) { performance = performance_s; }
    void setColor(string color_s) { color = color_s; }
    void setTransm(bool transmission_s) { transmission = transmission_s; }
};

// Declaración de objeto Suv que hereda de Car
class Suv : public Car
{

    // Declaro variables de instancia de objeto
private:
    unsigned int price; // Privado porque cada tipo de carro tiene su precio (si es el mismo carro)

    // Declaro métodos públicos que tendrá el objeto (constructores, destructor y métodos)
public: // brand, rend, color, trans, seats, id, type
    Suv() : Car("", 0.0, "", true, 4, 0, "suv"){};
    Suv(string brand, float performance, string color, unsigned int id, unsigned int price_s) : Car(brand, performance, color, true, 4, id, "suv"), price(price_s){};
    ~Suv(){}; // Destructor de Suv
    /**
     * setPrice() recibe un nuevo precio en método
     * changePrices() de clase Inventary
     * cambia el precio del carro seleccionado
     * es una sobreescritura, pues en clase base
     * no se declaró lo que hacia el método virtual
     *
     * @param unsignedint nuevo_precio
     * @return void solo cambia el precio
     */
    void setPrice(unsigned int new_price) { price = new_price; }

    /**
     * getPrice() método abstracto
     * que permite obtener el precio
     * del carro en el inventario
     *
     * @param
     * @return unsigned int price dado por constructor
     */
    unsigned int getPrice() { return price; }
};

// Declaración de objeto allTerrain que hereda de Car
class allTerrain : public Car
{
    // Declaro variables de instancia de objeto
private:
    unsigned int price; // Privado porque cada tipo de carro tiene su precio (si es el mismo carro)

    // Declaro métodos públicos que tendrá el objeto (constructores y destructor)
public: // brand, rend, color, trans, seats, id, type
    allTerrain() : Car("", 0.0, "", false, 5, 0, "todoterreno"){};
    allTerrain(string brand, float performance, string color, unsigned int id, unsigned int price_s) : Car(brand, performance, color, false, 5, id, "todoterreno"), price(price_s){};
    ~allTerrain(){}; // Destructor de allTerrain
    /**
     * setPrice() recibe un nuevo precio en método
     * changePrices() de clase Inventary
     * cambia el precio del carro seleccionado
     * es una sobreescritura, pues en clase base
     * no se declaró lo que hacia el método virtual
     *
     * @param unsignedint nuevo_precio
     * @return void solo cambia el precio
     */
    void setPrice(unsigned int new_price) { price = new_price; }

    /**
     * getPrice() método abstracto
     * que permite obtener el precio
     * del carro en el inventario
     *
     * @param
     * @return unsigned int price dado por constructor
     */
    unsigned int getPrice() { return price; }
};

// Declaración de objeto Luxury que hereda de Car
class Luxury : public Car
{
    // Declaro variables de instancia de objeto

private:
    unsigned int price; // Privado porque cada tipo de carro tiene su precio (si es el mismo carro)

    // Declaro métodos públicos que tendrá el objeto (constructores y destructor)
public: // brand, rend, color, trans, seats, id, type
    Luxury() : Car("", 0.0, "", true, 2, 0, "lujo"){};
    Luxury(string brand, float performance, string color, unsigned int id, unsigned int price_s) : Car(brand, performance, color, true, 2, id, "lujo"), price(price_s){};
    ~Luxury(){}; // Destructor de Luxury
    /**
     * setPrice() recibe un nuevo precio en método
     * changePrices() de clase Inventary
     * cambia el precio del carro seleccionado
     * es una sobreescritura, pues en clase base
     * no se declaró lo que hacia el método virtual
     *
     * @param unsignedint nuevo_precio
     * @return void solo cambia el precio
     */
    void setPrice(unsigned int new_price) { price = new_price; }

    /**
     * getPrice() método abstracto
     * que permite obtener el precio
     * del carro en el inventario
     *
     * @param
     * @return unsigned int price dado por constructor
     */
    unsigned int getPrice() { return price; }
};
#endif // CARRO_H_