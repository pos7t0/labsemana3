// See https://aka.ms/new-console-template for more information
using System;
namespace labsemana3_ejercicio4{

    class Program{
        static void Main(string[] args)
        {
            //datos for
            int i,h,n=1,nt=1;
            int equipo1=0,equipo2=0,random=0,elegirj,elegirn,usuariopierde=0,dado,cpuequipo,cpuenemigo=0,cpupierde=0;
            int vida_restante=0,vida_restantecpu=0;
            bool equipo=true,enemigo=true;
            Random rnd=new Random();
            Random dado1=new Random();
            Random dado2=new Random();
            jugador j1=new jugador();
            jugador j2=new jugador();
            jugador j3=new jugador();
            jugador j4=new jugador();
            jugador j5=new jugador();
            jugador j6=new jugador();
            jugador j7=new jugador();
            jugador j8=new jugador();
            jugador j9=new jugador();
            jugador j10=new jugador();
            jugador[] j={j1,j2,j3,j4,j5,j6,j7,j8,j9,j10};
            Console.Clear();
            do//validar max de equipo
            {
                if(n>5 || n<1)
                {
                    Console.WriteLine($"dato erroneo");
                }
                Console.WriteLine($"ingrese el maximo de jugadores en un equipo");
                n=Convert.ToInt32(Console.ReadLine());
            }while(n>5 || n<1);
            for(i=0;i<n*2;i++)
            {
                Console.WriteLine($"nombre del jugador {i+1}");
                j[i].Nombre=""+Console.ReadLine();
                j[i].Vida=rnd.Next(20,40);
                j[i].Defensa=rnd.Next(2,8);
                j[i].Fuerza=rnd.Next(6,18);
               
                do{
                    random =rnd.Next(0,2);
                }while(equipo1==n &&random==0 || equipo2==n &&random==1);
                if(random==0 && equipo1!=n){
                    j[i].Equipo=0;
                    equipo1++;
                }
                if(random==1 && equipo2!=n){
                    j[i].Equipo=1;
                    equipo2++;
                }
            }
             Console.WriteLine($"\t equipo 1");
            for(i=0;i<n*2;i++)
            {
                if(j[i].Equipo==0){
                    Console.WriteLine($"\tdatos del jugador {i+1}");
                    Console.WriteLine($"Nombre: {j[i].Nombre}");
                    Console.WriteLine($"Vida: {j[i].Vida}");
                    Console.WriteLine($"Defensa: {j[i].Defensa}");
                    Console.WriteLine($"Fuerza: {j[i].Fuerza}");
                }
               
            }
             Console.WriteLine($"\t equipo 2");
            for(i=0;i<n*2;i++)
            {
                if(j[i].Equipo==1){
                    Console.WriteLine($"\tdatos del jugador {i+1}");
                    Console.WriteLine($"Nombre: {j[i].Nombre}");
                    Console.WriteLine($"Vida: {j[i].Vida}");
                    Console.WriteLine($"Defensa: {j[i].Defensa}");
                    Console.WriteLine($"Fuerza: {j[i].Fuerza}");
                }
               
            }
            do//validar max de turnos y que no se sobre pase
            {
                if(nt>30 || nt<1)
                {
                    Console.WriteLine($"dato erroneo");
                }
                Console.WriteLine($"ingrese el maximo de turnos en el juego(max 30 turnos)");
                nt=Convert.ToInt32(Console.ReadLine());
            }while(nt>30 || nt<1);
            Console.Clear();
            for(h=0;h<nt;h++)
            {
                Console.WriteLine($"\t***ronda {h+1}***");
                Console.WriteLine($"\tturno del usuario");
                //turno del usuario
                Console.WriteLine($"\tdatos equipo");
                for(i=0;i<n*2;i++)
                {
                    if(j[i].Equipo==0){
                        Console.WriteLine($"\t**jugador {i+1}**");
                        Console.WriteLine($"Nombre: {j[i].Nombre}");
                        Console.WriteLine($"Vida: {j[i].Vida}");
                        Console.WriteLine($"Defensa: {j[i].Defensa}");
                        Console.WriteLine($"Fuerza: {j[i].Fuerza}");
                    }
                
                }
                do{
                    if(equipo==false){
                        Console.WriteLine($"numero de jugador de equipo falso o vida es menor o igual 0");
                    }
                    Console.WriteLine($"ingrese el numero del jugador que va a controlar");
                    elegirj=Convert.ToInt32(Console.ReadLine());
                    do 
                    {
                        if(1>elegirj ||n*2<elegirj)
                        {
                            Console.WriteLine($"ingrese un numero entre 1 y {n*2}");
                            elegirj=Convert.ToInt32(Console.ReadLine());
                        }
                        
                    }while(1>elegirj ||n*2<elegirj);
                    if( j[elegirj-1].Equipo==0 && j[elegirj-1].Vida>0){
                        equipo=true;
                    }else{
                        equipo=false;
                    }
                }while(equipo==false);
                Console.WriteLine($"\tdatos del enemigo");
                for(i=0;i<n*2;i++)
                {
                    if(j[i].Equipo==1){
                        Console.WriteLine($"\t**jugador {i+1}**");
                        Console.WriteLine($"Nombre: {j[i].Nombre}");
                        Console.WriteLine($"Vida: {j[i].Vida}");
                        Console.WriteLine($"Defensa: {j[i].Defensa}");
                        Console.WriteLine($"Fuerza: {j[i].Fuerza}");
                    }
                
                }
                do{
                    if(enemigo==false){
                        Console.WriteLine($"numero del jugador enemigo falso o vida es menor o igual 0");
                    }
                    Console.WriteLine($"ingrese el numero del enemigo que va a atacar");
                    elegirn=Convert.ToInt32(Console.ReadLine());
                    do 
                    {
                        if(1>elegirn ||n*2<elegirn)
                        {
                            Console.WriteLine($"ingrese un numero entre 1 y {n*2}");
                            elegirn=Convert.ToInt32(Console.ReadLine());
                        }
                        
                    }while(1>elegirn ||n*2<elegirn);
                    if( j[elegirn-1].Equipo==1 && j[elegirn-1].Vida>0){
                        enemigo=true;
                    }else{
                        enemigo=false;
                    }
                }while(enemigo==false);
                //decoracion
                Console.Write($"se ha tirado un dado de 3 caras");
                Thread.Sleep(500);
                Console.Write($" . ");
                Thread.Sleep(500);
                Console.Write($".");
                Thread.Sleep(500);
                dado=rnd.Next(1,4);
                //que resultado da en el dado
                if(dado==3){
                    Console.WriteLine($"salio un tres, el ataque se multiplica por 2");
                    j[elegirn-1].Vida+=j[elegirn-1].Defensa-j[elegirj-1].Fuerza*2;
                }
                if(dado==2){
                    Console.WriteLine($"salio un 2, se a realizado un ataque al enemigo");
                    j[elegirn-1].Vida+=j[elegirn-1].Defensa-j[elegirj-1].Fuerza;
                }
                if(dado==1){
                    Console.WriteLine($"salio un 1, haz fallado el ataque hacia el enemigo");
                }
                Thread.Sleep(1000);
                cpupierde=0;
                //validacion si es que la cpu pierde todos su jugadores
                for(i=0;i<n*2;i++)
                {
                    if(j[i].Vida<=0&& j[i].Equipo==1)
                    cpupierde++;
                }
                
                if(cpupierde!=n){
                    Console.WriteLine($"\tturno del computador");
                }
                
                
                //que la cpu escoja a su equipo
                do{
                    cpuequipo=rnd.Next(0,(n*2));
                }while(j[cpuequipo].Equipo!=1 && cpupierde!=n ||j[cpuequipo].Vida<=0&& cpupierde!=n);
                //que la cpu escoja a su enemigo
                do{
                    cpuenemigo=rnd.Next(0,(n*2));
                }while(j[cpuenemigo].Equipo!=0 && cpupierde!=n || j[cpuenemigo].Vida<=0&& cpupierde!=n);
                dado=rnd.Next(1,4);
                //lo que puede pasar con los dados
                if(dado==3&&cpupierde!=n){
                    Console.WriteLine($"salio un tres, la cpu pudo atacar hacia el jugador {cpuenemigo+1} el doble de daño con el jugador {cpuequipo+1}");
                    j[cpuenemigo].Vida+=j[cpuenemigo].Defensa-j[cpuequipo].Fuerza*2;
                }
                if(dado==2&&cpupierde!=n){
                    Console.WriteLine($"salio un 2, la cpu pudo atacar hacia el jugador {cpuenemigo+1} con el jugador {cpuequipo+1}");
                    j[cpuenemigo].Vida+=j[cpuenemigo].Defensa-j[cpuequipo].Fuerza;
                }
                if(dado==1&&cpupierde!=n){
                    Console.WriteLine($"salio un 1, la cpu fallo el ataque hacia el jugador {cpuenemigo+1}");
                }
                Thread.Sleep(2000);
                //para saber si el usuario pierde
                for(i=0;i<n*2;i++)
                {
                    if(j[i].Vida<=0 && j[i].Equipo==0)
                    usuariopierde++;
                }
                if(usuariopierde==n || cpupierde==n)
                {
                    h=30;
                }

            }
            for(i=0;i<n*2;i++)
            {
                if(j[i].Equipo==0){
                    vida_restante+=j[i].Vida;
                }
                if(j[i].Equipo==1){
                    vida_restantecpu+=j[i].Vida;
                }
            }
            if(vida_restante>vida_restantecpu){
                Console.WriteLine("\tFELICIDADES");
                Console.WriteLine($"Usted a ganado con {vida_restante} puntos");
            }else{
                Console.WriteLine("\tPerdiste");
                Console.WriteLine($"Usted a perdido con {vida_restante} puntos en comparacion a la cpu con {vida_restantecpu}");
            }
        }
    }
}
