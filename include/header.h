#ifndef HEADER_H
#define HEADER_H

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

#endif