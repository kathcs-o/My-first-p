#include <iostream>
using namespace std;

int main(){
	
	int anio;
	bool Bisiesto;
	
	
	// Primero pide el dato
	cout << "Ingrese el anio: ";
    cin >> anio;
    
    // Calcular después de tener el dato real
   	Bisiesto = (anio % 400 == 0) || (anio % 4 == 0 && anio % 100 != 0);
	
	// Mostrar resultado usando booleano
	if (Bisiesto){
	cout << "Es bisiesto";
	} else{
		cout << "No es bisiesto";
	}
	
	return 0;
	
	}
	
	
	
	
	
	
	
	
