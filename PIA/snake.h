#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#define V 21
#define H 65
#define N 100

typedef struct{
	int x, y; 
	int ModX, ModY;
	char image;
}snk;
typedef struct{
	int x, y;
}frt;

snk snake[N];
frt fruta;
void inicio(int *tam, char campo[V][H]);
void intro_campo(char campo[V][H]);
void intro_datos(char campo[V][H], int tam);
void draw(char campo[V][H]);
void loop(char campo[V][H], int tam);
void input(char campo[V][H], int *tam, int *dead);
void update(char campo[V][H], int tam);
void intro_datos2(char campo[V][H], int tam);
