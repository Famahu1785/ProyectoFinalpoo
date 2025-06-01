#ifndef JUEGO_H
#define JUEGO_H

#include <string>
#include <fstream>
#include <ctime> // esta libreria sirve para manejar fechas y horas
#include <iostream>
#include "Jugador.h"

// se declaran las clases Ahorcado y Concentrese para evitar dependencias circulares
// las dependencias circulares ocurren cuando dos o más archivos de encabezado se incluyen mutuamente, lo que puede causar problemas de compilación
class Ahorcado;
class Concentrese;

class Juego {
protected:
    std::string nombre;
    Jugador* jugador1;
    Jugador* jugador2;
    Juego(const Juego&) = delete;
    Juego& operator=(const Juego&) = delete;// Elimina el constructor de copia y el operador de asignación para evitar copias no deseadas
        virtual void guardarResultado(Jugador* jugador, const std::string& resultado) {// Guarda el resultado del juego en un archivo
        std::ofstream archivo("historial.txt", std::ios::app);// Abre el archivo en modo de adición
        time_t ahora = time(nullptr);// Obtiene el tiempo actual
        tm* tiempo = localtime(&ahora);// Convierte el tiempo a la zona horaria local
        char buffer[20];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", tiempo); // Formatea la fecha como una cadena

        archivo << buffer << " " << jugador->getNombre()  // Escribe la fecha, el nombre del jugador y el resultado en el archivo
                << " " << nombre << " " << resultado << std::endl;

        archivo.close();
    }

public:
    Juego(const std::string& nombre, Jugador* j1, Jugador* j2); // Constructor que inicializa el nombre del juego y los jugadores
    virtual ~Juego(); // Destructor virtual para permitir la limpieza adecuada de recursos
private:
    Ahorcado* ahorcado; // es el Puntero a un objeto de tipo Ahorcado
    Concentrese* concentrese; // es el  Puntero a un objeto de tipo Concentrese


    virtual void jugar() = 0; // Método virtual puro que debe ser implementado por las clases derivadas
    Juego();
    void mostrarMenu();
    void jugarAhorcado();
    void jugarConcentrese();
};

#endif
