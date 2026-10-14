#include <iostream>
using namespace std;

// Función para separar los números
void separarNumeros(int numeros[], int pares[], int impares[],
                    int cantidad, int &cantidadPares, int &cantidadImpares) {

    for (int i = 0; i < cantidad; i++) {

        if (numeros[i] % 2 == 0) {
            pares[cantidadPares] = numeros[i];
            cantidadPares++;
        }
        else {
            impares[cantidadImpares] = numeros[i];
            cantidadImpares++;
        }
    }
}

// Función para mostrar un arreglo
void mostrarArreglo(int arreglo[], int cantidad) {

    for (int i = 0; i < cantidad; i++) {
        cout << arreglo[i] << " ";
    }

    cout << endl;
}

int main() {

    int CANTIDAD = 10;

    int numeros[CANTIDAD];
    int pares[CANTIDAD];
    int impares[CANTIDAD];

    int cantidadPares = 0;
    int cantidadImpares = 0;

    // Ingresar los números
    for (int i = 0; i < CANTIDAD; i++) {

        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> numeros[i];
    }

    // Separar los números
    separarNumeros(
        numeros,
        pares,
        impares,
        CANTIDAD,
        cantidadPares,
        cantidadImpares
    );

    // Mostrar resultados
    cout << "\nNumeros pares: ";
    mostrarArreglo(pares, cantidadPares);

    cout << "Numeros impares: ";
    mostrarArreglo(impares, cantidadImpares);

    return 0;
}