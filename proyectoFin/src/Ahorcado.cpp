#include "include/Ahorcado.h"
#include <iostream>
#include <fstream>
#include <ctime>

Ahorcado::Ahorcado(Jugador* j1, Jugador* j2, const std::string& palabra, bool cpu)
    : Juego("AH", j1, j2), palabraSecreta(palabra), intentos(0), contraMaquina(cpu) {
    partesCuerpo = {"Cabeza", "Tronco", "Brazo izquierdo", "Brazo derecho", "Pierna izquierda", "Pierna derecha"};
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

std::string Ahorcado::obtenerPalabraAlea() {
    std::ifstream archivo("palabras.txt");
    std::vector<std::string> palabras;
    std::string palabra;
    while (archivo >> palabra && palabras.size() < 200) {
        palabras.push_back(palabra);
    }
    archivo.close();
    if (!palabras.empty()) {
        int indice = std::time(nullptr) % palabras.size();
        return palabras[indice];
    }
    return "error";
}

void Ahorcado::mostrarEstado(const std::string& oculta) {
    std::cout << "\nPalabra: " << oculta << "\n";
    if (intentos > 0 && intentos <= partesCuerpo.size()) {
        std::cout << "Parte mostrada: " << partesCuerpo[intentos - 1] << "\n";
    }
    std::cout << "Intentos: " << intentos << "/" << partesCuerpo.size() << "\n";
}

void Ahorcado::jugar() {
    std::string oculta(palabraSecreta.size(), '_');
    std::set<char> letras;
    Jugador* actual = jugador1;

    while (intentos < partesCuerpo.size() && oculta != palabraSecreta) {
        mostrarEstado(oculta);
        char intento;

        if (actual->esCPU()) {
            intento = 'a' + (std::time(nullptr) % 26);
            std::cout << actual->getNombre() << " (CPU) elige: " << intento << "\n";
        } else {
            std::cout << actual->getNombre() << ", ingrese una letra: ";
            std::cin >> intento;
            intento = tolower(intento);
        }

        if (letras.count(intento)) {
            std::cout << "Ya fue usada esa letra.\n";
        } else {
            letras.insert(intento);
            bool acierto = false;
            for (size_t i = 0; i < palabraSecreta.length(); i++) {
                if (palabraSecreta[i] == intento) {
                    oculta[i] = intento;
                    acierto = true;
                }
            }
            if (!acierto) intentos++;
        }

        if (oculta == palabraSecreta) {
            std::cout << "\nGanador: " << actual->getNombre() << "\n";
            actual->aumentarPuntaje();
            guardarResultado(actual, "G");
            return;
        }

        actual = (actual == jugador1) ? jugador2 : jugador1;
    }

    std::cout << "\nPerdieron. La palabra era: " << palabraSecreta << "\n";
    guardarResultado(jugador1, "P");
    guardarResultado(jugador2, "P");
}
