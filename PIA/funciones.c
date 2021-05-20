#include"snake.h"

//it will make the limits of the matrix
void intro_campo(char campo[V][H]){
	for(int i = 0; i < V; i++){
		for(int j = 0; j < H; j++){
			if(i == 0 || i == V-1){
				campo[i][j] = '-';
			}
			else if(j == 0 || j == H-1){
				campo[i][j] = '|';
			}
			else{
				campo[i][j] = ' ';
			}
		}
	}
}
//it gives the position of the snake
void intro_datos(char campo[V][H], int tam){
	for(int i = 1; i < tam; i++){
		snake[i].x = snake[i-1].x-1;
		snake[i].y = snake[i-1].y;
		snake[i].image = 'o';
	}
	snake[0].image = 'O';
	for(int i = 0; i < tam; i++){
		campo[snake[i].y][snake[i].x] = snake[i].image;
	}
	campo[fruta.y][fruta.x] = '%';
}
//it will draw the matrix of the playground
void draw(char campo[V][H]){
	for(int i = 0; i < V; i++){
		for(int j = 0; j < H; j++){
			printf("%c", campo[i][j]);
		}
		printf("\n");
	}
}

void input(char campo[V][H], int *tam, int *dead){
	char key;
	//Verification if we have died
	if(snake[0].x == 0 || snake[0].x == H-1 || snake[0].y == V-1){
		*dead = 1;
	}
	for(int i = 1; i < *tam && *dead == 0; i++){
		if(snake[0].x == snake[i].x && snake[0].y == snake[i].y){
			*dead = 1;
		}
	}
	//verification if we have eaten the fruit
	if(snake[0].x == fruta.x && snake[0].y == fruta.y){
		*tam += 1;
		snake[*tam - 1].image = 'o';
		fruta.x = rand() % (H-1);
		fruta.y = rand() % (V-1);
		while(fruta.x == 0 || fruta.y == 0){
			fruta.x = rand() % (H-1);
			fruta.y = rand() % (V-1);
		}
	}
	//it will read the key that we have introduced
	if(*dead == 0){
    key = getchar();
		if(key == 's' && snake[0].ModY != -1){
		   snake[0].ModX = 0;
			 snake[0].ModY = 1;
		}
		if(key == 'w' && snake[0].ModY != 1){
			snake[0].ModX = 0;
			snake[0].ModY = -1;
		}
		if(key == 'a' && snake[0].ModX != 1){
			snake[0].ModX = -1;
			snake[0].ModY = 0;
		}
		if(key == 'd' && snake[0].ModX != -1){
			snake[0].ModX = 1;
			snake[0].ModY = 0;
		}
	}
}
//it will erase the data of the matrix
void update(char campo[V][H], int tam){  
	intro_campo(campo);
	intro_datos2(campo, tam);
}

void intro_datos2(char campo[V][H], int tam){
	for(int i = tam-1; i > 0; i--){
		snake[i].x = snake[i-1].x;
		snake[i].y = snake[i-1].y;
	}
	snake[0].x += snake[0].ModX;
	snake[0].y += snake[0].ModY;
	for(int i = 0; i < tam; i++){
		campo[snake[i].y][snake[i].x] = snake[i].image;
	}
	campo[fruta.y][fruta.x] = '%';
}
