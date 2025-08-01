#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    const int FILAS = 3;
    const int COLUMNAS = 10;

    // Series correctas
    int serie1[COLUMNAS] = {1, 3, 6, 10, 15, 21, 28, 36, 45, 55};    
    int serie2[COLUMNAS] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};    
    int serie3[COLUMNAS] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};         

    int matriz[FILAS][COLUMNAS]; 

    cout << "DESCIFRAR EL CODIGO SECRETO\n";
    cout << "Ingresa 10 numeros enteros por cada fila separados por espacios.\n";

    for (int i = 0; i < FILAS; i++) {
        while (true) {
            cout << "Fila " << i + 1 << ": ";
            string linea;
            getline(cin, linea); 

            stringstream ss(linea);
            vector<int> numeros;
            int num;
            string palabra;

            bool error = false;

            while (ss >> palabra) {
                try {
                    num = stoi(palabra); 
                    numeros.push_back(num);
                } catch (...) {
                    cout << "Entrada invalida detectada: '" << palabra << "'. Intenta de nuevo\n";
                    error = true;
                    break;
                }
            }

            if (!error && numeros.size() == COLUMNAS) {
                for (int j = 0; j < COLUMNAS; j++) {
                    matriz[i][j] = numeros[j];
                }
                break; 
            } else if (!error) {
                cout << "Debes ingresar exactamente 10 numeros\n";
            }
        }
    }
 
    int codigo[3];

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            int correcto;
            if (i == 0) correcto = serie1[j];
            else if (i == 1) correcto = serie2[j];
            else correcto = serie3[j];

            if (matriz[i][j] != correcto) {
                codigo[i] = matriz[i][j]; 
                break; 
            }
        }
    }

    cout << "\nCodigo secreto encontrado: " << codigo[0] << "-" << codigo[1] << "-" << codigo[2] << endl;

    return 0;
}

