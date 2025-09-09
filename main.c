#include <stdio.h>
#include "include/header.h"

int main ()
{
    int n = 100;
    printf("La suma de los %d numeros naturales es: %d\n\n", n, suma_n(n));
    //Ejercicio 1

    int n1 = 4, n2 = 9;
    printf("El producto de %d y %d es igual a: %d\n\n", n1, n2, producto_n(n1, n2));
    //Ejercicio 2

    print_fibonacci(5, 0);
    printf("\n");
    print_fibonacci(cant_fibonacci(6, 1), 0);
    //Ejercicio 3

    printf("\n\n");
    float n3 = 2.0; 
    int n4 = -2;
    printf("La potencia de %.1f a la %d es igual a: %.4f\n\n", n3, n4, potencia_n(n3, n4));
    //Ejercicio 4

    return 0;
}

int suma_n(int i) //Ejercicio 1
{
    int r = 0;
    if (i > 0) {
        r = i + suma_n(i-1);
    }
    return r;
}

int producto_n(int i1, int i2) //Ejercicio 2
{
    int r = 0;
    if(i2 > 0) {
        r = i1 + producto_n(i1, i2-1);
    }
    return r;
}

int fibonacci(int i) //Ejercicio 3
{
    int r = 1;
    if (i > 1) {
        r = fibonacci(i-1) + fibonacci(i-2);
    }
    return r;
}

void print_fibonacci(int n, int i) { //Ejercicio 3
    if (i < n) {
        printf("%d ", fibonacci(i));  // Imprime el término i
        print_fibonacci(n, i+1);      // Llamada recursiva
    }
}

int cant_fibonacci(int x, int i) //Ejercicio 3
{
    if (x > fibonacci(i)) {
        return cant_fibonacci(x, i+1); 
    } else {
        return i;
    }
}

float potencia_n(float x, int n) //Ejercicio 4
{
    float r = 1.0;
    if(n > 0) {
        r = x * potencia_n(x, n-1);
    }
    if(n < 0) {
        r = 1.0 / (potencia_n(x, -n));
    }
    return r;
}