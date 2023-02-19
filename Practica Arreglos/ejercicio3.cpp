#include <iostream>
using namespace std;

const int TAM = 20;
void ejercicio_3();
void ingresar_valores(short int lista[TAM], int &contador);
void mostrar_valores(short int lista[TAM], int contador);
int main(){
    ejercicio_3();
}

void ejercicio_3(){
    short int lista[TAM];
    int contador = 0;
    cout << "BIENVENIDO AL EJERCICIO 3" << endl;
    cout << "Autores: Daniel Mera, Juan Naranjo" << endl;
    ingresar_valores(lista, contador);
    mostrar_valores(lista, contador);
}

void ingresar_valores(short int lista[TAM], int &contador){
    short int num, i = 0;
    bool repetido = true;
    do{
        cout << "Valor " << i + 1 << ": ";
        cin >> num; 
        if((num >= 10) && (num <= 100)){  
            for(int j = 0; j <= contador; j++){
                if(num == lista[j]){
                    repetido = false;
                }
            }
            if(repetido == true){
                lista[contador] = num;
                contador++;
            }
            i++;
            repetido = true;
        } else {
            cout << "Valor fuera de los limites" << endl;
        }
    }while(i < 6);
    cout << endl;
}

void mostrar_valores(short int lista[TAM], int contador){
    cout << "Valores ingresados no repetidos" << endl;
    for(int i = 0; i < contador; i++){
        cout << "Valor " << i + 1 << ": " << lista[i] << endl;
    }
}