#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#include "pacientes.h"
#include "color.h"


void guardarArchivoPacientes(const tListaPacientes &listaPacientes) {
  ofstream archivoPacientes;
  archivoPacientes.open("pacientes.txt");
  for (int i = 0; i < listaPacientes.contadorPacientes; i++) {
    archivoPacientes << listaPacientes.elementosPacientes[i].NombreCompleto
                     << endl;
    archivoPacientes << listaPacientes.elementosPacientes[i].Cedula << endl;
    archivoPacientes << listaPacientes.elementosPacientes[i].FechaNacimiento
                     << endl;
    archivoPacientes << listaPacientes.elementosPacientes[i].sexo << endl;
    archivoPacientes << listaPacientes.elementosPacientes[i].direccion << endl;
    archivoPacientes << listaPacientes.elementosPacientes[i].NumeroTelefono
                     << endl;
  }
  archivoPacientes << "XXX" << endl;
  archivoPacientes.close();
}

void cargarArchivoPacientes(tListaPacientes &listaPacientes, bool &okPacientes) {
  tPacientes pacientes;
  ifstream archivoPacientes;
  char auxPacientes;
  listaPacientes.contadorPacientes = 0;
  archivoPacientes.open("pacientes.txt");
  if (!archivoPacientes.is_open()) {
    okPacientes = false;
  } else {
    okPacientes = true;
    getline(archivoPacientes, pacientes.NombreCompleto);
    while ((pacientes.NombreCompleto != "XXX") &&
           (listaPacientes.contadorPacientes < maxPacientes)) {
      getline(archivoPacientes, pacientes.Cedula);
      getline(archivoPacientes, pacientes.FechaNacimiento);
      getline(archivoPacientes, pacientes.sexo);
      getline(archivoPacientes, pacientes.direccion);
      getline(archivoPacientes, pacientes.NumeroTelefono);
      // archivoCitas.get(auxCitas);
      listaPacientes.elementosPacientes[listaPacientes.contadorPacientes] =
          pacientes;
      listaPacientes.contadorPacientes++;
      getline(archivoPacientes, pacientes.NombreCompleto);
    }
    archivoPacientes.close();
  }
}

void buscarPacientes(const tListaPacientes listaPacientes,
                     string nPacientes) {
  for (int i = 0; i < listaPacientes.contadorPacientes; i++) {
    if (listaPacientes.elementosPacientes[i].Cedula == nPacientes) {
      cout<< ORANGE <<" "<<setfill('-')<<setw(123)<<'\n'<<setfill(' ') << RESET;
      cout<<ROSE<<" Cédula"<<setw(12)<<"Fecha"<<setw(12)<<"Sexo"<<setw(27)<<"Dirección"<<setw(16)<<"Teléfono"<<setw(34)<<"Nombre"<<RESET<<endl;
      cout<<ORANGE<<" "<<setfill('-')<<setw(123)<<'\n'<<setfill(' ')<<RESET;
      mostrarPacientes(listaPacientes.elementosPacientes[i]);
    }
  }
}

void modificarPacientes(tListaPacientes &listaPacientes){
  string posicion_CI;
  int i= 0, opcion;
  cout << "Número de cédula del paciente a modificar: ";
  cin >> posicion_CI;
  
  while(!(posicion_CI == listaPacientes.elementosPacientes[i].Cedula) && (i <= listaPacientes.contadorPacientes)) { // Desplazamos a la izquierda
    i++;
  }
  if(posicion_CI == listaPacientes.elementosPacientes[i].Cedula){
    do {  
      cout << endl;
      //esto toca hacer con el formato de los demas menús
      cout << ORANGE<< " " << setfill('*') << setw(123) << '\n' << setfill(' ') << RESET;
  cout << ORANGE <<"|" << setw(75) << ROSE <<"*Modificación por*" <<RESET<< setw(53) <<ORANGE<< "|\n";
  cout << ORANGE" " << setfill('*') << setw(121) << '\n' << setfill(' ');
  cout << " " << setfill('-') << setw(121) << '\n' << setfill(' ');
  cout << "|"<< RESET
       <<BLACK<< "1." << setw(121) << right << "Modificar Cédula."<< RESET<< ORANGE<<"|\n"<<RESET;
  cout <<ORANGE<<"|"
       <<BLACK << "2." << setw(120) << "Modificar Nombre."<< RESET<< ORANGE<<"|\n"<<RESET;
  cout << "|"
       <<BLACK << "3." << setw(121) << "Modificar Dirección."<< RESET<< ORANGE<<"|\n"<<RESET;
  cout << "|"
       <<BLACK << "4." << setw(121) << "Modificar Teléfono."<< RESET<< ORANGE<<"|\n"<<RESET;
  cout << "|"
       <<BLACK << "0." << setw(120) << "Salir."<< RESET<< ORANGE<<"|\n"<<RESET;
  cout <<ORANGE<< " " << setfill('-') << setw(121) << '\n' << setfill(' ')<<RESET;
      cout <<BLACK<< "Opcion: " <<RESET;
      cin >> opcion;
      if ((opcion < 0) || (opcion > 4)){
        cout << RED<<"Opcion invalida, intente de nuevo" << RESET<< endl;
      }
      cout << endl;
    }while((opcion < 0) || (opcion > 4));
  
    switch(opcion){
      case 1:
        cout << BLACK<<"Ingrese la nueva Cedula: "<< RESET;
        cin >> listaPacientes.elementosPacientes[i].Cedula;
        break;
  
      case 2:
        cin.ignore();
        cout <<BLACK<< "Ingrese el nuevo Nombre: "<<RESET;
        getline(cin, listaPacientes.elementosPacientes[i].NombreCompleto);
        break;
        
      case 3:
        cin.ignore();
        cout <<BLACK<< "Ingrese la nueva Direccion: "<<RESET;
        getline(cin, listaPacientes.elementosPacientes[i].direccion);
        break;
      
      case 4:
        cout <<BLACK<< "Ingrese la nuevo Teléfono: "<<RESET;
        cin >> listaPacientes.elementosPacientes[i].NumeroTelefono;
        break;
    }
  } else{
    cout << RED<<"No existe Paciete con esa Cédula" <<RESET<< endl;
  }
  cin.ignore(); /////
}
void leerPacientes(tPacientes &pacientes) {
  cin.sync();
  cin.ignore();
  cout <<ORANGE << " " << setfill('*') << setw(123) << '\n' << setfill(' ')<<RESET;
  cout << BLACK<<" - Nombre completo del Paciente: ";
  getline(cin, pacientes.NombreCompleto);
  cout << BLACK<<" - Número de cédula del Paciente: ";
  getline(cin, pacientes.Cedula);
  cout << BLACK<<" - Fecha de nacimiento (dd-mm-aa): ";
  getline(cin, pacientes.FechaNacimiento);
  cout <<BLACK<< " - Sexo (masculino/femenino): ";
  getline(cin, pacientes.sexo);
  cout << " - Dirección: ";
  getline(cin, pacientes.direccion);
  cout <<BLACK<< " - Número de teléfono: "<< RESET;
  getline(cin, pacientes.NumeroTelefono);
  cout << ORANGE<< " " << setfill('*') << setw(123) << '\n' << setfill(' ')<<RESET;
  cin.sync();
}

void insertarPacientes(tListaPacientes &listaPacientes, tPacientes pacientes, bool &okPacientes) {
  okPacientes = true;
  if (listaPacientes.contadorPacientes == maxPacientes) {
    okPacientes = false;
  } else {
    listaPacientes.elementosPacientes[listaPacientes.contadorPacientes] =
        pacientes;
    listaPacientes.contadorPacientes++;
  }
}

void mostrarPacientes(tPacientes pacientes) {
  cout << BLACK << pacientes.Cedula << setw(12) << pacientes.FechaNacimiento << setw(12) << pacientes.sexo << setw(40) << pacientes.direccion << setw(12) << pacientes.NumeroTelefono << setw(35) << pacientes.NombreCompleto << RESET<<endl;
}

void listadoPacientes(const tListaPacientes listaPacientes) {
  for (int i = 0; i < listaPacientes.contadorPacientes; i++) {
cout <<BLACK<< i + 1 << ":"<<RESET;
mostrarPacientes(listaPacientes.elementosPacientes[i]);
  }
}

void eliminarPacientes(tListaPacientes &listaPacientes, int posPacientes,
                       bool &okPacientes) {
  if ((posPacientes < 0) ||
      (posPacientes > listaPacientes.contadorPacientes - 1)) {
    okPacientes = false;
  } else {
    okPacientes = true;
    for (int i = posPacientes; i < listaPacientes.contadorPacientes - 1; i++) {
      listaPacientes.elementosPacientes[i] =
          listaPacientes.elementosPacientes[i + 1];
    }
    listaPacientes.contadorPacientes--;
  }
}
