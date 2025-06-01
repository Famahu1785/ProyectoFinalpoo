#include "include/Juego.h"

#include <iostream>
#include <limits>
using namespace std;

Juego::Juego() {}

void Juego::mostrarMenu() {
    int opcion = 0;
    do {
        cout << "\n==== MENU PRINCIPAL ====" << endl;
        cout << "1. Jugar Ahorcado" << endl;
        cout << "2. Jugar Concéntrese" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();  // aqui se  Limpia el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta
            cout << "Entrada inválida. Por favor, ingrese un número." << endl;
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
                cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 3);
}
