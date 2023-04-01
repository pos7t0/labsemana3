#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	//nombre del jugador
	char name[50];
	//nivel del jugador
	int level;
	//vida maxima del jugador
	int salud;
	//cantidad de daño que va a atacar a sus oponente
	int fuerza;
	//determinar el equipo que va a estar
	int equipo;
	//cantidad de recepcion de daño que va a aguantar
	int defensa;
} jugador;

int main(){
	int equipo1=0,equipo2=0;
	srand(time(NULL));
	jugador j1,j2,j3,j4,j5,j6,j7,j8,j9,j10;
	jugador *j[10]={malloc(sizeof(j1)),malloc(sizeof(j2)),malloc(sizeof(j3)),malloc(sizeof(j4)),
					malloc(sizeof(j5)),malloc(sizeof(j6)),malloc(sizeof(j7)),malloc(sizeof(j8)),
					malloc(sizeof(j9)),malloc(sizeof(j10))};
	int i;
	//ingresar datos a los atributos de los jugadores				
	for(i=0;i<10;i++){
		printf("ingrese nombre del jugador %d\n",i+1);
		scanf("%s",&j[i]->name);
		j[i]->level=rand()%10+1;
		j[i]->salud=rand()%40+11;
		j[i]->fuerza=rand()%8+8;
		j[i]->defensa=rand()%4+4;
		//que los equipos no sobrepasen la cantidad de 5
		do{
			j[i]->equipo=rand()%2;
		}while(equipo1>=5 && j[i]->equipo==0|| equipo2>=5 && j[i]->equipo==1);
		if(j[i]->equipo==0){
			equipo1++;
		}
		if(j[i]->equipo==1){
			equipo2++;
		}
	}
	//imprimir datos del equipo 1
	printf("\tEQUIPO 1\n");
	for(i=0;i<10;i++){
		if(j[i]->equipo==0){
			printf("Datos jugador %d\n",i+1);
			printf("nombre: %s\n",j[i]->name);
			printf("nivel: %d\n",j[i]->level);
			printf("salud: %d\n",j[i]->salud);
			printf("fuerza: %d\n",j[i]->fuerza);
		}
	}
		//imprimir datos del equipo 2
	printf("\tEQUIPO 2\n");
	for(i=0;i<10;i++){
		if(j[i]->equipo==1){
			printf("Datos jugador %d\n",i+1);
			printf("nombre: %s\n",j[i]->name);
			printf("nivel: %d\n",j[i]->level);
			printf("salud: %d\n",j[i]->salud);
			printf("fuerza: %d\n",j[i]->fuerza);
		}
	}
	

	
	return 0;
}
