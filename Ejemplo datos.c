/* Ejemplo muy breve de los tipos de datos que solicitaste */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

int main(void) {
    /* ---- Entero (int) ---- */
    int a = 10;
    int b = 3;
    int suma = a + b;
    int resta = a - b;
    int producto = a * b;
    int division = a / b; // división entera
    printf("Entero int (32 bits) %d a %d\n", INT_MIN, INT_MAX);
    printf("  Operaciones: %d+%d=%d, %d-%d=%d, %d*%d=%d, %d/%d=%d\n",
           a, b, suma, a, b, resta, a, b, producto, a, b, division);

    /* ---- Flotante (float) ---- */
    float f1 = 3.14159f;
    float f2 = 2.0f;
    float f_mul = f1 * f2;
    printf("Flotante float 4 Bytes %.5f (6-7 dígitos de precisión)\n", f1);
    printf("  Multiplicación: %.5f * %.5f = %.5f\n", f1, f2, f_mul);

    /* ---- Doble precisión (double) ---- */
    double d1 = 2.718281828459045;
    double d2 = 2.0;
    double d_div = d1 / d2;
    printf("Doble Precision double 8 Bytes %.15lf (Precisión de 15-17 dígitos)\n", d1);
    printf("  División: %.15lf / %.1lf = %.15lf\n", d1, d2, d_div);

    /* ---- Carácter (char) ---- */
    char c = 'A';
    char next = c + 1; // 'B'
    printf("Carácter char 1 Byte '%c' (Código ASCII)\n", c);
    printf("  Siguiente carácter: '%c'\n", next);

    /* ---- Booleano (bool) ---- */
    bool b_true = true;
    bool b_false = false;
    bool logic_and = b_true && b_false;
    bool logic_or  = b_true || b_false;
    printf("Booleano bool 1 Byte %s (1) o false (0)\n", b_true ? "true" : "false");
    printf("  Operaciones lógicas: true && false = %s, true || false = %s\n",
           logic_and ? "true" : "false",
           logic_or  ? "true" : "false");

    return 0;
}