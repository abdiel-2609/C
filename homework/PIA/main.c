#include"snake.h"

int main()
{
	int tam, score; 
	char campo[V][H];
	//system("PAUSE");
	inicio(&tam, campo);
	loop(campo, tam);
	//system("PAUSE");	
}
void inicio(int *tam, char campo[V][H]){
	//creación de la serpiente
	snake[0].x= 32;
	snake[0].y = 11;
	
	//random creation of the fruit
	*tam = 5;
	srand(time(NULL));
	fruta.x = rand() % (H-1);
	fruta.y = rand() % (V-1);
	while(fruta.x == 0 || fruta.y == 0){
		fruta.x = rand() % (H-1);
		fruta.y = rand() % (V-1);
	}
	for(int i = 0; i < *tam; i++){
		snake[i].ModX = 1;
		snake[i].ModY = 0;
	}
	intro_campo(campo);
	intro_datos(campo, *tam);
}
void loop(char campo[V][H], int tam){
	int dead = 0;
	do{
		//system("cls");
		draw(campo);
		input(campo, &tam, &dead);
		update(campo, tam);
	}while(dead == 0);
}