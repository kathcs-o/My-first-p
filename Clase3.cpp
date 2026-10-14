/*
ENUNCIADO:

Una tienda desea calcular el valor final de una compra.

El programa debe solicitar:
- El valor de la compra.
- Si el cliente tiene membresía.

Descuentos:
- Compra mayor o igual a $500.000: 20 %.
- Compra entre $200.000 y $499.999: 10 %.
- Compra inferior a $200.000: 5 %.

Si el cliente tiene membresía, recibe un 5 % adicional.

Mostrar:
- Valor de la compra.
- Porcentaje de descuento.
- Valor descontado.
- Total a pagar.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double compra;
    char membresia;
    double porcentajeDescuento;
    double valorDescuento;
    double totalPagar;

    cout << "Ingrese el valor de la compra: $";
    cin >> compra;

    cout << "¿Tiene membresia? (S/N): ";
    cin >> membresia;

    // Determinar el descuento según el valor de la compra
    if (compra >= 500000) {
        porcentajeDescuento = 20;
    } else if (compra >= 200000) {
        porcentajeDescuento = 10;
    } else {
        porcentajeDescuento = 5;
    }

    // Descuento adicional por tener membresía
    if (membresia == 'S' || membresia == 's') {
        porcentajeDescuento += 5;
    }

    // Calcular los valores finales
    valorDescuento = compra * porcentajeDescuento / 100;
    totalPagar = compra - valorDescuento;

    cout << fixed << setprecision(2);

    cout << "\n----- RESUMEN DE LA COMPRA -----" << endl;
    cout << "Valor de la compra: $" << compra << endl;
    cout << "Descuento aplicado: " << porcentajeDescuento << "%" << endl;
    cout << "Valor descontado: $" << valorDescuento << endl;
    cout << "Total a pagar: $" << totalPagar << endl;

    return 0;
}