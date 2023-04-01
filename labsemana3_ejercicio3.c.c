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
//muestra la estadistica del jugador mencionado
void estadistica_j(int i,char a[], int b, int c, int d,int e){
	//i representa el numero del jugador
	printf("Datos jugador %d\n",i);
	//a representa el nombre
	printf("nombre: %s\n",a);
	//b representa el nivel del jugador
	printf("nivel: %d\n",b);
	//c representa la vida maxima
	printf("salud: %d\n",c);
	//d representa la fuerza que tiene el jugador
	printf("fuerza: %d\n",d);
	//e representa la defensa
	printf("defensa: %d\n",e);
}

int main(){
	//variable para el codigo de equipo
	int equipo1=0,equipo2=0,e1ataque,e1defensa,e1vida,e2ataque,e2defensa,e2vida,visto=0;
	srand(time(NULL));
	jugador j1,j2,j3,j4,j5,j6,j7,j8,j9,j10;
	jugador *j[10]={malloc(sizeof(j1)),malloc(sizeof(j2)),malloc(sizeof(j3)),malloc(sizeof(j4)),
					malloc(sizeof(j5)),malloc(sizeof(j6)),malloc(sizeof(j7)),malloc(sizeof(j8)),
					malloc(sizeof(j9)),malloc(sizeof(j10))};
	//variables para interactuar
	int i,desicion,nj=1;
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
			estadistica_j(i+1,j[i]->name,j[i]->level,j[i]->salud,j[i]->fuerza,j[i]->defensa);
		}
	}
		//imprimir datos del equipo 2
	printf("\tEQUIPO 2\n");
	for(i=0;i<10;i++){
		if(j[i]->equipo==1){
			estadistica_j(i+1,j[i]->name,j[i]->level,j[i]->salud,j[i]->fuerza,j[i]->defensa);
		}
	}
	do{
		e1vida=0;
		e1ataque=0;
		e1defensa=0;
		e2vida=0;
		e2ataque=0;
		e2defensa=0;
		printf("\tingrese lo que quiere hacer\n");
		printf("[1]ver estadistica de jugador [2]actualizar estadistica de jugador\n");
		printf("[3]ver equipo ganador         [cualquier otro numero]salir\n");
		scanf("%d",&desicion);
		switch(desicion){
			case 1:{
				do{
					//validar numero de jugador
					if(nj<1 || nj>10){
						printf("dato erroneo, ingrese denuevo\n");
					}
					printf("ingrese el numero del jugador\n");
					scanf("%d",&nj);	
				}while(nj<1 ||10<nj);
				estadistica_j(nj,j[nj-1]->name,j[nj-1]->level,j[nj-1]->salud,j[nj-1]->fuerza,j[nj-1]->defensa);
				break;
			}
			case 2:{
				do{
					//validar numero de jugador
					if(nj<1 || nj>10){
						printf("dato erroneo, ingrese denuevo\n");
					}
					printf("ingrese el numero del jugador\n");
					scanf("%d",&nj);	
				}while(nj<1 ||10<nj);
				do{
					//validar lo que pide el texto
					if(j[nj-1]->level<=0){
						printf("dato erroneo, ingrese denuevo\n");
					}
					printf("ingrese nuevo nivel del jugador %d(no puede ser menor o igual que 0)\n",nj);
					scanf("%d",&j[nj-1]->level);
				}while(j[nj-1]->level<=0);
				do{
					//validar lo que pide el texto
					if(j[nj-1]->salud<=0){
						printf("dato erroneo, ingrese denuevo\n");
					}
					printf("ingrese la nueva salud del jugador %d(no puede ser menor o igual que 0)\n",nj);
					scanf("%d",&j[nj-1]->salud);
				}while(j[nj-1]->salud<=0);
				printf("ingrese la nueva fuerza del jugador %d\n",nj);
				scanf("%d",&j[nj-1]->fuerza);
				printf("ingrese la nueva defensa del jugador %d\n",nj);
				scanf("%d",&j[nj-1]->defensa);
				break;
			}
			case 3:{
				//informacion
				if(visto==0){
					printf("la batalla se realizara de la siguiente forma:\n");
					printf("[1]se sumaran todos los puntos de fuerza, salud y fuerza de cada equipo\n");
					printf("[2luego se realizara el siguiente calculo: vida de equipo-((ataque enemigo)-(defensa de equipo))]\n");
					printf("[3]la vida de equipo sobrante se convertira en experiencia\n");
					printf("[4]el equipo ganador se determinara quien tenga mas experiencia\n");
					printf("[bonus]si un integrante del equipo tiene fuerza o defensa menor a cero,\n se remplaza con un 0 al no apoyar en nada\n");
					visto++;
				}
				//sumando la fuerza y defensa del equipo entero y validando los numeros negativos
				for(i=0;i<10;i++){
					if(j[i]->equipo==0){
						if(j[i]->fuerza<0){
							e1ataque+=0;
						}else{
							e1ataque+=j[i]->fuerza;
						}
						if(j[i]->defensa<0){
							e1defensa+=0;
						}else{
							e1defensa+=j[i]->defensa;
						}
						e1vida+=j[i]->salud;
					}
					if(j[i]->equipo==1){
						if(j[i]->fuerza<0){
							e2ataque+=0;
						}else{
							e2ataque+=j[i]->fuerza;
						}
						if(j[i]->defensa<0){
							e2defensa+=0;
						}else{
							e2defensa+=j[i]->defensa;
						}
						e2vida+=j[i]->salud;
					}
					
				}
				e1vida-=(e2ataque-e1defensa);
				e2vida-=(e1ataque-e2defensa);
				//la vida sobrante en equipo se convertiran en puntos de experiencia
				//generando que gane el que tenga mas puntos de vida
				if(e1vida>e2vida){
					printf("el equipo 1 ha ganado con %d en comparacion del equipo 2 con %d\n",e1vida,e2vida);
				}else{
					if(e1vida<e2vida){
						printf("el equipo 2 ha ganado con %d en comparacion del equipo 1 con %d\n",e2vida,e1vida);
					}else{
						printf("ha habido un empate entre los dos equipos con %d\n",e1vida);
					}
				}
				break;
			}
		}
	}while(desicion>0 || desicion<4);
	
	

	
	return 0;
}
