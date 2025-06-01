#include "include/Jugador.h"

// este archivo contiene la implementación de la clase Jugador
Jugador::Jugador() : nombre(""), puntaje(0) {}

// la & indica que el parámetro es una referencia, lo que evita la copia innecesaria de cadenas
Jugador::Jugador(const std::string& nombre, int puntaje) : nombre(nombre), puntaje(puntaje) {}


std::string Jugador::getNombre() const {
    return nombre;
}


void Jugador::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

int Jugador::getPuntaje() const {
    return puntaje;
}


void Jugador::setPuntaje(int puntaje) {
    this->puntaje = puntaje;
}


void Jugador::aumentarPuntaje(int cantidad) {
    puntaje += cantidad;
}
void Jugador::resetPuntaje() {
    puntaje = 0;
}

