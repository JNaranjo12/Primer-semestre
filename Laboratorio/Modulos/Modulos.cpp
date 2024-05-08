#include <iostream>
using namespace std;

int main() {
    int num, fib, fibMenos2 = 0, fibMenos1 = 1; // 1º y 2º
    fib = fibMenos2 + fibMenos1; // Calculamos el tercero
    cout << "Hasta: ";
    cin >> num;
    if (num >= 1) { // Ha de ser entero positivo
        cout << "0 1 "; // Los dos primeros son <= num
        while (fib <= num) { // Mientras no mayor que num
            cout << fib << " ";
            fibMenos2 = fibMenos1; // Actualizamos anteriores
            fibMenos1 = fib; // para obtener...
            fib = fibMenos2 + fibMenos1; // ... el siguiente
        }
    }
}




/*void num(int a, int b, int &c){
    a = b + c;
    b = a + c;
    c = a + b;
}*/
/*int a;
void fun(int &b)
{
    a = 3;
    b =  a * b;

}*/
/*int main()
{
    int i = 5;
    int *puntero = &i;
    cout << endl;
    cout << *puntero << endl;
    int *puntero2;
    //*puntero2 = 8;
    cout << puntero2 << endl;
    cout << *puntero + *puntero2 << endl;*/
    /*int x = 3, y = 5;
    num(x,y,y);
    cout << x << endl << y;
    return 0;*/

    /*int x = 15, y = 25;
    cout  << endl;
    cout  << endl;
    cout  << endl;
    cout << mcd(x,y);
    return (0);*/
    /*a = 2;
    fun(a);
    cout << a << endl;
    return 0;*/ 

