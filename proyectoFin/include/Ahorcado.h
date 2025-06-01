#ifndef AHORCADO_H
#define AHORCADO_H

#include "/workspaces/ProyectoFinalpoo/proyectoFin/include/Juego.h"
#include <vector>
#include <set>

// Clase que implementa el juego del Ahorcado
class Ahorcado : public Juego {
private:
    std::string palabraSecreta;           // Palabra que el jugador debe adivinar
    std::string palabraOculta;            // Representación de la palabra con guiones bajos
    std::string palabraAdivinada;         // Palabra adivinada por el jugador hasta el momento
    int intentos;                          // Número de intentos fallidos
    int turno;                             // Turno actual (1 = jugador1, 2 = jugador2 o CPU)
    int puntajeJugador1;                  // Puntaje acumulado del jugador 1
    int puntajeJugador2;                  // Puntaje acumulado del jugador 2 (o CPU)
    bool cpu;                              // Indica si se juega contra la CPU
    bool contraMaquina;                   // Bandera duplicada para control extra (puede fusionarse con 'cpu')

    std::vector<std::string> partesCuerpo; // Partes del cuerpo mostradas al fallar
    std::set<char> letrasUsadas;           // Letras que ya se intentaron

    Jugador* jugador1; // Puntero al jugador 1
    Jugador* jugador2; // Puntero al jugador 2 o CPU

    // Muestra el estado actual del juego (palabra parcial, partes del cuerpo, intentos)
    void mostrarEstado(const std::string& oculta);

public:
    // Constructor. Si se juega contra CPU, j2 puede ser nullptr.
    Ahorcado(Jugador* j1, Jugador* j2, const std::string& palabra, bool cpu = false);

    // Destructor virtual para asegurar liberación correcta en jerarquía
    ~Ahorcado() override;

    // Método que ejecuta el flujo completo del juego
    void jugar() override;

    // Selecciona una palabra aleatoria desde el archivo palabras.txt
    std::string obtenerPalabraAlea();
};

#endif
