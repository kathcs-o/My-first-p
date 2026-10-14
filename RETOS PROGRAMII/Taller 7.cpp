#include <iostream>
using namespace std;


// FUNCIÓN 1
// Solicita al usuario que ingrese numeros y los almacena en un arreglo

void cargarNumeros(int numeros[], int cantidad) {

    for (int i = 0; i < cantidad; i++) {
        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> numeros[i];
    }
}

// Función 2
// Muestra los numeros almacenados en el arreglo de funcion 1

void mostrarArreglo(int arreglo[], int cantidad) {

    for (int i = 0; i < cantidad; i++) {
        cout << arreglo[i] << " ";
    }

    cout << endl;
}

// Función 3
// Separa los numeros en positivos, negativos y ceros y los almacena en arreglos separados

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

// Función 4
// Calcula suma de todos los numeros que estan en el arreglo de funcion 1
int calcularSuma(int numeros[], int cantidad) {

    int suma = 0;

    for (int i = 0; i < cantidad; i++) {
        suma += numeros[i];
    }

    return suma;
}

// Función 5
// Calcula promedio de todos los numeros que estan en el arreglo de funcion 1
float calcularPromedio(int numeros[], int cantidad) {

    int suma = 0;

    for (int i = 0; i < cantidad; i++) {
        suma += numeros[i];
    }

    return (float)suma / cantidad;
}

// Función 6
// Encuentra el numero mayor y el numero menor en el arreglo de funcion 1
void encontrarMayorMenor(int numeros[], int cantidad,
                         int &mayor, int &menor) {

    mayor = numeros[0];
    menor = numeros[0];

    for (int i = 1; i < cantidad; i++) {

        if (numeros[i] > mayor) {
            mayor = numeros[i];
        }

        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }
}

// Función 7
// Cuenta los numeros positivos, numeros negativos y ceros en el arreglo de funcion 1
void contarNumeros(int numeros[], int cantidad,
                   int &positivos, int &negativos, int &ceros) {

    for (int i = 0; i < cantidad; i++) {

        if (numeros[i] > 0) {
            positivos++;
        }
        else if (numeros[i] < 0) {
            negativos++;
        }
        else {
            ceros++;
        }
    }
}


int main() {

    const int MAX = 100;   //tamaño maximo de los arreglos

    // arreglos
    int numeros[MAX];
    int pares[MAX];
    int impares[MAX];

    // variables
    int cantidad;
    int cantidadPares = 0;
    int cantidadImpares = 0;

    // variables para guardar el mayor y el menor
    int mayor;
    int menor;

    // Declara los contadores de positivos, negativos y ceros
    int positivos = 0;
    int negativos = 0;
    int ceros = 0;

    cout << endl;
    cout << "REGISTRO Y ANALISIS DE NUMEROS" << endl;
    cout << endl;

    cout << "Ingrese la cantidad de numeros: ";
    cin >> cantidad;

    cargarNumeros(numeros, cantidad);   // llamado de la funcion 1

    cout << "Numeros ingresados: ";
    mostrarArreglo(numeros, cantidad);  // llamado de la funcion 2

    separarNumeros(numeros, pares, impares, cantidad, cantidadPares, cantidadImpares);  // llamado de la funcion 3

    cout << "Numeros pares: ";
    mostrarArreglo(pares, cantidadPares);  // llamado de la funcion 2

    cout << "Numeros impares: ";
    mostrarArreglo(impares, cantidadImpares);  // llamado de la funcion 2

    cout << endl;

    int suma = calcularSuma(numeros, cantidad);  // llamado de la funcion 4

    cout << "Suma de los numeros: " << suma << endl;

    float promedio = calcularPromedio(numeros, cantidad);  // llamado de la funcion 5

    cout << "Promedio: " << promedio << endl;

    encontrarMayorMenor(numeros, cantidad, mayor, menor);  // llamado de la funcion 6

    cout << "Numero mayor: " << mayor << endl;
    cout << "Numero menor: " << menor << endl;

    contarNumeros(numeros, cantidad, positivos, negativos, ceros);  // llamado de la funcion 7

    cout << endl;

    cout << "Cantidad de positivos: " << positivos << endl;
    cout << "Cantidad de negativos: " << negativos << endl;
    cout << "Cantidad de ceros: " << ceros << endl;


    return 0;
}
