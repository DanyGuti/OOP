# POO (Programación Orientada a Objetos) Proyecto 

# Renta de Carros
Con este proyecto se pretende construir una empresa que renta
carros, esto apartir de cierto inventario de carros, carros 
"construidos" por tipo: Lujo, Suv y TodoTerreno.

El funcionamiento que se tiene (desde punto de vista User), 
es básicamente el poder buscar un carro en base a su precio
y poder reservarlo, esto después de haber enseñado al usuario
el inventario de carros, mostrando las características más importantes 
del carro como: color, marca, transmisión, número de asientos,
rendimiento y su ID o placa.

El funcionamiento que se tiene desde el punto de vista CEO
es el de poder agregar carros "uno por uno": dependiendo
del tipo, o por stack, con las características antes
mencionadas, además se puede cambiar el precio de un carro
pidiendo las características de un carro en el inventario.

# Correr el programa
Para poder correr el programa, se deben de descargar o 
git pull de: "carro.h", "inventario.h", "CarRental.h" y 
"main.cpp", se puede correr con c++11 en adelante
(de preferencia c++11):  
# 
g++ -std=c++11 main.cpp -o "nombre de ejecutable"
#
./"nombre de ejecutable"
