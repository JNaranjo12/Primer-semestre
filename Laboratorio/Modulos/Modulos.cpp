#include <iostream>
using namespace std;
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
int main()
{
    int i = 5;
    int *puntero = &i;
    cout << endl;
    cout << *puntero << endl;
    int *puntero2;
    //*puntero2 = 8;
    cout << puntero2 << endl;
    cout << *puntero + *puntero2 << endl;
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

}