#ifndef CONCENTRESE_H
#define CONCENTRESE_H

#include "/workspaces/ProyectoFinalpoo/proyectoFin/include/Juego.h"
#include "Base.h"

// Clase que representa el juego Concéntrese (memorama de pares)
class Concentrese : public Juego {
private:
    Base base; // Objeto base que contiene la matriz de pares

public:
    // Constructor que recibe dos jugadores (humano vs humano o humano vs CPU)
    Concentrese(Jugador* j1, Jugador* j2);

    // Destructor virtual para asegurar limpieza correcta en jerarquía
    ~Concentrese() override;

    // Ejecuta la lógica completa del juego Concéntrese
    void jugar() override;
};

#endif

