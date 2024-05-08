#include <iostream>
using namespace std;
#include <fstream>

const int N = 100;

typedef struct { // Lista de longitud variable
   int elementos[N];
   int contador;
} tLista;

int main() {
   tLista lista;
   ifstream archivo;
   int dato, pos, tmp;
   lista.contador = 0;
   archivo.open("insercion.txt");
   if (!archivo.is_open()) {
      cout << "Error de apertura de archivo!" << endl;
   }
   else {
      archivo >> dato;
      while ((lista.contador < N) && (dato != -1)) {
      // Centinela -1 al final
         lista.elementos[lista.contador] = dato;
         lista.contador++;
         archivo >> dato;
      }
      archivo.close();
      // Si hay mas de N ignoramos el resto
      cout << "Antes de ordenar:" << endl;
      for (int i = 0; i < lista.contador; i++) {
         cout << lista.elementos[i] << "  ";
      }
      cout << endl;
      for (int i = 1; i < lista.contador; i++) {
         pos = i;
         while ((pos > 0) && (lista.elementos[pos-1] > lista.elementos[pos])) 
         {
            tmp = lista.elementos[pos];
            lista.elementos[pos] = lista.elementos[pos - 1];
            lista.elementos[pos - 1] = tmp;
            pos--;
         }
      }
      cout << "Despues de ordenar:" << endl;
      for (int i = 0; i < lista.contador; i++) {
         cout << lista.elementos[i] << "  ";
      }
      cout << endl;
   }
   return 0;
}