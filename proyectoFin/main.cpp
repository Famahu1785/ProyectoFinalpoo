#include "include/Ahorcado.h"
#include "include/Concentrese.h"
#include <iostream>
#include <limits>
#include <ctime>

// Limpia la entrada estándar para evitar errores de lectura posteriores
void limpiarEntrada() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Lee un entero desde la entrada estándar, validando el rango y la entrada
int leerEntero(const std::string& mensaje, int min = std::numeric_limits<int>::min(), int max = std::numeric_limits<int>::max()) {
    int valor;
    while (true) {
        std::cout << mensaje;
        std::cin >> valor;
        // Si la entrada falla o está fuera de rango, se limpia y se pide de nuevo
        if (std::cin.fail() || valor < min || valor > max) {
            std::cout << "Entrada inválida. Intente de nuevo.\n";
            limpiarEntrada();
        } else {
            limpiarEntrada();
            return valor;
        }
    }
}

// Lee una cadena simple (sin espacios) desde la entrada estándar
std::string leerCadena(const std::string& mensaje) {
    std::string input;
    std::cout << mensaje;
    std::cin >> input;
    return input;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Inicializa la semilla para aleatoriedad

    while (true) {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1. Jugar Ahorcado\n";
        std::cout << "2. Jugar Concentrese\n";
        std::cout << "3. Salir\n";

        int opcion = leerEntero("Seleccione una opcion: ", 1, 3);

        if (opcion == 1) {
            int modo = leerEntero("\n1. Jugador vs Jugador\n2. Jugador vs CPU\nSeleccione modo: ", 1, 2);
            std::string nombre1 = leerCadena("Ingrese nombre del jugador 1: ");
            std::string nombre2, palabra;

            Jugador* j1 = new Jugador(static_cast<std::string>(nombre1));
            Jugador* j2 = nullptr;

            if (modo == 1) {
                nombre2 = leerCadena("Ingrese nombre del jugador 2: ");
                j2 = new Jugador(nombre2);

                // Permite elegir quién escribe la palabra secreta y la solicita
                int iniciador = leerEntero("¿Quién escribe la palabra secreta? (1 o 2): ", 1, 2);
                palabra = leerCadena((iniciador == 1 ? nombre1 : nombre2) + ", escriba la palabra secreta: ");

                // Crea el juego de ahorcado en modo jugador vs jugador
                Ahorcado juego(j1, j2, palabra, false);
                juego.jugar();
            } else {
                std::cout << "La palabra se seleccionará aleatoriamente del archivo.\n";
                j2 = new Jugador("CPU", true);
                // Usa una función externa para obtener una palabra aleatoria para el modo CPU
                extern std::string obtenerPalabraAleatoria();
                std::string palabraCPU = obtenerPalabraAleatoria();
                // Crea el juego de ahorcado en modo jugador vs CPU
                Ahorcado juego(j1, j2, palabraCPU, true);
                juego.jugar();
            }

            delete j1;
            delete j2;

        } else if (opcion == 2) {
            std::string nombre1 = leerCadena("Ingrese nombre del jugador 1: ");
            int modo = leerEntero("1. Contra otro jugador\n2. Contra CPU\nSeleccione modo: ", 1, 2);

            Jugador* j1 = new Jugador(nombre1);
            Jugador* j2 = nullptr;

            if (modo == 1) {
                std::string nombre2 = leerCadena("Ingrese nombre del jugador 2: ");
                j2 = new Jugador(static_cast<std::string>(nombre2));
            } else {
                j2 = new Jugador("CPU", true);
            }

            // Crea el juego de Concentrese con los jugadores seleccionados
            Concentrese juego(j1, j2);
            juego.jugar();

            delete j1;
            delete j2;

        } else {
            std::cout << "Saliendo del programa...\n";
            break;
        }
    }

    return 0;
}
