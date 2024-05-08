#include <iostream>
using namespace std;
#include <string>

typedef struct{
    string nombre;
    int puntaje;
}tEquipo;

const int TAM = 50;

void ejercicio_1();
void ingresar_equipos(tEquipo equipos[TAM], const int cantidad_equipos);
void mostrar_posiciones(tEquipo equipos[TAM], const int cantidad_equipos);

int main(){
    ejercicio_1();
    return 0;
}

void ejercicio_1(){
    tEquipo equipos[TAM];
    char opcion; 
    int cantidad_equipos;
    cout << "BIENVENIDO AL EJERCICIO 1" << endl;
    cout << "Autores: Juan Naranjo, Daniel Mera\n" << endl;
    do{
        cout << "Cantidad de equipos a registrar: ";
        cin >> cantidad_equipos;
        do{
            if(cantidad_equipos <= 0){
                cout << "Cantidad incorrecta, ingrese de nuevo: ";
                cin  >> cantidad_equipos;
            }
        }while(cantidad_equipos <= 0);
        ingresar_equipos(equipos, cantidad_equipos);
        mostrar_posiciones(equipos, cantidad_equipos);
        cout << "Presione 0 para salir, otra tecla para continuar: ";
        cin >> opcion;

    }while(opcion != '0');

}

void ingresar_equipos(tEquipo equipos[TAM], const int cantidad_equipos){
    int ganados, empatados;

    for(int i = 0; i < cantidad_equipos; i++){
        cout << "Nombre del equipo: ";
        cin >> equipos[i].nombre;
        cout << "Partidos ganados: ";
        cin >> ganados;
        cout << "Partidos empatados: ";
        cin >> empatados;
        cout << endl;
        equipos[i].puntaje = (ganados * 3) + empatados;
        ganados = 0;
        empatados = 0;
    }
}
void mostrar_posiciones(tEquipo equipos[TAM], const int cantidad_equipos){
    int contador = 0, resultado = -2, aux1 = -1, aux2 = 0, ubicacion = 1;
    cout << "TABLA DE POSICIONES" << endl;
    do{
        for(int i = 0; i < cantidad_equipos; i++){
            if((resultado <= equipos[i].puntaje) && (resultado < equipos[aux2].puntaje)){
                resultado = equipos[i].puntaje;
                aux2 = i; 
            }
        }
        cout << ubicacion << ". " << equipos[aux2].nombre << " " << equipos[aux2].puntaje << endl;
        /*for(int j = 0; j < cantidad_equipos; j++){
            if(resultado == equipos[j].puntaje aux2 == j){
                cout << ubicacion << ". " << equipos[j].nombre << " " << equipos[j].puntaje << endl;
            }
        }
        aux1 = aux2;
        ubicacion++;
        aux2 = resultado;*/ 
        ubicacion++;
        resultado = 0;
        contador++;
    }while(contador < cantidad_equipos);
    ubicacion = 0;
}