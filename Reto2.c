/*
Este programa calcula la nota exacta que un estudiante necesita obtener en su cuarto parcial para aprobar la materia con una meta de 3.0.
El sistema toma tres notas ya obtenidas con sus respectivos porcentajes (20%, 25% y 25%) [8-10] y calcula el puntaje acumulado hasta el momento.
Luego, resta ese acumulado a la meta y lo divide por el porcentaje del cuarto parcial (30%) [11, 17] para hallar la nota requerida.
Finalmente, un condicional if-else verifica si esa nota es alcanzable (es decir, si está entre 0.0 y 5.0). En caso afirmativo, muestra que el estudiante aún 'Cumple' con la posibilidad de pasar

*/




#include <stdio.h>

int main(){
	
	float Nota1 = 3.5;
	float Nota2 = 2.8;
	float Nota3 = 4.0;
	float Porcent1 = 0.20;
	float Porcent2 = 0.25;
	float Porcent3 = 0.25;
	float Porcent4 = 0.30;
	float Meta = 3.0;
	float Acumulado;
	float NotaNecesaria;
	
	Acumulado = (Nota1 * Porcent1)+(Nota2 * Porcent2)+(Nota3 * Porcent3);
	NotaNecesaria = (Meta - Acumulado) /Porcent4;
	
	
	printf("Nota final: %.2f\n", NotaNecesaria);
	if(NotaNecesaria >= 0.0 && NotaNecesaria <= 5.0){
		printf("Cumple\n");
	}else{
		printf("No cumple\n");
	}
	
	
	return 0;
	
	
	
}
