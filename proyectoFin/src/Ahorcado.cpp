#include "include/Ahorcado.h"
#include <iostream>
#include <fstream>
#include <ctime>

// Constructor de la clase Ahorcado
Ahorcado::Ahorcado(Jugador* j1, Jugador* j2, const std::string& palabra, bool cpu)
    : Juego("AH", j1, j2), palabraSecreta(palabra), intentos(0), contraMaquina(cpu) {

    // Inicializa las partes del cuerpo del ahorcado
    partesCuerpo = { "Cabeza", "Tronco", "Brazo izquierdo", "Brazo derecho", "Pierna izquierda", "Pierna derecha" };

    // Inicializa la semilla para números aleatorios
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

// Devuelve una palabra aleatoria del archivo palabras.txt
std::string Ahorcado::obtenerPalabraAlea() {
    std::ifstream archivo("palabras.txt");
    std::vector<std::string> palabras;
    std::string palabra;

    // Lee hasta 200 palabras del archivo
    while (archivo >> palabra && palabras.size() < 200) {
        palabras.push_back(palabra);
    }

    archivo.close();

    // Si hay palabras, elige una al azar
    if (!palabras.empty()) {
        int indice = std::time(nullptr) % palabras.size();
        return palabras[indice];
    }

    // Si no hay palabras, devuelve "error"
    return "error";
}

// Muestra el estado actual del juego
void Ahorcado::mostrarEstado(const std::string& oculta) {
    std::cout << "\nPalabra: " << oculta << "\n";

    // Si hubo intentos, muestra la parte del cuerpo correspondiente
    if (intentos > 0 && intentos <= static_cast<int>(partesCuerpo.size())) {
        std::cout << "Parte mostrada: " << partesCuerpo[intentos - 1] << "\n";
    }

    std::cout << "Intentos: " << intentos << "/" << partesCuerpo.size() << "\n";
}

// Lógica principal del juego del ahorcado
void Ahorcado::jugar() {
    std::string oculta(palabraSecreta.length(), '_'); // Crea la palabra oculta con guiones bajos
    std::set<char> letras; // Letras ya usadas
    Jugador* actual = jugador1; // Jugador actual

    // Mientras no se acaben los intentos y no se adivine la palabra
    while (intentos < static_cast<int>(partesCuerpo.size()) && oculta != palabraSecreta) {
        mostrarEstado(oculta);
        char intento;

        // Si el jugador es CPU, elige una letra aleatoria
        if (actual->esCPU()) {
            intento = 'a' + (std::time(nullptr) % 26);
            std::cout << actual->getNombre() << " (CPU) elige: " << intento << "\n";
        } else {
            // Si es humano, pide una letra
            std::cout << actual->getNombre() << ", ingrese una letra: ";
            std::cin >> intento;
            intento = tolower(intento);
        }

        // Verifica si la letra ya fue usada
        if (letras.count(intento)) {
            std::cout << "Ya fue usada esa letra.\n";
        } else {
            letras.insert(intento);
            bool acierto = false;

            // Recorre la palabra secreta para ver si la letra está
            for (size_t i = 0; i < palabraSecreta.length(); ++i) {
                if (palabraSecreta[i] == intento) {
                    oculta[i] = intento;
                    acierto = true;
                }
            }

            // Si no acertó, aumenta los intentos
            if (!acierto) {
                intentos++;
            }
        }

        // Si adivinó la palabra, termina el juego
        if (oculta == palabraSecreta) {
            std::cout << "\nGanador: " << actual->getNombre() << "\n";
            actual->aumentarPuntaje();
            guardarResultado(actual, "G");
            return;
        }

        // Cambia de jugador
        actual = (actual == jugador1) ? jugador2 : jugador1;
    }

    // Si se acaban los intentos, pierden ambos
    std::cout << "\nPerdieron. La palabra era: " << palabraSecreta << "\n";
    guardarResultado(jugador1, "P");
    guardarResultado(jugador2, "P");
}
