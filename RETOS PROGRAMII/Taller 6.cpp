#include <iostream>
#include <iomanip>
using namespace std;


// Función que muestra arreglo

    void CargarNotas(float notas[], int cantidad) {

     for (int i = 0; i < cantidad; i++) {
        float nota;


// Ciclo para validar la nota
        do {
            cout << "Ingrese la nota del estudiante " << i + 1 << " (0.0 a 5.0): ";
            cin >> nota;
            
            if (nota < 0.0 || nota > 5.0) {
                cout << "Error: Nota invalida. Intente de nuevo." << endl;
            }
        } while (nota < 0.0 || nota > 5.0);
        
        // Guardamos la nota validada en el arreglo
        notas[i] = nota;
    }
    }


    // Función para mostrar las notas guardadas
   void mostrarNotas(float notas[], int cantidad) {
    
    cout << "\n--- LISTA DE NOTAS ---" << endl;
    
    cout << fixed << setprecision(1);
    for (int i = 0; i < cantidad; i++) {
        cout << "Estudiante " << i + 1 << ": " << notas[i] << endl;
    }
    
    cout << "----------------------" << endl;
    }

// Función para calcular el promedio
float calcularPromedio(float notas[], int cantidad) {
    float suma = 0.0;
    
    for (int i = 0; i < cantidad; i++) {
        suma = suma + notas[i]; // También puedes usar: suma += notas[i];
    }
    
    return suma / cantidad;
}


//Función principal

int main() {
    
    int MAX_ESTUDIANTES = 100;
    float notas[MAX_ESTUDIANTES]; 
    int numEstudiantes;

   
    cout << "Cuantos estudiantes va a registrar? ";
    cin >> numEstudiantes;

    
    if (numEstudiantes <= 0 || numEstudiantes > MAX_ESTUDIANTES) {
    cout << "Error: Cantidad invalida. Debe ser entre 1 y " << MAX_ESTUDIANTES << endl;
    return 1; 
    }

    cout << "Vas a registrar " << numEstudiantes << " estudiante(s)." << endl;




    // Llama Función para cargar las notas
    CargarNotas(notas, numEstudiantes);
    
    // Mostrar las notas que se guardaron
    mostrarNotas(notas, numEstudiantes);



    // --- Cálculo de Mayor y Menor 
    
    float mayor = notas[0]; // Asumimos que la primera es la mayor
    float menor = notas[0]; // Asumimos que la primera es la menor
    
    for (int i = 1; i < numEstudiantes; i++) {
     if (notas[i] > mayor) {
    mayor = notas[i];
   }
   if (notas[i] < menor) {
    menor = notas[i];
    }
    }
    
    cout << "La nota mayor es: " << mayor << endl;
    cout << "La nota menor es: " << menor << endl;
    
    
    
    // Calcular y mostrar el promedio
    float promedio = calcularPromedio(notas, numEstudiantes);
    cout << "\nEl promedio del grupo es: " << promedio << endl;
    
    
    return 0;
}










