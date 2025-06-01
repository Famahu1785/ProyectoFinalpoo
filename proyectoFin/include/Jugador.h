
#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

// Clase que representa a un jugador humano o CPU
class Jugador {
public:
    // Constructores
    Jugador(); // Puntaje inicializado en 0
    Jugador(const std::string& nombre, bool esMaquina = false, int puntaje = 0); // Por defecto no es CPU
    Jugador(const std::string& nombre, int puntaje); // Constructor alternativo

    // Métodos de acceso
    std::string getNombre() const;
    void setNombre(const std::string& nombre);

    int getPuntaje() const;
    void setPuntaje(int puntaje);

    bool esCPU() const;

    // Métodos de control de puntaje
    void aumentarPuntaje(int cantidad = 1);
    void resetPuntaje();

private:
    std::string nombre;
    int puntaje;
    bool esMaquina;
};

#endif
