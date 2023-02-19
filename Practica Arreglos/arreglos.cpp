#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
int menu();

// prototipos del ejercicio 1
const int TAM = 50;
void ejercicio_1();
int menu1();
void ingresar_notas(double lista[TAM], int &contador);
int buscar(const double lista[TAM], const int contador, bool &encontrado);
void eliminar(double lista[TAM], int &contador);
void insertar(double lista[TAM], int &contador);
void visualizar(const double lista[TAM], const int contador);

////prototipos del ejercicio 2
const int MAX = 10;
void ejercicio2();
int contador(int numero);
void escrituraNumero(int numero, int &contador);
void arregloInverso(int arreglo[MAX], int numero, int contador);
void arregloNormal(int arreglo[MAX], int numero, int contador);
void mostrar(int arreglo[MAX], int contador);
int comparacion(int arreglo[MAX], int arreglo2[MAX], int contador);
void palindromo(int contador, int comparar);

// prototipos del ejercicio 3
const int tam = 20;
void ejercicio_3();
void ingresar_valores(short int lista[tam], int &contador1);
void mostrar_valores(short int lista[tam], int contador1);

////prototipos del ejercicio 4
int const limite = 36000;

void ejercicio4();
void aleatorio(int arreglo[], int arregl2[]);
void suma(int arreglo1[], int arreglo2[], int &contador2, int &contador3,
        int &contador4, int &contador5, int &contador6, int &contador7,
        int &contador8, int &contador9, int &contador10, int &contador11,
        int &contador12);
// void porcentaje(int contador);

///

int main() {
    int opcion;
    cout << "Bienvenido a los ejercicios de funciones" << endl;
    cout << "Autores: Daniel Mera, Juan Naranjo" << endl;

    do {
    opcion = menu();
    switch (opcion) {
    case 1:
        ejercicio_1();
        break;

    case 2:
        ejercicio2();
        break;

    case 3:
        ejercicio_3();
        cout << endl;
        break;

    case 4:
        ejercicio4();
        break;
    }

    } while (opcion != 0);

    return 0;
}

int menu() {
    int opcion = -1;
    while ((opcion < 0) || (opcion > 4)) {
        cout << "Menu de ejercicios realizados" << endl;
        cout << "Selecccione el ejercicio que desea" << endl;
        cout << "1. Ejercicio 1" << endl;
        cout << "2. Ejercicio 2" << endl;
        cout << "3. Ejercicio 3" << endl;
        cout << "4. Ejercicio 4" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;
        if ((opcion < 0) || (opcion > 4)) {
        cout << "Opcion no valida" << endl;
        }
    }
    return opcion;
}

// funciones del ejercicio 1
void ejercicio_1() {
    int opcion, buscado, contador = 0;
    double lista[TAM];
    bool encontrado = false;
    cout << "BIENVENIDO AL EJERCICIO 1" << endl;
    cout << "Autores: Daniel Mera, Juan Naranjo" << endl;
    do {
        opcion = menu1();
        switch (opcion) {
        case 1:
        ingresar_notas(lista, contador);
        break;

        case 2:
        buscado = buscar(lista, contador, encontrado);
        if (encontrado == true) {
            cout << "La calificacion " << lista[buscado]
                << " se encuentra en la posicion " << buscado + 1 << endl;
        } else {
            cout << "La calificacion ingresda no consta en la lista" << endl;
        }
        cout << endl;
        break;

        case 3:
        eliminar(lista, contador);
        break;

        case 4:
        insertar(lista, contador);
        break;

        case 5:
        visualizar(lista, contador);
        break;
        }
    } while (opcion != 0);
}

void ingresar_notas(double lista[TAM], int &contador) {
    int num_calificaciones;
    cout << "Cantidad de calificaciones a ingresar: ";
    cin >> num_calificaciones;
    if (num_calificaciones <= TAM) {
        for (int i = 0; i < num_calificaciones; i++) {
        cout << "Calificacion " << i + 1 << ": ";
        cin >> lista[i];
        contador++;
        }
    } else {
        cout << "Cantidad de calificaciones superior a la capacidad de la lista"
            << endl;
    }
    cout << endl;
}

int buscar(const double lista[TAM], const int contador, bool &encontrado) {
    double buscado;
    int resultado, i = 0;
    cout << "Ingrese la calificacion a buscar: ";
    cin >> buscado;

    while ((i < contador) && (!encontrado)) {
        if (lista[i] == buscado) {
        encontrado = true;
        resultado = i;
        } else {
        i++;
        }
    }
    return resultado;
}

void eliminar(double lista[TAM], int &contador) {
    int pos;
    cout << "Ingresar posicion de la calificacion a eliminar: ";
    cin >> pos;
    for (int i = pos - 1; i < contador - 1; i++) {
        lista[i] = lista[i + 1];
    }
    contador--;
    cout << endl;
}

void insertar(double lista[TAM], int &contador) {
    int pos;
    double calificacion;
    cout << "Ingresar la posicion de la nueva calificacion: ";
    cin >> pos;
    cout << "Ingresar el valor de la nueva calificacion: ";
    cin >> calificacion;
    if (contador < TAM) {
        for (int i = contador; i > pos - 1; i--) {
        lista[i] = lista[i - 1];
        }
        lista[pos - 1] = calificacion;
        contador++;
    }
    cout << endl;
}

void visualizar(const double lista[TAM], const int contador) {
    cout << "Listado de notas" << endl;
    for (int i = 0; i < contador; i++) {
        cout << "Calificacion " << i + 1 << ": " << lista[i] << endl;
    }
    cout << endl;
}

int menu1() {
    int opcion = -1;
    while ((opcion < 0) || (opcion > 5)) {
        cout << "SISTEMA DE CALIFICACIONES" << endl;
        cout << "1. Ingresar calificaciones" << endl;
        cout << "2. Buscar calificaciones" << endl;
        cout << "3. Eliminar calificaciones" << endl;
        cout << "4. Insertar calificacion atrasada" << endl;
        cout << "5. Visualizar calificaciones" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;
        if ((opcion < 0) || (opcion > 5)) {
        cout << "Opcion no valida" << endl;
        }
    }
    cout << endl;
    return opcion;
}

////funciones del ejercicio 2
void ejercicio2() {
    int numero, opcion;
    while (opcion != 0) {
        int contador = 0;
        cout << "Autores: Daniel Mera y Juan Naranjo" << endl;
        cout << "ingrese un numero: ";
        cin >> numero;
        escrituraNumero(numero, contador);
        int arreglo[contador], arreglo2[contador];
        arregloInverso(arreglo, numero, contador);
        mostrar(arreglo, contador);
        arregloNormal(arreglo2, numero, contador);
        cout << endl;
        mostrar(arreglo2, contador);
        palindromo(contador, comparacion(arreglo, arreglo2, contador - 1));
        cout << endl
            << "presione 0 para salir del sistema" << endl
            << "presione otro numero para continuar" << endl;
        cin >> opcion;
    }
}

void escrituraNumero(int numero, int &contador) {
    ofstream escritura;
    int resultado;
    escritura.open("numeros.txt");
    while (numero > 0 || resultado >= 10) {
        resultado = numero % 10;
        numero = numero / 10;
        escritura << resultado << endl;
        contador++;
    }
    escritura.close();
}

void arregloInverso(int arreglo[MAX], int numero, int contador) {
    ifstream lectura1;
    int valor1, i = 0;
    lectura1.open("numeros.txt");
    if (lectura1.is_open()) {
        while (i < contador) {
        lectura1 >> valor1;
        arreglo[i] = valor1;
        i++;
        }
        lectura1.close();
    }
}

void arregloNormal(int arreglo[MAX], int numero, int contador) {
    ifstream lectura2;
    int valor2, j = contador - 1;
    lectura2.open("numeros.txt");
    if (lectura2.is_open()) {
        while (j >= 0) {
        lectura2 >> valor2;
        arreglo[j] = valor2;
        j--;
        }
    }
}

void mostrar(int arreglo[MAX], int contador) {
    for (int i = 0; i < contador; i++) {
        cout << arreglo[i] << endl;
    }
}

int comparacion(int arreglo[MAX], int arreglo2[MAX], int contador) {
    int comparar;
    for (int i = 0; i < contador; i++) {
        if (arreglo[i] == arreglo2[i]) {
        comparar++;
        }
    }
    return comparar;
}

void palindromo(int contador, int comparar) {
    if (contador == comparar) {
        cout << "es un palindromo" << endl;
    } else {
        cout << "no es un palindromo" << endl;
    }
}
/// Funciones del ejercicio 3
void ejercicio_3() {
    short int lista[tam];
    int contador1 = 0;
    char opcion;
    cout << "BIENVENIDO AL EJERCICIO 3" << endl;
    cout << "Autores: Daniel Mera, Juan Naranjo" << endl;
        ingresar_valores(lista, contador1);
        mostrar_valores(lista, contador1);
}

void ingresar_valores(short int lista[tam], int &contador1) {
    short int num, i = 0;
    bool repetido = true;
    cout << "Ingrese 20 valores entre 10 a 100" << endl;
    do {
        cout << "Valor " << i + 1 << ": ";
        cin >> num;
        if ((num >= 10) && (num <= 100)) {
        for (int j = 0; j <= contador1; j++) {
            if (num == lista[j]) {
            repetido = false;
            }
        }
        if (repetido == true) {
            lista[contador1] = num;
            contador1++;
        }
        i++;
        repetido = true;
        } else {
        cout << "Valor fuera de los limites" << endl;
        }
    } while (i < 20);
    cout << endl;
    }

    void mostrar_valores(short int lista[tam], int contador1) {
    cout << "Valores ingresados no repetidos" << endl;
    for (int i = 0; i < contador1; i++) {
        cout << "Valor " << i + 1 << ": " << lista[i] << endl;
    }
}

////Funciones del ejercicio 4
void ejercicio4() {
    int salida = 1;
    cout << "Autores: Daniel Mera y Juan Naranjo" << endl;
    cout << "resultados de la suma de lanzar dos dados 36000 veces" << endl;
    while (salida != 0) {
        int contador2 = 0, contador3 = 0, contador4 = 0, contador5 = 0,
            contador6 = 0, contador7 = 0, contador8 = 0, contador9 = 0,
            contador10 = 0, contador11 = 0, contador12 = 0;
        int numerosAleatorios[limite], numerosAleatorios2[limite],
            srand(time(NULL));
        aleatorio(numerosAleatorios, numerosAleatorios2);
        suma(numerosAleatorios, numerosAleatorios2, contador2, contador3, contador4,
            contador5, contador6, contador7, contador8, contador9, contador10,
            contador11, contador12);
        cout << endl;
        cout << "veces que los dados sumaron 2: " << contador2 << endl;
        cout << "veces que los dados sumaron 3: " << contador3 << endl;
        cout << "veces que los dados sumaron 4: " << contador4 << endl;
        cout << "veces que los dados sumaron 5: " << contador5 << endl;
        cout << "veces que los dados sumaron 6: " << contador6 << endl;
        cout << "veces que los dados sumaron 7: " << contador7 << endl;
        cout << "veces que los dados sumaron 8: " << contador8 << endl;
        cout << "veces que los dados sumaron 9: " << contador9 << endl;
        cout << "veces que los dados sumaron 10: " << contador10 << endl;
        cout << "veces que los dados sumaron 11: " << contador11 << endl;
        cout << "veces que los dados sumaron 12: " << contador12 << endl;
        cout << endl
            << "presione 0 para salir" << endl
            << "presione otro numero para hacer nuevos lanzamientos" << endl;
        cin >> salida;
    }
}

void aleatorio(int arreglo[], int arreglo2[]) {
    srand(time(NULL));
    for (int i = 0, j = 0; i < limite; i++, j++) {
        arreglo[i] = 1 + rand() % (6);
        arreglo2[i] = 1 + rand() % (6);
    }
}

void suma(int arreglo1[], int arreglo2[], int &contador2, int &contador3,
            int &contador4, int &contador5, int &contador6, int &contador7,
            int &contador8, int &contador9, int &contador10, int &contador11,
            int &contador12) {
    int suma[limite];
    for (int i = 0; i < limite; i++) {
        suma[i] = arreglo1[i] + arreglo2[i];

        if (suma[i] == 2) {
        contador2++;
        }
        if (suma[i] == 3) {
        contador3++;
        }
        if (suma[i] == 4) {
        contador4++;
        }
        if (suma[i] == 5) {
        contador5++;
        }
        if (suma[i] == 6) {
        contador6++;
        }
        if (suma[i] == 7) {
        contador7++;
        }
        if (suma[i] == 8) {
        contador8++;
        }
        if (suma[i] == 9) {
        contador9++;
        }
        if (suma[i] == 10) {
        contador10++;
        }
        if (suma[i] == 11) {
        contador11++;
        }
        if (suma[i] == 12) {
        contador12++;
        }
    }
}

//////////////////