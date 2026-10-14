#include <iostream>
#include <iomanip>
using namespace std;


 int main(){
	
	//ENTRADAS
string Nombre;
int Valorcompra = 0.0;
char Membresia;
double Porcentajedescuento = 0.0;
double Descuento = 0.0;
double TotalPagar = 0.0;
int totalClientes = 0;
	
   // 1. Pedir inicialmente la cantidad de clientes
    cout << "Ingrese la cantidad de clientes que seran atendidos: ";
    cin >> totalClientes;
	
	for (int i = 1; i <= totalClientes; i++) 
		
	do{
cout << "Ingrese nombre completo:";
cin >> Nombre;
	
cout << "Ingrese valor de la compra:\n";
cin >> Valorcompra;
	
cout << "Cuenta con membresia? S/N:\n";
cin >> Membresia;	


    
    if (Valorcompra >= 500000){
	Porcentajedescuento = 20;
}else if (Valorcompra >= 200000 && Valorcompra <= 499999){
         Porcentajedescuento = 10;     
}else{ 
	Porcentajedescuento = 5;}      

          
 if (Membresia == 'S' || Membresia == 's') {
        Porcentajedescuento += 5;}
		 
 Descuento = Valorcompra * Porcentajedescuento / 100.0;
    TotalPagar = Valorcompra - Descuento;		 

	}while(Valorcompra < 0);
	
	
	


    cout << "\n----- RESUMEN DE LA COMPRA -----" << endl;
    cout << "Nombre completo: " << Nombre  << endl;
    cout << "Valor de la compra: $" << Valorcompra << endl;
    cout << "Descuento aplicado: " << Porcentajedescuento << "%" << endl;
    cout << "Valor descontado: $" << Descuento << endl;
    cout << "Total a pagar: $" << TotalPagar << endl;
	
	
	
	return 0;
}
