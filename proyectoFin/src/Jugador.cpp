#include "include/Jugador.h"

// Implementación de la clase Jugador

// Constructor por defecto: nombre vacío y puntaje en cero
Jugador::Jugador() : nombre(""), puntaje(0) {}

// Constructor con nombre y puntaje inicial
Jugador::Jugador(const std::string& nombre, int puntaje) : nombre(nombre), puntaje(puntaje) {}

// Devuelve el nombre del jugador
std::string Jugador::getNombre() const {
    return nombre;
}

// Cambia el nombre del jugador
void Jugador::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

// Devuelve el puntaje actual
int Jugador::getPuntaje() const {
    return puntaje;
}

// Establece un nuevo valor para el puntaje
void Jugador::setPuntaje(int puntaje) {
    this->puntaje = puntaje;
}

// Aumenta el puntaje en la cantidad indicada
void Jugador::aumentarPuntaje(int cantidad) {
    puntaje += cantidad;
}

// Reinicia el puntaje a cero
void Jugador::resetPuntaje() {
    puntaje = 0;
}


