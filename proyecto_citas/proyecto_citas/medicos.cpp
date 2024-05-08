#include <iostream>
#include <iomanip>
using namespace std;
#include <fstream>
#include "medicos.h"
#include "color.h"

ifstream leer_archivo_M;
ofstream guardar_archivo_Medicos;

////// Procedimientos y funciones que ayudan al programa pero interactuan directamente con el usuario
void cargar_Archivo_M(tCantMedicos &lista_Medicos, const int contador){  //Procedimiento que se encarga de cargar los datos del archivo a una lista
  char aux;
  lista_Medicos.cont_lista = 0;
  leer_archivo_M.open("medicos.txt", ios::in);
  if(leer_archivo_M.fail()){
    cout <<RED<< "ERROR: Falla en el sistema"<<RESET;
    exit(1);
  } else{
    for(int i = 0; i < contador; i++){
      //cin.ignore();
      leer_archivo_M >> lista_Medicos.medico[i].cedula >> lista_Medicos.medico[i].especialidad;
      //cin.get(aux);
      getline(leer_archivo_M, lista_Medicos.medico[i].nombre);
      lista_Medicos.cont_lista++;
    }
  }
  leer_archivo_M.close();
}

void guardar_en_archivo_M(const tCantMedicos lista_Medicos){ //Procedimiento que se encarga de guardar los datos de la lista al archivo
  guardar_archivo_Medicos.open("medicos.txt", ios::out); 
  if(guardar_archivo_Medicos.fail()){
    cout <<RED<< "ERROR: Falla en el sistema"<<RESET;
    exit(1);
  }else{
    for(int i = 0; i < lista_Medicos.cont_lista; i++){
      guardar_archivo_Medicos << lista_Medicos.medico[i].cedula << " "; 
      guardar_archivo_Medicos << lista_Medicos.medico[i].especialidad;
      guardar_archivo_Medicos << lista_Medicos.medico[i].nombre << endl; 
    }
  }
  guardar_archivo_Medicos.close();
}

int contar_Medicos(){ //Funcion que cuenta el numero de lineas en el archivo de medicos 
  string leer_linea;
  int num_lineas = 0;
  leer_archivo_M.open("medicos.txt", ios::in);
  if(leer_archivo_M.fail()){
    cout <<RED<< "ERROR: Falla en el sistema"<<RESET;
    exit(1);
  } 
  while(!leer_archivo_M.eof()){
    getline(leer_archivo_M, leer_linea);
    num_lineas++; 
  }
  leer_archivo_M.close();
  return num_lineas - 1; //Devuelve el numero de lineas del archivo restado uno
}

/////// Procedimientos que interactuan con el usuario
void cargar_Medico(const tMedicos infoMedico, bool &archivo_lleno){ //Procedimiento que carga un medico al archivo medicos.txt
  int llenadura_Archivo; 
  llenadura_Archivo = contar_Medicos();
  
  guardar_archivo_Medicos.open("medicos.txt", ios::app); //ios::app permite abrir medicos.txt sin modificar el contenido que tenia previamente cargado
  if(llenadura_Archivo <= TAM ){
    guardar_archivo_Medicos << infoMedico.cedula << " " << infoMedico.especialidad << " " << infoMedico.nombre << endl;
   llenadura_Archivo++; 
  } else{
    archivo_lleno = true;
    cout <<RED<< "Capacidad de medicos superada" <<RESET<< endl;
    cin.ignore(); /////
  }
  guardar_archivo_Medicos.close();
  //cin.get(aux);
}

void ingresar_Medico(tMedicos &infoMedico){ //Guarda la informacion de un medico en la estructura tMedicos
  cin.ignore();
  cout << " " << setfill('*') << setw(123) << '\n' << setfill(' ');
  cout <<BLACK<< "Nombre del medico: ";
  getline(cin,infoMedico.nombre);
  //cin.get(aux);
  cout <<BLACK<< "Cedula del medico: ";
  getline(cin,infoMedico.cedula);
  //cin.get(aux);
  cout <<BLACK<< "Especialidad del medico: ";
  getline(cin,infoMedico.especialidad);
  cout << " " << setfill('*') << setw(123) << '\n' << setfill(' ');
  cin.sync();
  //cin.get(aux);
}

void buscar_Medico(tMedicos infoMedico, const int contador){ //Procedimiento que busca y muestra un medico  a traves de la cedula 
  string cedula_M;
  bool aux = false;
  cout <<BLACK<< "Ingresar cedula medico: "<<RESET;
  cin >> cedula_M;
  leer_archivo_M.open("medicos.txt", ios::in);
  if(leer_archivo_M.fail()){
    cout <<RED<< "ERROR: Falla en el sistema"<<RESET;
    exit(1);
  } 
  for(int i = 1; i <= contador; i++){
    leer_archivo_M >> infoMedico.cedula >> infoMedico.especialidad;
    getline(leer_archivo_M, infoMedico.nombre);
    
    if(infoMedico.cedula == cedula_M){
      cout << "\n";
  cout <<CYAN<< " " << setfill('*') << setw(123) << '\n' << setfill(' ');
  cout <<CYAN<< "|" << setw(75) <<ROSE<<"*INFORMACION DEL MEDICO*" << setw(49) <<RESET<< "|\n";
  cout <<CYAN<< " " << setfill('*') << setw(123) << '\n' << setfill(' ');
  cout <<CYAN<<" "<<setfill('-')<<setw(123)<<'\n'<<setfill(' ');
  cout <<CYAN<<" Cedula"<<setw(53)<<"Doctor"<<setw(45)<<"Especialidad" << endl;
  cout <<CYAN<<" "<<setfill('-')<<setw(123)<<'\n'<<setfill(' ')<<RESET;
      cout <<BLACK<< infoMedico.cedula<<setw(51) << infoMedico.nombre << setw(43) << infoMedico.especialidad <<RESET<< endl;
      aux = true;
    }
    if((i == contador) && (aux == false)){
      cout <<RED<< "El medico no consta en la lista" <<RESET<< endl; 
    }
  }
  leer_archivo_M.close();
  cin.ignore(); ////
}

void modificar_Medico(tCantMedicos &lista_Medicos){ //Procedimiento que modifica un medico a traves de la cedula
  string posicion_CI;
  int aux = 0, opcion;
  cout <<BLACK<< "Numero de cedula del medico a modificar: "<<RESET;
  cin >> posicion_CI;
  
  while(!(posicion_CI == lista_Medicos.medico[aux].cedula) && (aux <= lista_Medicos.cont_lista)) { // Desplazamos a la izquierda
    aux++;
  }
  if(posicion_CI == lista_Medicos.medico[aux].cedula){
    do {  
      cout << endl;
  cout <<CYAN<< " " << setfill('*') << setw(121) << '\n' << setfill(' ');
  cout <<CYAN<< "|" << setw(75) <<ROSE<< "*Modificación por*" << setw(49) <<RESET<<CYAN<<"|\n";
  cout <<CYAN<< " " << setfill('*') << setw(121) << '\n' << setfill(' ');
  cout <<CYAN<< " " << setfill('-') << setw(121) << '\n' << setfill(' ');
  cout <<CYAN<< "|"
       <<BLACK<< "1." << setw(121) << right << "Modificar Cédula."<< RESET<< CYAN<<"|\n"<<RESET;
  cout <<CYAN<< "|"
       <<BLACK<< "2." << setw(120) << "Modificar Nombre."<< RESET<< CYAN<<"|\n"<<RESET;
  cout <<CYAN<< "|"
       << "3." << setw(120) << "Modificar Especialidad."<< RESET<< CYAN<<"|\n"<<RESET;
  cout <<CYAN<< "|"
       <<BLACK<< "0." << setw(120) << "Salir."<< RESET<< CYAN<<"|\n"<<RESET;
  cout <<CYAN<< " " << setfill('-') << setw(121) << '\n' << setfill(' ');
      cout <<BLACK<< "Opcion: "<<RESET;
      cin >> opcion;
      if ((opcion < 0) || (opcion > 3)){
        cout <<RED<< "Opcion invalida, intente de nuevo" <<RESET<< endl;
      }
      cout << endl;
    }while((opcion < 0) || (opcion > 3));
  
    switch(opcion){
      case 1:
        cout <<BLACK<< "Ingrese la nueva cedula: ";
        cin >> lista_Medicos.medico[aux].cedula;
        break;
  
      case 2:
        cin.ignore();
        cout <<BLACK<< "Ingrese el nuevo nombre: ";
        getline(cin, lista_Medicos.medico[aux].nombre);
        break;
        
      case 3:
        cout <<BLACK<< "Ingrese la nueva especialidad: ";
        cin >> lista_Medicos.medico[aux].especialidad;
        break;
    }
  } else{
    cout <<RED<< "No existe medico con esa cedula" <<RESET<< endl;
  }
  cin.ignore(); /////
}

void eliminar_Medico(tCantMedicos &lista_Medicos){ //Procedimiento que elimina un medico a traves de la cedula
  string posicion_CI;
  int aux = 0;
  cout <<BLACK<< "Numero de cedula del medico a eliminar: "<<RESET;
  cin >> posicion_CI;
  
  while(!(posicion_CI == lista_Medicos.medico[aux].cedula) && (aux <= lista_Medicos.cont_lista)) { 
    aux++;
  }
  if(posicion_CI == lista_Medicos.medico[aux].cedula){ 
    for (int i = aux; i < lista_Medicos.cont_lista - 1; i++) { // Desplazamos a la izquierda
        lista_Medicos.medico[i] = lista_Medicos.medico[i + 1];
    }
    lista_Medicos.cont_lista--;
  } else{
    cout <<RED<< "No existe medico con esa cedula" <<RESET<< endl;
  }
  cin.ignore(); //////
}

void mostrar_Medicos(tMedicos infoMedico, const int contador){ //Procedimiento que muestra los medicos 
  //char aux;
  leer_archivo_M.open("medicos.txt", ios::in);
  if(leer_archivo_M.fail()){
    cout <<RED<< "ERROR: Falla en el sistema"<<RESET;
    exit(1);
  } 
  cout <<YELLOW<< " " << setfill('*') << setw(123) << '\n' << setfill(' ');
  cout <<YELLOW<< "|" << setw(73) <<ROSE<< "*LISTA DEL MEDICOS*" <<RESET<< setw(51) << "|\n";
  cout <<YELLOW<< " " << setfill('*') << setw(123) << '\n' << setfill(' ');
      cout<<YELLOW<<" "<<setfill('-')<<setw(123)<<'\n'<<setfill(' ');
          cout<<ROSE<<" Cedula"<<setw(53)<<"Doctor"<<setw(45)<<"Especialidad" <<RESET<< endl;
          
      cout <<BLACK<< infoMedico.cedula << infoMedico.nombre << infoMedico.especialidad <<RESET<< endl;
  
  for(int i = 1; i <= contador; i++){
    //cin.ignore();
    leer_archivo_M >> infoMedico.cedula >> infoMedico.especialidad;
    getline(leer_archivo_M, infoMedico.nombre);
    cout <<BLACK<< i  << ". "<< infoMedico.cedula <<setw(49)<< infoMedico.nombre << setw(43) << infoMedico.especialidad <<RESET<< endl;
   
  }
  leer_archivo_M.close();
  cin.ignore(); ////
}