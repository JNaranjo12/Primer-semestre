#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <iomanip>

typedef struct {
    int id;
    string nombre_animal;
    float peso;
    string tipo_animal;
} tAnimal;

void ejercicio_2();
int menu2();
void registrar(tAnimal animal);
void mostrar_animales(tAnimal animal);
void buscar_animal(tAnimal animal);

int main(){
    ejercicio_2();
}

void ejercicio_2(){
    tAnimal animal; 
    int opcion;
    cout << "BIENVENIDO AL EJERCICIO 2" << endl;
    cout << "Autores: Daniel Mera, Juan Naranjo" << endl;

    do{
        opcion = menu2();
        switch (opcion)
        {
        case 1:
            registrar(animal);
            break;
        case 2:
            mostrar_animales(animal);
            break;    
        case 3:
            buscar_animal(animal);
            break;
        }
    } while(opcion != 4);
    
}
int menu2() {
    int opcion = -1;
    while ((opcion < 1) || (opcion > 4)) {
        cout << endl;
        cout << "MENU OPCIONES" << endl;
        cout << "1. Registrar animal" << endl;
        cout << "2. Base de datos de animales del zoologico" << endl;
        cout << "3. Buscar animal" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        if ((opcion < 1) || (opcion > 4)) {
        cout << "Opcion no valida" << endl;
        }
    }
    cout << endl;
    return opcion;
}

void registrar(tAnimal animal){ 
    ofstream zoo_ingresar;
    int cantidad;
    char aux;
    cout << "AVISO: Ingresar nombres en minusculas" << endl;
    cout << "Cantidad de animales a registar: ";
    cin >> cantidad;
    zoo_ingresar.open("zoologico.txt");
    for(int i = 0; i < cantidad; i++){
        cout << "Identificacion animal: " << i + 1 << endl;
        animal.id = i + 1;
        cin.get(aux);
        cout << "Ingrese nombre de animal: ";
        getline(cin, animal.nombre_animal);
        cout << "Ingrese peso del animal (Kg): ";
        cin >> animal.peso;
        cout << "Ingrese el tipo de animal: ";
        cin >> animal.tipo_animal;
        zoo_ingresar << animal.id << endl;
        zoo_ingresar << animal.nombre_animal << endl; 
        zoo_ingresar << animal.peso << endl; 
        zoo_ingresar<< animal.tipo_animal << endl; 
        cout << endl;
    }
    zoo_ingresar << 0;
    zoo_ingresar.close();
}

void mostrar_animales(tAnimal animal){
    char aux;
    ifstream zoo_leer;
    cout << left <<setw(16) << left << "IDENTIFICACION" << left << setw(15) << "NOMBRE" << left << setw(10) <<"PESO(kg)" << left << setw(10) << "TIPO" << endl;
    zoo_leer.open("zoologico.txt");
    if(zoo_leer.is_open()){
        zoo_leer >> animal.id;
        while(animal.id != 0){
            zoo_leer.get(aux);
            getline(zoo_leer, animal.nombre_animal);
            zoo_leer >> animal.peso;
            zoo_leer >> animal.tipo_animal;
            cout << left << setw(16) << animal.id << left << setw(15) << animal.nombre_animal << left << setw(10) << animal.peso << left << setw(10) << animal.tipo_animal << endl; 
            zoo_leer >> animal.id;
        }
    }
    zoo_leer.close();
    cout << endl;
}

void buscar_animal(tAnimal animal){
    char aux;
    string buscado;
    ifstream zoo_leer;
    cin.get(aux);
    cout << "AVISO: Ingresar nombre en minuscula" << endl;
    cout << "Nombre del animal que desea buscar: ";
    getline(cin, buscado);
    zoo_leer.open("zoologico.txt");
    if(zoo_leer.is_open()){
        do{
            zoo_leer >> animal.id;
            zoo_leer.get(aux);
            getline(zoo_leer, animal.nombre_animal);
            zoo_leer >> animal.peso;
            zoo_leer >> animal.tipo_animal;
        }while(!(buscado == animal.nombre_animal));
    }
    zoo_leer.close();
    cout << endl;
    cout << "INFORMACION DEL ANIMAL" <<  endl;
    cout <<  "Identificacion: " << animal.id << endl;
    cout << "Nombre: " << animal.nombre_animal << endl;
    cout << "Peso (kg): " <<animal.peso << endl;
    cout << "Tipo: "<< animal.tipo_animal << endl << endl; 
}