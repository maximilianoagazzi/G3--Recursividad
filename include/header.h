#ifndef HEADER_H
#define HEADER_H
#include "vector.h"

int suma_n(int i);
int producto_n(int i1, int i2);
int fibonacci(int i);
void print_fibonacci(int n, int i);
int cant_fibonacci(int x, int i);
float potencia_n(float x, int n);
int creciente(int n);
int creciente_r(char *b);
char *inverted(char *chain);
int long_chain(char *chain, int i);
void inverted_r(char *chain, char *inverted, int i, int j);
void piramide_n_aria(int n);
void piramide_n_aria_r1(int n, int i);
void piramide_n_aria_aux(int n, int j);
vector* set_random_vector_float(int size);
float max_elem(vector* v);
float max_elem_r(vector* v, int i);
float min_elem(vector* v);
float min_elem_r(vector* v, int i);
float sum_elem(vector* v);
float sum_elem_r(vector* v, int i);
float prom_elem(vector* v);
void print_elem(vector* v);
void print_elem_r(vector* v, int i);
void print_elem_inv(vector* v);
void print_elem_inv_r(vector* v, int i);
int sequential_search(vector* v, float val);
int sequential_search_r(vector* v, float val, int i);
void bubble_sort(vector *v, int n);
void bubble_sort_aux(vector* v, int n, int i);
int binary_search(vector* v, float val);
int binary_search_r(vector* v, float val, int low, int high);

#endif