
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int M= 3, N=3;
void imprimir(const int A[M][N]);
void transpuesta(const int A[M][N], int B[M][N]);
void suma(int A[M][N], int B[M][N], int C[M][N]);
void multiplicacion(int A[M][N], int B[M][N], int D[M][N]);
int traza(int D[M][N]);
void leerMatriz(int E[M][N]);
int main(){
    int A[M][N]=    {{1,2,3},
                    {4,5,6},
                    {7,8,9}};
    int B[M][N];
    int C[M][N];
    int D[M][N];
    int E[M][N];
    int F[M][N];
    cout << "Matriz A " << endl; 
    imprimir(A);
    cout << endl;
    
    //Transpuesta de una matriz
    transpuesta(A,B);
    cout << "Transpuesta de la matriz A\nMatriz B = transpuesta de matriz A" << endl;
    imprimir(B);
    cout << endl;
    
    // Suma de matrices 
    suma(A,B,C);
    cout << "Suma de matrices \nC = A + B" << endl;
    imprimir(C);
    cout << endl;

    //Multiplicacion de matrices
    multiplicacion(A,B,D);
    cout << "Multiplicacion de matrices \nD = A * B" << endl;
    imprimir (D);
    cout << endl;

    //Traza de una matriz = A la suma de los numeros que conforman la diagonal principal
    cout << "La traza de la matriz D es: " << traza(D) << endl <<endl;

    //Matriz extraida desde un archivo de texto
    leerMatriz(E);
    cout << "Matriz E extraida desde un archivo de texto" << endl;
    imprimir (E);
    cout << endl;
    //Suma de matris con la matriz extraida del archivo de texto
    suma(A, E, F);
    cout << "Suma de matrices \nF = A + E" << endl;
    imprimir(F);
    return 0;
}

void imprimir(const int A[M][N]){
    for (int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    } 
}

void transpuesta(const int A[M][N], int B[M][N]){
    for (int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            B[j][i] = A[i][j];
        }
    }
}    

void suma( int A[M][N], int B[M][N], int C[M][N]){
    for (int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            C[i][j] = A[i][j] + B[i][j];
            //cout << C[i][j] << endl;
        }
    }
}

void multiplicacion(int A[M][N], int B[M][N], int D[M][N]){
    int Q = 3;
    for (int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            for (int k = 0; k < Q; k++){
                D[i][j] = 0;
                 D[i][j] = D[i][j] +  (A[i][k] * B[i][j]);
            }
        }
    }
}

int traza(int D[M][N]){
    int resultado = 0;
    for (int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(i == j){
                resultado += D[i][j];
            }
        }
    }
    return resultado;
}

void leerMatriz(int E[M][N]){
    int unidades, unidades2;
    char aux;
    string aux2;
    ifstream archivo;
    archivo.open("matriz.txt");
    if(archivo.is_open()){
            for (int i = 0; i < M; i++){
                for(int j = 0; j < N; j++){
                    archivo >> unidades;
                    E[i][j] = unidades;
                    archivo.get(aux); 
                }
            }
    }
    archivo.close();
}