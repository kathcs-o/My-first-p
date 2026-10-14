/*
"Este programa calcula la nota final de una materia basándose en tres notas parciales con pesos del 30%, 30% y 40% respectivamente.
Utiliza variables de tipo float para manejar decimales.
Primero realiza la operación matemática multiplicando cada nota por su peso y sumándolas.
Luego, mediante una estructura condicional if-else,
verifica si la nota final es mayor o igual a 3.0 para determinar si el alumno aprobó o reprobó, mostrando el resultado en consola."
*/




#include <stdio.h>



int main() {


    float nota1 = 3.8f;
    float nota2 = 4.2f;
    float nota3 = 2.9f;
    float peso1 = 0.30;
    float peso2 = 0.30;
    float peso3 = 0.40;
    float notafinal;

    notafinal = (nota1 * peso1) + (nota2 * peso2) + (nota3 * peso3);
    printf("Nota: %.1f\n", notafinal);

    if (notafinal >= 3.0) {
        printf("Resultado: Excelente, aprobaste\n");
    } else {
        printf("Resultado: No pasaste, :( no te rindas\n");
    }

    return 0;
}

