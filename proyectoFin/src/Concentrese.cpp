#include "include/Concentrese.h"
#include <iostream>

// Constructor: inicializa el juego llamando al constructor base con el nombre "MEM" y los jugadores
Concentrese::Concentrese(Jugador* j1, Jugador* j2) : Juego("MEM", j1, j2) {}

// Método principal para jugar Concentrese
void Concentrese::jugar() {
    // Reinicia la puntuación de ambos jugadores al inicio del juego
    jugador1->resetPuntuacion();
    jugador2->resetPuntuacion();
    Jugador* actual = jugador1; // El jugador que inicia

    int totalPares = 20; // Número total de pares a encontrar
    // El juego continúa hasta que se encuentren todos los pares
    while (jugador1->getPuntuacion() + jugador2->getPuntuacion() < totalPares) {
        std::cout << "\nTurno de: " << actual->getNombre() << std::endl;
        base.mostrar(); // Muestra el tablero actual

        int f1, c1, f2, c2;
        std::cout << "Seleccione primera posicion (fila columna): ";
        std::cin >> f1 >> c1;
        std::cout << "Seleccione segunda posicion (fila columna): ";
        std::cin >> f2 >> c2;

        // Verifica si alguna de las posiciones ya fue descubierta
        if (base.estaDescubierto(f1, c1) || base.estaDescubierto(f2, c2)) {
            std::cout << "Una o ambas posiciones ya fueron descubiertas.\n";
            continue; // Si ya están descubiertas, repite el turno
        }

        // Intenta descubrir las posiciones seleccionadas
        if (base.descubrir(f1, c1, f2, c2)) {
            std::cout << "¡Par encontrado!\n";
            actual->sumarPunto(); // Suma un punto si es un par
            // El mismo jugador sigue jugando si acierta
        } else {
            std::cout << "No es un par.\n";
            // Cambia de jugador si no acierta
            actual = (actual == jugador1) ? jugador2 : jugador1;
        }
    }

    // Cuando se encuentran todos los pares, termina el juego
    std::cout << "\nJuego finalizado.\n";
    base.mostrar(false); // Muestra el tablero completo al final

    // Muestra la puntuación final de ambos jugadores
    std::cout << jugador1->getNombre() << ": " << jugador1->getPuntuacion() << " puntos\n";
    std::cout << jugador2->getNombre() << ": " << jugador2->getPuntuacion() << " puntos\n";

    // Determina el ganador y guarda el resultado
    if (jugador1->getPuntuacion() > jugador2->getPuntuacion()) {
        std::cout << "Ganador: " << jugador1->getNombre() << "\n";
        guardarResultado(jugador1, "G"); // G = Ganador
        guardarResultado(jugador2, "P"); // P = Perdedor
    } else if (jugador2->getPuntuacion() > jugador1->getPuntuacion()) {
        std::cout << "Ganador: " << jugador2->getNombre() << "\n";
        guardarResultado(jugador2, "G");
        guardarResultado(jugador1, "P");
    } else {
        std::cout << "Empate.\n";
        guardarResultado(jugador1, "E"); // E = Empate
        guardarResultado(jugador2, "E");
    }
}


