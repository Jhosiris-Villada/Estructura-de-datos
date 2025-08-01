#include <iostream>
#include <vector>
#include <string>

using namespace std;


void insertarDatos(vector<string>& nombres) {
    int cantidad;
    cout << "\n Cuantos nombres desea ingresar? ";
    cin >> cantidad;
    cin.ignore(); 

    for (int i = 0; i < cantidad; i++) {
        string nombre;
        cout << "Ingrese el nombre #" << (i + 1) << ": ";
        getline(cin, nombre);
        nombres.push_back(nombre);
    }
}

void listarDatos(const vector<string>& nombres) {
    if (nombres.empty()) {
        cout << "\nNo hay nombres registrados.\n";
        return;
    }

    cout << "\n--Lista de Nombres Registrados--\n";
    for (size_t i = 0; i < nombres.size(); i++) {
        cout << i << ". " << nombres[i] << "\n";
    }
}

void eliminarDato(vector<string>& nombres) {
    if (nombres.empty()) {
        cout << "\nNo hay nombres para eliminar.\n";
        return;
    }

    listarDatos(nombres);

    size_t indice;
    cout << "\nIngrese el indice del nombre que desea eliminar: ";
    cin >> indice;

    if (cin.fail() || indice >= nombres.size()) {
        cout << "Indice invalido.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    nombres.erase(nombres.begin() + indice);
    cout << "Nombre eliminado correctamente\n";
}

int main() {
    vector<string> nombres;
    int opcion;
    do {
        cout << "\n------- MENU PRINCIPAL ---------\n";
        cout << "1. Insertar nombres\n";
        cout << "2. Listar nombres\n";
        cout << "3. Eliminar un nombre\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                insertarDatos(nombres);
                break;
            case 2:
                listarDatos(nombres);
                break;
            case 3:
                eliminarDato(nombres);
                break;
            case 4:
                cout << "Saliendo del programa\n";
                break;
            default:
                cout << "Opcion invalida, intente de nuevo\n";
        }

    } while (opcion != 4);

    return 0;
}
