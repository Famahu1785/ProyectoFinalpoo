#include "include/Base.h"
#include <iostream>

Base::Base(int filas, int columnas) : filas(filas), columnas(columnas) {
    std::vector<int> numeros;
    for (int i = 1; i <= 20; ++i) {
        numeros.push_back(i);
        numeros.push_back(i);
    }

    // Mezcla simple sin usar <algorithm> ni <cstdlib>
    for (int i = 0; i < numeros.size(); ++i) {
        int j = i + (std::rand() % (numeros.size() - i));
        int temp = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = temp;
    }

    matriz.resize(filas, std::vector<int>(columnas));
    descubiertos.resize(filas, std::vector<bool>(columnas, false));

    int idx = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = numeros[idx++];
        }
    }
}

void Base::mostrar(bool oculto) const {
    std::cout << "\nBase:\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (descubiertos[i][j] || !oculto)
                std::cout << matriz[i][j] << "\t";
            else
                std::cout << "X\t";
        }
        std::cout << "\n";
    }
}

bool Base::descubrir(int f1, int c1, int f2, int c2) {
    if (matriz[f1][c1] == matriz[f2][c2]) {
        descubiertos[f1][c1] = true;
        descubiertos[f2][c2] = true;
        return true;
    }
    return false;
}

bool Base::estaDescubierto(int f, int c) const {
    return descubiertos[f][c];
}
