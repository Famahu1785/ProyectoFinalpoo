#ifndef BASE_H
#define BASE_H

#include <vector>
#include <iostream>

// Clase que representa la base del juego Concentrese
// Contiene una matriz de números y otra que indica qué celdas han sido descubiertas
class Base {
private:
    std::vector<std::vector<int>> matriz;       // Matriz que contiene los números de las celdas
    std::vector<std::vector<bool>> descubiertos;// Matriz que indica si una celda ha sido descubierta
    int filas;
    int columnas;

public:
    // Constructor que inicializa la matriz con pares de números del 1 al 20
    // Por defecto se genera una matriz de 5x8 (40 celdas)
    Base(int filas = 5, int columnas = 8);

    // Muestra la matriz en consola
    // Si oculto es true, muestra "X" en celdas no descubiertas
    void mostrar(bool oculto = true) const;

    // Intenta descubrir dos celdas
    // Retorna true si los valores coinciden
    bool descubrir(int f1, int c1, int f2, int c2);

    // Retorna true si la celda en (f, c) ya fue descubierta
    bool estaDescubierto(int f, int c) const;

    // Verifica si una posición dada está dentro de los límites de la matriz
    bool esValida(int f, int c) const;
};

#endif

