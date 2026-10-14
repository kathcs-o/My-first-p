#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


// ---------------------------------------------------------
// FUNCION 1
// Determina el precio base según el tipo de entrada.
// ---------------------------------------------------------

double Tarifa(int tipoServicio) {

    if (tipoServicio == 1) {
        return 1500;

    } else if (tipoServicio == 2) {
        return 2500;

    } else {
        return 4000;
    }
}


// ---------------------------------------------------------
// FUNCION 2
// Calcula el descuento según tipo de servicio
// ---------------------------------------------------------

double calcularDescuento(double precio, double unidades) {

    if (unidades > 100) {
        return precio * 0.10;
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

void mostrarDatos(
    string nombre,
    double precio,
    double descuento,
    double total
) {

    cout << "\n---------- LISTADO ----------" << endl;

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
    int Personas,
    int Basico,
    int Premium,
    int Empresarial,
    double CantidadConsumo,
    double Membresia,
    double Descuento,
    double TotalPagar
    
    
) {

    cout << "\n================================" << endl;
    cout << "       RESUMEN DE LA FUNCION    " << endl;
    cout << "================================" << endl;

    cout << "Personas registradas: "
         << Personas << endl;

    cout << "Servicio basico: "
         << Basico << endl;

    cout << "Servicio premium: "
         << Premium << endl;

    cout << "Servicio empresarial: "
         << Empresarial << endl;
         
    cout << "Tiene membresia? S/N: $"
         << Membresia << endl;
         
    cout << "Cantidad consumida en unidades: $"
         << CantidadConsumo << endl;

    cout << "Descuento por tipo de servicio: $"
         << Descuento << endl;
         
    cout << "Total recaudo: $"
         << TotalPagar << endl;
}


// ---------------------------------------------------------
// PROGRAMA PRINCIPAL
// ---------------------------------------------------------

int main() {
	
	int cantidadPersonas;

    int ServicioBasico = 0;
    int ServicioPremium = 0;
    int ServicioEmpresarial = 0;
    int conMembresia = 0;
    double totalRecaudado = 0, totalDescuentos = 0, CantidadConsumo= 0;
    
    

 cout << "================================" << endl;
    cout << "    CONSUMO MENSUAL DE CLIENTES VIP   " << endl;
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

int unidades; // o double unidades;
cout << "Ingrese la cantidad de unidades: ";
cin >> unidades;



    // Ciclo para registrar las personas

    for (int i = 1; i <= cantidadPersonas; i++) {

        string nombre;

        double Servicio;

        double precio;
        double descuento;
        double total;


        cout << "\n========== PERSONA "
             << i << " ==========" << endl;


        // Entrada de datos

        cout << "Nombre: ";
        cin >> nombre;

        cout << "Tipo de servicio: ";
        cin >> Servicio;
        
        

// Seleccionar tipo de entrada

        cout << "\nTipo de servicio:" << endl;
        cout << "1. Basico   $1500" << endl;
        cout << "2. Premium $2500" << endl;
        cout << "3. Empresarial $4500" << endl;

        cout << "Seleccione una opcion: ";
        cin >> Servicio;


        // Validar tipo de entrada

        while (
            Servicio < 1 ||
            Servicio > 3
        ) {

            cout << "Tipo de entrada invalido."
                 << endl;

            cout << "Seleccione nuevamente: ";
            cin >> Servicio;
        }



 // Obtener precio

        precio = Tarifa( Servicio);


        // Calcular descuento

        descuento = calcularDescuento(precio, unidades);


        // Calcular total

        total = calcularTotal(precio, descuento);


        // Actualizar contadores

        if (Servicio == 1) {

           ServicioBasico++;

        } else if (Servicio == 2) {

            ServicioPremium++;

        } else {

            ServicioEmpresarial++;
        }


        // Acumular dinero

        totalRecaudado += total;


        // Mostrar información

        mostrarDatos(
            nombre,
            precio,
            descuento,
            total
        );
    }


    // Mostrar resumen final

   mostrarResumen(
    cantidadPersonas,
    ServicioBasico,
    ServicioPremium,
    ServicioEmpresarial,
    conMembresia,
    totalRecaudado, 
	totalDescuentos, 
	CantidadConsumo
    );


    return 0;
}






