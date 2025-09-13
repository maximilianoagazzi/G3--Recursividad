#include <stdio.h>
#include <stdlib.h>
#include "include/vector.h"
#include "include/header.h"

void quick_sort(vector* v, int i, int f);

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
    //Ejercicio 7

    vector* v_float = set_random_vector_float(10);
    //Ejercicio 8

    float max = max_elem(v_float);
    printf("\nEl maximo elemento del vector de reales es: %.2f\n", max);
    //Ejercicio 8a

    float min = min_elem(v_float);
    printf("\nEl minimo elemento del vector de reales es: %.2f\n", min);
    //Ejercicio 8b

    float sum = sum_elem(v_float);
    printf("\nLa suma del vector de reales es: %.2f\n", sum);
    //Ejercicio 8c

    float prom = prom_elem(v_float);
    printf("\nEl promedio del vector de reales es: %.2f\n", prom);
    //Ejercicio 8d

    printf("\nEl vector de Reales es: \n\n");
    print_elem(v_float);
    //Ejercicio 8e

    printf("\nEl vector de Reales impreso al reves es: \n\n");
    print_elem_inv(v_float);
    //Ejercicio 8f

    int pos = sequential_search(v_float, *(float* )vector_get(v_float, 4));
    printf("\nEl elementeo %.2f se encuentra en la posicion %d\n", *(float* )vector_get(v_float, 4), pos);
    //Ejercicio 9a

    bubble_sort(v_float, vector_size(v_float));
    printf("\nEl vector de Reales ordenado es: \n\n");
    print_elem(v_float);
    int bsq = binary_search(v_float, *(float* )vector_get(v_float, 7));
    printf("\nEl valor %.2f se encuentra en la posicion: %d\n", *(float* )vector_get(v_float, 7), bsq);
    //Ejercicio 9b

    free(palabra_i);
    for(int i=0; i<vector_size(v_float); i++) {
        free(vector_get(v_float, i));
    }
    vector_free(v_float);
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

vector* set_random_vector_float(int size)  //Ejercicio 8
{
    vector* v = vector_new_with(size); 

    for (int i=0; i<size; i++) {
        float* num = (float* )malloc(sizeof(float));
        *num = ((float) rand() / (RAND_MAX + 1.0)) * 100.0; // Números aleatorios entre 0 y 99
        vector_add(v, num);
    }
    return v;
}

float max_elem(vector* v) // Ejercicio 8a
{
    return max_elem_r(v, 0);
}

float max_elem_r(vector* v, int i) //Ejercicio 8a
{
    if (i == vector_size(v) - 1) {  // Caso base: último elemento
        return *(float*)vector_get(v, i);
    } else {
        float actual = *(float*)vector_get(v, i);
        float resto = max_elem_r(v, i+1);
        if (actual > resto) {
            return actual;
        } else {
            return resto;
        }
    }
}

float min_elem(vector* v) // Ejercicio 8b
{
    return min_elem_r(v, 0);
}

float min_elem_r(vector* v, int i) //Ejercicio 8b
{
    if (i == vector_size(v) - 1) {  // Caso base: último elemento
        return *(float*)vector_get(v, i);
    } else {
        float actual = *(float*)vector_get(v, i);
        float resto = min_elem_r(v, i+1);
        if (actual < resto) {
            return actual;
        } else {
            return resto;
        }
    }
}

float sum_elem(vector* v) // Ejercicio 8c
{
    return sum_elem_r(v, 0);
}

float sum_elem_r(vector* v, int i) //Ejercicio 8c
{
    if (i == vector_size(v)) {  // Caso base: último elemento
        return 0.0;
    } else {
        return *(float* )vector_get(v, i) + sum_elem_r(v, i+1);
    }
}

float prom_elem(vector* v) //Ejercicio 8d
{
    return sum_elem_r(v, 0)/vector_size(v);
}

void print_elem(vector* v) //Ejercicio 8e
{
    print_elem_r(v, 0);
    printf("\n");
}

void print_elem_r(vector* v, int i) //Ejercicio 8e
{
    if (i < vector_size(v)) {
        printf("%.2f ", *(float*)vector_get(v, i));
        print_elem_r(v, i+1);
    }
}

void print_elem_inv(vector* v) //Ejercicio 8f
{
    print_elem_inv_r(v, vector_size(v)-1);
    printf("\n");
}

void print_elem_inv_r(vector* v, int i) //Ejercicio 8f
{
    if (i >= 0) {
        printf("%.2f ", *(float*)vector_get(v, i));
        print_elem_inv_r(v, i-1);
    }
}

int sequential_search(vector* v, float val) //Ejercicio 9a
{
    return sequential_search_r(v, val, 0);
}

int sequential_search_r(vector* v, float val, int i) //Ejercicio 9a
{
    if (i < vector_size(v)) {
        if(val != *(float* )vector_get(v, i)) {
            return sequential_search_r(v, val, i+1);
        } else {
            return i+1;
        }
    } else {
        return -1;
    }
}

void bubble_sort(vector* v, int n) //Ejercicio 9b
{
    if (n > 1) {
        bubble_sort_aux(v, n, 1);
        bubble_sort(v, n-1);
    }
}

void bubble_sort_aux(vector* v, int n, int i) //Ejercicio 9b
{
    if (i < n) {
        float* a = (float* )vector_get(v, i-1);
        float* b = (float* )vector_get(v, i);
        if (*a > *b) {
            float temp = *a;
            *a = *b;
            *b = temp;
        }
        bubble_sort_aux(v, n, i+1);
    }
}

int binary_search(vector* v, float val) //Ejercicio 9b (Solo para vector ordenado)
{
    int low = 0; 
    int high = vector_size(v) - 1;  
    int mid = binary_search_r(v, val, low, high);

    if (*(float* )vector_get(v, mid) == val) {
        return mid+1;
    } else {
        return -1; //El valor no aparece
    }
}

int binary_search_r(vector* v, float val, int low, int high) //Ejercicio 9b
{
    if(low > high) {
        return -1;
    }

    int mid = (high + low) / 2;
    if ((low <= high) && (*(float* )vector_get(v, mid) != val)) {
        if (val < *(float* )vector_get(v, mid)) {
            return binary_search_r(v, val, low, mid-1);
        } else {
            return binary_search_r(v, val, mid+1, high);
        }
    }
    return mid;
}

void quick_sort(vector* v, int i, int f)
{
    
}