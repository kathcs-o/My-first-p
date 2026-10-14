#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// ---------------------------------------------------------
// FUNCION 1: Obtiene la tarifa por unidad según el tipo de servicio
// ---------------------------------------------------------
double obtenerTarifaUnidad(int tipoServicio) {
    if (tipoServicio == 1) {
        return 1500.0;
    } else if (tipoServicio == 2) {
        return 2500.0;
    } else {
        return 4000.0;
    }
}

// ---------------------------------------------------------
// FUNCION 2: Calcula el valor inicial (Tarifa * Unidades)
// ---------------------------------------------------------
double calcularValorInicial(int tipoServicio, double unidades) {
    return obtenerTarifaUnidad(tipoServicio) * unidades;
}

// ---------------------------------------------------------
// FUNCION 3: Calcula el descuento total (Consumo > 100 y/o Membresia)
// ---------------------------------------------------------
double calcularDescuento(double valorInicial, double unidades, char membresia) {
    double porcentajeDescuento = 0.0;

    if (unidades > 100) {
        porcentajeDescuento += 0.10; // 10% por superar 100 unidades
    }

    // Se valida minúscula o mayúscula
    if (membresia == 'S' || membresia == 's') {
        porcentajeDescuento += 0.05; // 5% adicional por membresia
    }

    return valorInicial * porcentajeDescuento;
}

// ---------------------------------------------------------
// FUNCION 4: Calcula el valor final a pagar
// ---------------------------------------------------------
double calcularTotal(double valorInicial, double descuento) {
    double total = valorInicial - descuento;
    if (total < 0) {
        return 0; // El valor final no puede ser negativo
    }
    return total;
}

// ---------------------------------------------------------
// FUNCION 5: Muestra la información de un cliente
// ---------------------------------------------------------
void mostrarDatosCliente(string nombre, int tipoServicio, double unidades, double valorInicial, double descuento, double total) {
    cout << "\n---------- FACTURA / CLIENTE ----------" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Tipo de servicio: ";
    if (tipoServicio == 1) cout << "Basico" << endl;
    else if (tipoServicio == 2) cout << "Premium" << endl;
    else cout << "Empresarial" << endl;

    cout << "Unidades consumidas: " << unidades << endl;
    cout << "Valor inicial: $" << valorInicial << endl;
    cout << "Descuento aplicado: $" << descuento << endl;
    cout << "Valor final a pagar: $" << total << endl;
}

// ---------------------------------------------------------
// FUNCION 6: Muestra el resumen general
// ---------------------------------------------------------
void mostrarResumen(int totalClientes, double totalFacturado, int clientesMembresia, double promedioPagado) {
    cout << "\n========================================" << endl;
    cout << "           RESUMEN GENERAL              " << endl;
    cout << "========================================" << endl;
    cout << "Cantidad total de clientes registrados: " << totalClientes << endl;
    cout << "Valor total facturado: $" << totalFacturado << endl;
    cout << "Cantidad de clientes con membresia: " << clientesMembresia << endl;
    cout << "Promedio del valor pagado por cliente: $" << promedioPagado << endl;
}

// ---------------------------------------------------------
// PROGRAMA PRINCIPAL
// ---------------------------------------------------------
int main() {
    int cantidadClientes;
    int clientesMembresia = 0;
    double totalFacturado = 0;

    cout << fixed << setprecision(2);

    cout << "========================================" << endl;
    cout << "  GESTION DE CONSUMO MENSUAL DE CLIENTES " << endl;
    cout << "========================================" << endl;

    cout << "Ingrese la cantidad de clientes a registrar: ";
    cin >> cantidadClientes;

    while (cantidadClientes <= 0) {
        cout << "La cantidad debe ser mayor que cero. Ingrese nuevamente: ";
        cin >> cantidadClientes;
    }

    for (int i = 1; i <= cantidadClientes; i++) {
        string nombre;
        int tipoServicio;
        double unidades;
        char membresia;

        cout << "\n========== REGISTRO CLIENTE " << i << " ==========" << endl;

        // Lectura directa del nombre sin cin.ignore() ni getline()
        cout << "Nombre del cliente: ";
        cin >> nombre;

        cout << "Seleccione el tipo de servicio:\n 1. Basico ($1.500/u)\n 2. Premium ($2.500/u)\n 3. Empresarial ($4.000/u)\nOpcion: ";
        cin >> tipoServicio;

        while (tipoServicio < 1 || tipoServicio > 3) {
            cout << "Opcion invalida. Ingrese 1, 2 o 3: ";
            cin >> tipoServicio;
        }

        cout << "Cantidad de unidades consumidas: ";
        cin >> unidades;

        while (unidades < 0) {
            cout << "Las unidades no pueden ser negativas. Ingrese nuevamente: ";
            cin >> unidades;
        }

        cout << "Tiene membresia especial (S/N): ";
        cin >> membresia;

        // Validación simple sin toupper()
        while (membresia != 'S' && membresia != 's' && membresia != 'N' && membresia != 'n') {
            cout << "Opcion invalida. Ingrese S o N: ";
            cin >> membresia;
        }

        if (membresia == 'S' || membresia == 's') {
            clientesMembresia++;
        }

        // Procesos
        double valorInicial = calcularValorInicial(tipoServicio, unidades);
        double descuento = calcularDescuento(valorInicial, unidades, membresia);
        double valorFinal = calcularTotal(valorInicial, descuento);

        totalFacturado += valorFinal;

        // Salida individual
        mostrarDatosCliente(nombre, tipoServicio, unidades, valorInicial, descuento, valorFinal);
    }

    // Promedio
    double promedioPagado = totalFacturado / cantidadClientes;

    // Resumen Final
    mostrarResumen(cantidadClientes, totalFacturado, clientesMembresia, promedioPagado);

    return 0;
}
