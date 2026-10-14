#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <limits>
using namespace std;

int main() {

cout << "     SISTEMA DE VENTAS DE LA TIENDA     \n";

    int cantidadClientes;
    double totalCompras = 0, totalDescuentos = 0, totalRecaudado = 0;
    int conMembresia = 0;

        do {                    // Validar cantidad de clientes
        cout << "Cantidad de clientes a atender: ";
        cin >> cantidadClientes;
        if (cantidadClientes <= 0) {
            cout << "Debe ser mayor que 0.\n";
        }
    } while (cantidadClientes <= 0);

    cout << fixed << setprecision(2);

    for (int i = 1; i <= cantidadClientes; i++) {
        string nombre;
        double compra;
        char membresia;

        cout << "\n--- CLIENTE " << i << " ---\n";

        cin.ignore(); // limpiar el salto de linea pendiente
        cout << "Nombre: ";
        getline(cin, nombre);

        do {               // Validar valor de la compra   
            cout << "Valor de la compra: $";
            cin >> compra;
            if (compra <= 0) {
                cout << "El valor debe ser mayor que 0.\n";
            }
        } while (compra <= 0);

                do {          // Validar membresia (S o N)
            cout << "Tiene membresia (S/N): ";
            cin >> membresia;
            membresia = toupper(membresia);
            if (membresia != 'S' && membresia != 'N') {
                cout << "Ingrese S o N.\n";
            }
        } while (membresia != 'S' && membresia != 'N');

        int porcentaje;         // Calcular porcentaje de descuento
        if (compra >= 500000) {
            porcentaje = 20;
        } else if (compra >= 200000) {
            porcentaje = 10;
        } else {
            porcentaje = 5;
        }

        if (membresia == 'S') {
            porcentaje += 5;
            conMembresia++;
        }

        double descuento = compra * porcentaje / 100;
        double total = compra - descuento;

        cout << "\n--- FACTURA DEL CLIENTE " << i << " ---\n";
        
        cout << "\nNombre: " << nombre << endl;    // Mostrar resultado del cliente
        cout << "Valor de la compra: $" << compra << endl;
        cout << "Porcentaje de descuento: " << porcentaje << "%" << endl;
        cout << "Valor descontado: $" << descuento << endl;
        cout << "Total a pagar: $" << total << endl;

        // Acumular totales
        totalCompras += compra;
        totalDescuentos += descuento;
        totalRecaudado += total;
    }

    // Resumen final

    cout << "\n--- RESUMEN FINAL ---\n";
    cout << "Clientes atendidos: " << cantidadClientes << endl;
    cout << "Total compras (sin descuento): $" << totalCompras << endl;
    cout << "Total descuentos otorgados: $" << totalDescuentos << endl;
    cout << "Total recaudado: $" << totalRecaudado << endl;
    cout << "Clientes con membresia: " << conMembresia << endl;

    return 0;
}