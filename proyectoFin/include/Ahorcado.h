#ifndef AHORCADO_H
#define AHORCADO_H

#include "/workspaces/ProyectoFinalpoo/proyectoFin/include/Juego.h"
#include <vector>
#include <set>

class Ahorcado : public Juego {
private:
    std::string palabraSecreta;
    int intentos;
    std::vector<std::string> partesCuerpo;// Partes del cuerpo que se muestran en el juego
    std::set<char> letrasUsadas; // Letras que ya han sido adivinadas
    Jugador* jugador1; // Puntero al primer jugador
    Jugador* jugador2;
    std::string palabraOculta; // Representación de la palabra oculta con guiones bajos
    std::string palabraAdivinada; // Representación de la palabra adivinada por el jugador
    bool cpu; // Indica si se está jugando contra la CPU
    int turno; // Indica de quién es el turno (1 para jugador 1, 2 para jugador 2 o CPU)
    int puntajeJugador1; // Puntaje del jugador 1
    int puntajeJugador2; // Puntaje del jugador 2 (puede ser 0 si se juega contra la CPU)
    bool contraMaquina;

    void mostrarEstado(const std::string& oculta);// Muestra el estado actual del juego, incluyendo la palabra oculta y las partes del cuerpo

public:
    Ahorcado(Jugador* j1, Jugador* j2, const std::string& palabra, bool cpu = false); // aqui con "jugador* j2" se permite que el segundo jugador sea nulo si se juega contra la CPU
    ~Ahorcado() override; // esto se hace para asegurarse de que el destructor de la clase base se llame correctamente
    void jugar() override;
    std::string obtenerPalabraAlea();
};

#endif
