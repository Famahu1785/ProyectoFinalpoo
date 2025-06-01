#include "include/Base.h"
#include <iostream>

// Constructor de la clase Base
// Recibe el número de filas y columnas para la matriz del juego
Base::Base(int filas, int columnas) : filas(filas), columnas(columnas) {
    std::vector<int> numeros;

    // Llenamos el vector 'numeros' con pares de números del 1 al 20
    for (int i = 1; i <= 20; ++i) {
        numeros.push_back(i);
        numeros.push_back(i);
    }

    // Mezclamos los números para que estén en posiciones aleatorias
    // el rand se utiliza para generar números aleatorios (posiciones aleatorias)
    for (size_t i = 0; i < numeros.size(); ++i) {
        int j = i + (std::rand() % (numeros.size() - i)); // Elegimos una posición aleatoria a partir de i
        int temp = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = temp;
    }

    // se redimensiona la matriz principal y la matriz de descubiertos
    matriz.resize(filas, std::vector<int>(columnas));
    descubiertos.resize(filas, std::vector<bool>(columnas, false));

    // Llenamos la matriz con los números mezclados
    int index = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = numeros[index++];
        }
    }
}

// Muestra la matriz en consola
// Si 'oculto' es true, muestra 'X' en las posiciones no descubiertas
void Base::mostrar(bool oculto) const {
    std::cout << "\nBase:\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (descubiertos[i][j] || !oculto) {
                std::cout << matriz[i][j] << "\t"; // Muestra el número si está descubierto o si no hay ocultamiento
            } else {
                std::cout << "X\t"; // Muestra 'X' si está oculto
            }
        }
        std::cout << "\n";
    }
}

// Intenta descubrir dos posiciones de la matriz
// Si los valores son iguales, los marca como descubiertos y retorna true
// Si no, retorna false
bool Base::descubrir(int f1, int c1, int f2, int c2) {
    if (matriz[f1][c1] == matriz[f2][c2]) {
        descubiertos[f1][c1] = true;
        descubiertos[f2][c2] = true;
        return true;
    }
    return false;
}

// Verifica si una posición específica ya fue descubierta
bool Base::estaDescubierto(int f, int c) const {
    return descubiertos[f][c];
}


