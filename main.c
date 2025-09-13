#include <stdio.h>
#include <stdlib.h>
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

    int n5 = 67;
    if (creciente(n5) == 1) {
        printf("El numero %d es creciente\n\n", n5);
    } else {
        printf("El numero %d no es creciente\n\n", n5);
    }
    //Ejercicio 5

    char palabra[] = "lamina";
    char* palabra_i = inverted(palabra);
    printf("El inverso de la palabra %s es %s\n\n", palabra, palabra_i);
    //Ejercicio 6

    piramide_n_aria(5);

    free(palabra_i);
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

int creciente(int n) //Ejercicio 5
{
    char buffer[60];

    if (n < 0) {
        return -1;
    }
    sprintf(buffer, "%d", n);

    return creciente_r(buffer);
}

int creciente_r(char* b) //Ejercicio 5
{
    if(*(b+1) == '\0') {
        return 1;
    }

    if(*(b) > *(b+1)) {
        return 0;
    }

    return creciente_r(b+1);
}

char* inverted(char* chain) //Ejercicio 6
{
    char* inv;
    int i = long_chain(chain, 0);

    inv = (char* )malloc(sizeof(char)*(i+1));
    if (inv == NULL) {
        return NULL;  //Ocurrio un error
    }

    inverted_r(chain, inv, i, 1);
    inv[i] = '\0';
    return inv;
}

int long_chain(char* chain, int i) //Ejercicio 6
{
    if(chain[i] == '\0') {
        return i;
    }
    return long_chain(chain, i+1);
}

void inverted_r(char* chain, char* inverted, int i, int j) //Ejercicio 6
{
    if(j <= i) {
        *inverted = chain[i-j];
        inverted_r(chain, inverted+1, i, j+1);
    }
}

void piramide_n_aria(int n) //Ejercicio 7
{
    piramide_n_aria_r1(n, 1);
}

void piramide_n_aria_r1(int n, int i) //Ejercicio 7
{
    if (i <= n) {
        piramide_n_aria_aux(n, i);
        printf("\n");
        piramide_n_aria_r1(n, i+1);
    }
}

void piramide_n_aria_aux(int n, int j) //Ejercicio 7
{
    if (j > 0) {
        printf("%d  ", j);
        piramide_n_aria_aux(n, j-1);
    }
}

