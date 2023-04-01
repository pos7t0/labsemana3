#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char name[50];
	int level;
	int salud;
	int puntaje;
} jugador;

int main(){
	jugador *j1=malloc(sizeof(jugador));
	jugador *j2=malloc(sizeof(jugador));
	jugador *j3=malloc(sizeof(jugador));
	
	printf("jugador 1\n");
	printf("ingrese nombre\n");
	scanf("%s",&j1->name);
	printf("ingrese nivel\n");
	scanf("%d",&j1->level);
	printf("ingrese salud\n");
	scanf("%d",&j1->salud);
	printf("ingrese puntaje\n");
	scanf("%d",&j1->puntaje);
	
	printf("jugador 2\n");
	printf("ingrese nombre\n");
	scanf("%s",&j2->name);
	printf("ingrese nivel\n");
	scanf("%d",&j2->level);
	printf("ingrese salud\n");
	scanf("%d",&j2->salud);
	printf("ingrese puntaje\n");
	scanf("%d",&j2->puntaje);
	
	printf("jugador 3\n");
	printf("ingrese nombre\n");
	scanf("%s",&j3->name);
	printf("ingrese nivel\n");
	scanf("%d",&j3->level);
	printf("ingrese salud\n");
	scanf("%d",&j3->salud);
	printf("ingrese puntaje\n");
	scanf("%d",&j3->puntaje);
	printf("jugador 1\n");
	printf("nombre: %s nivel: %d salud: %d puntaje: %d\n",j1->name,j1->level,j1->salud,j1->puntaje);
	printf("jugador 2\n");
	printf("nombre: %s nivel: %d salud: %d puntaje: %d\n",j2->name,j2->level,j2->salud,j2->puntaje);
	printf("jugador 3\n");
	printf("nombre: %s nivel: %d salud: %d puntaje: %d\n",j3->name,j3->level,j3->salud,j3->puntaje);
	
	return 0;
}
