#ifndef BASE_H
#define BASE_H

#include <vector>
#include <iostream>

class Base {
private:
    std::vector<std::vector<int>> matriz; // Matriz que contiene los números de las celdas
    std::vector<std::vector<bool>> descubiertos;// Matriz que indica si una celda ha sido descubierta
    int filas, columnas;

public:
    Base(int filas = 5, int columnas = 8); // 40 celdas para 20 pares
    void mostrar(bool oculto = true) const;// Muestra la matriz, ocultando o mostrando los números según el parámetro
    bool descubrir(int f1, int c1, int f2, int c2);// Descubre dos celdas y verifica si son iguales
    bool estaDescubierto(int f, int c) const;// Verifica si una celda ha sido descubierta
    bool esValida(int f, int c) const; // Verifica si las coordenadas están dentro de los límites de la matriz
};

#endif
