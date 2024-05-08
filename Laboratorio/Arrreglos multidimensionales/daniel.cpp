#include <iostream>

using namespace std;

void burbuja();

int main(){
    int vector[6] = {3,7,1,0,2,3};

    int aux = 0;
    for (int i = 0; i < 6; i++)
    {
        for(int j=0;j<6;j++){
            if(vector[i]<vector[j]){
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }

    for(int i =0;i<6;i++){
        cout<<vector[i]<<" ";
    }
    cout << endl;
    
    return 0;
}



