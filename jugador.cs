using System;
namespace labsemana3_ejercicio4{

    class jugador{

        private string _nombre="";
        private int _vida=0;
        private int _defensa=0;
        private int _fuerza=0;
        private int _equipo=0;
        public jugador(){

        }
        public jugador(string nombre, int vida, int defensa, int fuerza,int equipo){
            this._nombre=nombre;
            this._vida=vida;
            this._defensa=defensa;
            this._fuerza=fuerza;
            this._equipo=equipo;
        }
        public string Nombre
        {
            get{return this._nombre;}
            set{this._nombre=value;}
        }
        public int Vida
        {
            get{return this._vida;}
            set{this._vida=value;}
        }
        public int Defensa
        {
            get{return this._defensa;}
            set{this._defensa=value;}
        }
        public int Fuerza
        {
            get{return this._fuerza;}
            set{this._fuerza=value;}
        }
        public int Equipo
        {
            get{return this._equipo;}
            set{this._equipo=value;}
        }

    }
}