
#include <iostream>
using namespace std;

const int M= 3, N=3;
void imprimir(const int A[M][N]);
void transpuesta(const int A[M][N], int B[M][N]);
void suma(int A[M][N], int B[M][N], int C[M][N]);
void multiplicacion(int A[M][N], int B[M][N], int D[M][N]);
int traza(int D[M][N]);
int main(){
    int A[M][N]=    {{1,2,3},
                    {4,5,6},
                    {7,8,9}};
    int B[M][N];
    int C[M][N];
    int D[M][N];
    imprimir(A);
    cout << endl;
    transpuesta(A,B);
    imprimir(B);
    cout << endl;
    suma(A,B,C);
    imprimir(C);
    cout << endl;
    multiplicacion(A,B,D);
    imprimir (D);
    cout << endl;

    cout << "La traza es: " << traza(D) << endl;
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