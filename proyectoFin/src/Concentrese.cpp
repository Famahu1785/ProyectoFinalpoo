#include "include/Concentrese.h"
#include <iostream>

Concentrese::Concentrese(Jugador* j1, Jugador* j2) : Juego("MEM", j1, j2) {}

void Concentrese::jugar() {
    jugador1->resetPuntuacion();
    jugador2->resetPuntuacion();
    Jugador* actual = jugador1;

    int totalPares = 20;
    while (jugador1->getPuntuacion() + jugador2->getPuntuacion() < totalPares) {
        std::cout << "\nTurno de: " << actual->getNombre() << std::endl;
        base.mostrar();
        int f1, c1, f2, c2;
        std::cout << "Seleccione primera posicion (fila columna): ";
        std::cin >> f1 >> c1;
        std::cout << "Seleccione segunda posicion (fila columna): ";
        std::cin >> f2 >> c2;

        if (base.estaDescubierto(f1, c1) || base.estaDescubierto(f2, c2)) {
            std::cout << "Una o ambas posiciones ya fueron descubiertas.\n";
            continue;
        }

        if (base.descubrir(f1, c1, f2, c2)) {
            std::cout << "¡Par encontrado!\n";
            actual->sumarPunto();
        } else {
            std::cout << "No es un par.\n";
            actual = (actual == jugador1) ? jugador2 : jugador1;
        }
    }

    std::cout << "\nJuego finalizado.\n";
    base.mostrar(false);
    std::cout << jugador1->getNombre() << ": " << jugador1->getPuntuacion() << " puntos\n";
    std::cout << jugador2->getNombre() << ": " << jugador2->getPuntuacion() << " puntos\n";

    if (jugador1->getPuntuacion() > jugador2->getPuntuacion()) {
        std::cout << "Ganador: " << jugador1->getNombre() << "\n";
        guardarResultado(jugador1, "G");
        guardarResultado(jugador2, "P");
    } else if (jugador2->getPuntuacion() > jugador1->getPuntuacion()) {
        std::cout << "Ganador: " << jugador2->getNombre() << "\n";
        guardarResultado(jugador2, "G");
        guardarResultado(jugador1, "P");
    } else {
        std::cout << "Empate.\n";
        guardarResultado(jugador1, "E");
        guardarResultado(jugador2, "E");
    }
}

