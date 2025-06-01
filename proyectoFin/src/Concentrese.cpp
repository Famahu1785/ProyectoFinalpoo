#include "include/Concentrese.h"
#include <iostream>

// Constructor: le pasa los jugadores al constructor base junto con el nombre del juego
Concentrese::Concentrese(Jugador* j1, Jugador* j2) : Juego("MEM", j1, j2) {}

// Método que ejecuta el juego completo de Concéntrese
void Concentrese::jugar() {
    // Se reinicia la puntuación de ambos jugadores al comenzar
    jugador1->resetPuntuacion();
    jugador2->resetPuntuacion();

    Jugador* actual = jugador1; // El jugador que arranca

    int totalPares = 20; // Hay 20 pares por encontrar

    // Mientras no se hayan encontrado todos los pares, el juego sigue
    while (jugador1->getPuntuacion() + jugador2->getPuntuacion() < totalPares) {
        std::cout << "\nTurno de: " << actual->getNombre() << std::endl;
        base.mostrar(); // Se muestra el tablero con las cartas ocultas

        int f1, c1, f2, c2;
        std::cout << "Seleccione primera posicion (fila columna): ";
        std::cin >> f1 >> c1;
        std::cout << "Seleccione segunda posicion (fila columna): ";
        std::cin >> f2 >> c2;

        // Si alguna de las dos posiciones ya fue descubierta, se avisa
        if (base.estaDescubierto(f1, c1) || base.estaDescubierto(f2, c2)) {
            std::cout << "Una o ambas posiciones ya están descubiertas.\n";
            continue; // Se vuelve a pedir una jugada
        }

        // Se intenta descubrir un par
        if (base.descubrir(f1, c1, f2, c2)) {
            std::cout << "¡Par encontrado!\n";
            actual->sumarPunto(); // Suma punto si acierta
            // El jugador repite si acierta
        } else {
            std::cout << "No es un par.\n";
            // Si no acierta, se cambia al otro jugador
            actual = (actual == jugador1) ? jugador2 : jugador1;
        }
    }

    // Al terminar el juego, se muestra el tablero completo
    std::cout << "\nJuego finalizado.\n";
    base.mostrar(false);

    // Se muestran los puntajes finales
    std::cout << jugador1->getNombre() << ": " << jugador1->getPuntuacion() << " puntos\n";
    std::cout << jugador2->getNombre() << ": " << jugador2->getPuntuacion() << " puntos\n";

    // Se determina el resultado y se guarda
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



