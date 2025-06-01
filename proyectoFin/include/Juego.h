#ifndef JUEGO_H
#define JUEGO_H

#include <string>
#include <fstream>
#include <ctime>     // Esta librería sirve para manejar fechas y horas
#include <iostream>
#include "Jugador.h"

// Declaraciones anticipadas para evitar dependencias circulares
// Las dependencias circulares ocurren cuando dos encabezados se incluyen mutuamente
class Ahorcado;
class Concentrese;

// Clase base abstracta para todos los juegos
class Juego {
protected:
    std::string nombre;         // Nombre del juego (ej. "Ahorcado", "Concentrese")
    Jugador* jugador1;          // Puntero al jugador 1
    Jugador* jugador2;          // Puntero al jugador 2

    // Constructor protegido que impide copias no deseadas
    Juego(const Juego&) = delete;
    Juego& operator=(const Juego&) = delete;

    // Guarda el resultado del juego en un archivo historial.txt
    virtual void guardarResultado(Jugador* jugador, const std::string& resultado) {
        std::ofstream archivo("historial.txt", std::ios::app); // Abre en modo añadir
        time_t ahora = time(nullptr);         // Obtiene el tiempo actual
        tm* tiempo = localtime(&ahora);       // Convierte a hora local

        char buffer[20];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", tiempo);  // Formatea la fecha

        archivo << buffer << " " << jugador->getNombre()
                << " " << nombre << " " << resultado << std::endl;

        archivo.close();
    }

public:
    // Constructor que inicializa el nombre del juego y los jugadores
    Juego(const std::string& nombre, Jugador* j1, Jugador* j2);

    // Destructor virtual para permitir la limpieza correcta en clases derivadas
    virtual ~Juego();

    // Método puramente virtual que deben implementar los juegos concretos
    virtual void jugar() = 0;

private:
    Ahorcado* ahorcado;         // Puntero a un objeto Ahorcado
    Concentrese* concentrese;   // Puntero a un objeto Concentrese

    // Métodos auxiliares para menú (actualmente no utilizados si se gestiona desde main)
    Juego();                    // Constructor privado por seguridad
    void mostrarMenu();
    void jugarAhorcado();
    void jugarConcentrese();
};

#endif
