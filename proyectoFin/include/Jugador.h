
#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

class Jugador {
public:
    // Constructor único claro
    Jugador(); 
    Jugador(const std::string& nombre, bool esMaquina = false, int puntaje = 0);
    Jugador(const std::string& nombre, int puntaje);

    std::string getNombre() const;
    int getPuntuacion() const;
    void sumarPunto();
    void resetPuntuacion();
    void setNombre(const std::string& nombre);

    int getPuntaje() const;
    void setPuntaje(int puntaje);
    bool esCPU() const;

    void aumentarPuntaje(int cantidad = 1);
    void resetPuntaje();

private:
    std::string nombre;
    int puntaje;
    bool esMaquina;
};

#endif
