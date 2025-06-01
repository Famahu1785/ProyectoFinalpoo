#include "include/Ahorcado.h"
#include "include/Concentrese.h"
#include <iostream>
#include <limits>
#include <ctime>

// Implementación temporal de obtenerPalabraAleatoria
std::string obtenerPalabraAleatoria() {
    // Puedes reemplazar esto con la lógica real de selección de palabras
    return "ejemplo";
}

// Limpia cualquier error en la entrada y descarta caracteres sobrantes
void limpiarBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Pide al usuario un número dentro de un rango, repite si se equivoca
int pedirNumero(const std::string& mensaje, int minimo = std::numeric_limits<int>::min(), int maximo = std::numeric_limits<int>::max()) {
    int valor;
    while (true) {
        std::cout << mensaje;
        std::cin >> valor;
        if (std::cin.fail() || valor < minimo || valor > maximo) {
            std::cout << "Eso no es válido. Intenta otra vez.\n";
            limpiarBuffer();
        } else {
            limpiarBuffer();
            return valor;
        }
    }
}

// Pide una palabra al usuario
std::string pedirTexto(const std::string& mensaje) {
    std::string texto;
    std::cout << mensaje;
    std::cin >> texto;
    return texto;
}

// Muestra el menú y devuelve la opción elegida
int mostrarMenu() {
    std::cout << "\n=== MENU PRINCIPAL ===\n";
    std::cout << "1. Jugar Ahorcado\n";
    std::cout << "2. Jugar Concentrese\n";
    std::cout << "3. Salir\n";
    return pedirNumero("Elige una opción: ", 1, 3);
}

// Modo para jugar al Ahorcado
void jugarAhorcado() {
    int modo = pedirNumero("\n1. Jugador vs Jugador\n2. Jugador vs CPU\nSelecciona el modo: ", 1, 2);
    std::string nombre1 = pedirTexto("Nombre del jugador 1: ");
    std::string nombre2, palabra;

    Jugador* j1 = new Jugador(nombre1);
    Jugador* j2 = nullptr;

    if (modo == 1) {
        nombre2 = pedirTexto("Nombre del jugador 2: ");
        j2 = new Jugador(nombre2);

        int quienEscribe = pedirNumero("¿Quién escribe la palabra secreta? (1 o 2): ", 1, 2);
        palabra = pedirTexto((quienEscribe == 1 ? nombre1 : nombre2) + ", escribe la palabra secreta: ");

        Ahorcado juego(j1, j2, palabra, false);
        juego.jugar();

    } else {
        std::cout << "Se elegirá una palabra aleatoria del archivo.\n";
        j2 = new Jugador("CPU", true);
        // Suponiendo que hay una función global o utilitaria para obtener la palabra aleatoria:
        palabra = obtenerPalabraAleatoria(); // Implementa esta función en otro archivo si no existe

        Ahorcado juego(j1, j2, palabra, true);
        juego.jugar();
    }

    delete j1;
    delete j2;
}

// Modo para jugar a Concéntrese
void jugarConcentrese() {
    std::string nombre1 = pedirTexto("Nombre del jugador 1: ");
    int modo = pedirNumero("1. Contra otro jugador\n2. Contra CPU\nElige el modo: ", 1, 2);

    Jugador* j1 = new Jugador(nombre1);
    Jugador* j2 = nullptr;

    if (modo == 1) {
        std::string nombre2 = pedirTexto("Nombre del jugador 2: ");
        j2 = new Jugador(nombre2);
    } else {
        j2 = new Jugador("CPU", true);
    }

    Concentrese juego(j1, j2);
    juego.jugar();

    delete j1;
    delete j2;
}

// Punto de entrada del programa
int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Inicia la aleatoriedad para los juegos

    while (true) {
        int opcion = mostrarMenu();

        if (opcion == 1) {
            jugarAhorcado();
        } else if (opcion == 2) {
            jugarConcentrese();
        } else {
            std::cout << "Hasta pronto.\n";
            break;
        }
    }

    return 0;
}

