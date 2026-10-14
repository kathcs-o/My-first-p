/*
ENUNCIADO:

Una sala de cine necesita un programa para registrar las reservas
de una función.

El programa debe solicitar la cantidad de personas que desean
reservar.

Para cada persona se debe solicitar:
- Nombre.
- Edad.
- Tipo de entrada:
    1. General: $15.000
    2. Estudiante: $10.000
    3. Adulto mayor: $8.000

Reglas:
- Los menores de 12 años reciben un descuento adicional del 20%.
- Los estudiantes tienen un precio especial.
- Los adultos mayores tienen un precio especial.
- La edad no puede ser negativa.
- El tipo de entrada debe ser válido.

Al finalizar mostrar:
- Cantidad de personas registradas.
- Cantidad de entradas generales.
- Cantidad de entradas de estudiante.
- Cantidad de entradas de adulto mayor.
- Valor total recaudado.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


// ---------------------------------------------------------
// FUNCION 1
// Determina el precio base según el tipo de entrada.
// ---------------------------------------------------------

double obtenerPrecio(int tipoEntrada) {

    if (tipoEntrada == 1) {
        return 15000;

    } else if (tipoEntrada == 2) {
        return 10000;

    } else {
        return 8000;
    }
}


// ---------------------------------------------------------
// FUNCION 2
// Calcula el descuento para menores de 12 años.
// ---------------------------------------------------------

double calcularDescuento(double precio, int edad) {

    if (edad < 12) {
        return precio * 0.20;
    }

    return 0;
}


// ---------------------------------------------------------
// FUNCION 3
// Calcula el valor final de la entrada.
// ---------------------------------------------------------

double calcularTotal(double precio, double descuento) {

    return precio - descuento;
}


// ---------------------------------------------------------
// FUNCION 4
// Muestra la información de una reserva.
// ---------------------------------------------------------

void mostrarReserva(
    string nombre,
    double precio,
    double descuento,
    double total
) {

    cout << "\n---------- RESERVA ----------" << endl;

    cout << "Cliente: " << nombre << endl;
    cout << "Precio base: $" << precio << endl;
    cout << "Descuento: $" << descuento << endl;
    cout << "Total a pagar: $" << total << endl;
}


// ---------------------------------------------------------
// FUNCION 5
// Muestra el resumen general.
// ---------------------------------------------------------

void mostrarResumen(
    int personas,
    int generales,
    int estudiantes,
    int adultosMayores,
    double totalRecaudado
) {

    cout << "\n================================" << endl;
    cout << "       RESUMEN DE LA FUNCION    " << endl;
    cout << "================================" << endl;

    cout << "Personas registradas: "
         << personas << endl;

    cout << "Entradas generales: "
         << generales << endl;

    cout << "Entradas estudiantes: "
         << estudiantes << endl;

    cout << "Entradas adultos mayores: "
         << adultosMayores << endl;

    cout << "Total recaudado: $"
         << totalRecaudado << endl;
}


// ---------------------------------------------------------
// PROGRAMA PRINCIPAL
// ---------------------------------------------------------

int main() {

    int cantidadPersonas;

    int entradasGenerales = 0;
    int entradasEstudiantes = 0;
    int entradasAdultosMayores = 0;

    double totalRecaudado = 0;

    cout << "================================" << endl;
    cout << "      RESERVAS DE CINE          " << endl;
    cout << "================================" << endl;

    cout << "Ingrese la cantidad de personas: ";
    cin >> cantidadPersonas;


    // Validación de la cantidad de personas

    while (cantidadPersonas <= 0) {

        cout << "La cantidad debe ser mayor que cero."
             << endl;

        cout << "Ingrese nuevamente la cantidad: ";
        cin >> cantidadPersonas;
    }


    // Ciclo para registrar las personas

    for (int i = 1; i <= cantidadPersonas; i++) {

        string nombre;

        int edad;
        int tipoEntrada;

        double precio;
        double descuento;
        double total;


        cout << "\n========== PERSONA "
             << i << " ==========" << endl;


        // Entrada de datos

        cout << "Nombre: ";
        cin >> nombre;


        cout << "Edad: ";
        cin >> edad;


        // Validar edad

        while (edad < 0) {

            cout << "La edad no puede ser negativa."
                 << endl;

            cout << "Ingrese nuevamente la edad: ";
            cin >> edad;
        }


        // Seleccionar tipo de entrada

        cout << "\nTipo de entrada:" << endl;
        cout << "1. General      $15000" << endl;
        cout << "2. Estudiante   $10000" << endl;
        cout << "3. Adulto mayor $8000" << endl;

        cout << "Seleccione una opcion: ";
        cin >> tipoEntrada;


        // Validar tipo de entrada

        while (
            tipoEntrada < 1 ||
            tipoEntrada > 3
        ) {

            cout << "Tipo de entrada invalido."
                 << endl;

            cout << "Seleccione nuevamente: ";
            cin >> tipoEntrada;
        }


        // Obtener precio

        precio = obtenerPrecio(tipoEntrada);


        // Calcular descuento

        descuento = calcularDescuento(precio, edad);


        // Calcular total

        total = calcularTotal(precio, descuento);


        // Actualizar contadores

        if (tipoEntrada == 1) {

            entradasGenerales++;

        } else if (tipoEntrada == 2) {

            entradasEstudiantes++;

        } else {

            entradasAdultosMayores++;
        }


        // Acumular dinero

        totalRecaudado += total;


        // Mostrar información

        mostrarReserva(
            nombre,
            precio,
            descuento,
            total
        );
    }


    // Mostrar resumen final

    mostrarResumen(
        cantidadPersonas,
        entradasGenerales,
        entradasEstudiantes,
        entradasAdultosMayores,
        totalRecaudado
    );


    return 0;
}