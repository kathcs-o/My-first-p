/*
ENUNCIADO:

Una tienda necesita calcular el valor total de una compra.

El programa debe solicitar al usuario:
- El precio de un producto.
- La cantidad de unidades compradas.
- El porcentaje de descuento.

Luego debe calcular:

1. El subtotal de la compra:
   subtotal = precio × cantidad

2. El valor del descuento:
   valorDescuento = subtotal × porcentajeDescuento / 100

3. El total a pagar:
   total = subtotal - valorDescuento

Finalmente, el programa debe mostrar:
- El subtotal.
- El valor del descuento.
- El total a pagar.

Ejemplo:

Precio: 80000
Cantidad: 3
Descuento: 15%

Resultado esperado:

Subtotal: $240000
Descuento: $36000
Total a pagar: $204000
*/

#include <iostream>
using namespace std;

int main() {

    double precio;
    int cantidad;
    double porcentajeDescuento;

    cout << "Ingrese el precio del producto: ";
    cin >> precio;

    cout << "Ingrese la cantidad: ";
    cin >> cantidad;

    cout << "Ingrese el porcentaje de descuento: ";
    cin >> porcentajeDescuento;

    // Calcular el subtotal
    double subtotal = precio * cantidad;

    // Calcular el valor del descuento
    double valorDescuento = subtotal * porcentajeDescuento / 100;

    // Calcular el total a pagar
    double total =
        subtotal - valorDescuento;

    // Mostrar los resultados
    cout << "\n--- RESUMEN DE LA COMPRA ---" << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Descuento: $" << valorDescuento << endl;
    cout << "Total a pagar: $" << total << endl;

    return 0;
}