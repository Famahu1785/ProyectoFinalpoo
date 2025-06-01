#include "include/Juego.h"

#include <iostream>
#include <limits>
using namespace std;

// Constructor vacío
Juego::Juego() {}

// Muestra el menú del juego principal
void Juego::mostrarMenu() {
    int opcion = 0;

    do {
        cout << "\n==== MENU PRINCIPAL ====\n";
        cout << "1. Jugar Ahorcado\n";
        cout << "2. Jugar Concéntrese\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        // Si hubo un error en la entrada, lo limpiamos y pedimos de nuevo
        if (cin.fail()) {
            cin.clear(); // Borra el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta lo que quedó en el búfer
            cout << "Eso no es válido. Intente otra vez.\n";
            continue;
        }

        switch (opcion) {
            case 1:
                jugarAhorcado();
                break;
            case 2:
                jugarConcentrese();
                break;
            case 3:
                cout << "Saliendo del juego...\n";
                break;
            default:
                cout << "Opción no válida. Intente nuevamente.\n";
        }

    } while (opcion != 3);
}
