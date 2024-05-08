#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#include "citas.h"
#include "medicos.h"
#include "pacientes.h"
#include "color.h"
void guardarArchivoCitas(const tListaCitas &listaCitas) {
  ofstream archivoCitas;
  archivoCitas.open("citas.txt");
  for (int i = 0; i < listaCitas.contadorCitas; i++) {
    archivoCitas << listaCitas.elementosCitas[i].doctor << endl;
    archivoCitas << listaCitas.elementosCitas[i].paciente << endl;
    archivoCitas << listaCitas.elementosCitas[i].especialidad << endl;
    archivoCitas << listaCitas.elementosCitas[i].fecha << endl;
    archivoCitas << listaCitas.elementosCitas[i].hora << endl;
  }
  archivoCitas << "XXX" << endl;
  archivoCitas.close();
} //Guarda el archivo actualizado al final del módulo citas

void cargarArchivoCitas(tListaCitas &listaCitas, bool &okCitas) {
  tCitas citas;
  ifstream archivoCitas;
  char auxCitas;
  listaCitas.contadorCitas = 0;
  archivoCitas.open("citas.txt");
  if (!archivoCitas.is_open()) {
    okCitas = false;
  } else {
    okCitas = true;
    getline(archivoCitas, citas.doctor);
    while ((citas.doctor != "XXX") && (listaCitas.contadorCitas < maxCitas)) {
      getline(archivoCitas, citas.paciente);
      getline(archivoCitas, citas.especialidad);
      getline(archivoCitas, citas.fecha);
      getline(archivoCitas, citas.hora);
      listaCitas.elementosCitas[listaCitas.contadorCitas] = citas;
      listaCitas.contadorCitas++;
      getline(archivoCitas, citas.doctor);
    }
    archivoCitas.close();
  }
} //Función void que carga el archivo de texto con las citas almacenadas.

void buscarCitasDoctor(const tListaCitas listaCitas, string doctorCitas) {
  for (int i = 0; i < listaCitas.contadorCitas; i++) {
    if (listaCitas.elementosCitas[i].doctor == doctorCitas) {
      mostrarCita(listaCitas.elementosCitas[i]);
    }
  }
} //Función void que busca las citas según el nombre del doctor
void buscarCitasPaciente(const tListaCitas listaCitas, string pacienteCitas) {
  for (int i = 0; i < listaCitas.contadorCitas; i++) {
    if (listaCitas.elementosCitas[i].paciente == pacienteCitas) {
      mostrarCita(listaCitas.elementosCitas[i]);
    }
  }
}//Función void que busca las citas según el nombre del paciente.
void buscarCitasEspecialidad(const tListaCitas listaCitas,
                             string especialidadCitas) {
  for (int i = 0; i < listaCitas.contadorCitas; i++) {
    if (listaCitas.elementosCitas[i].especialidad == especialidadCitas) {
      mostrarCita(listaCitas.elementosCitas[i]);
    }
  }
}//Función void que busca las citas según la especialidad agendada.
void buscarCitasFecha(const tListaCitas listaCitas, string fechaCitas) {
  for (int i = 0; i < listaCitas.contadorCitas; i++) {
    if (listaCitas.elementosCitas[i].fecha == fechaCitas) {
      mostrarCita(listaCitas.elementosCitas[i]);
    }
  }
}//Función void que busca las citas en una fecha determinada.

void leerCita(tCitas &citas, tMedicos infoMedico, tPacientes paciente, const int contador,
              int &condicion) {
  cin.sync();
  cin.ignore();
  cout << " " << setfill('*') << setw(123) << '\n' << setfill(' ');
  cout << BLACK <<" - Nombre del Doctor: "<<RESET;
  getline(cin, citas.doctor);
  ifstream leer_archivo_M;
  leer_archivo_M.open("medicos.txt", ios::in);
  if (leer_archivo_M.fail()) {
    cout << RED<<"ERROR: Falla en el sistema"<<RESET; //si el archivo de texto de doctores no está abierto, muestra error
    exit(1);
  }
  for (int i = 1; i <= contador; i++) {
    leer_archivo_M >> infoMedico.cedula >> infoMedico.especialidad;
    getline(leer_archivo_M, infoMedico.nombre); //recoge toda la información del archivo medicos.txt
    if (" " + citas.doctor == infoMedico.nombre) {
      condicion = 0; //compara si el nombre del medico ingresado por el usuario existe en el archivo de medicos.
      break;
    } else {
      condicion = 1;
    }
  }
  leer_archivo_M.close();
  if (condicion == 1) {
    cout << RED <<"No se ha encontrado un doctor con ese nombre" << RESET << endl;
  } else { //si sí existe, continua registrando la cita.
    cout << GREEN <<" " << setfill('*') << setw(123) << '\n' << setfill(' ')<< RESET;
    cout << BLACK << " - Nombre del Paciente: " <<RESET;
    getline(cin, citas.paciente);
    ifstream archivoPacientes;
    archivoPacientes.open("pacientes.txt");
    if(!archivoPacientes.is_open()) { 
    cout <<RED<< "ERROR: Falla en el sistema"<<RESET;
    exit(1);
    }
    for (int i = 0; i < contador; i++) {
      getline(archivoPacientes, paciente.NombreCompleto);
      getline(archivoPacientes, paciente.Cedula);
      getline(archivoPacientes, paciente.FechaNacimiento);
      getline(archivoPacientes, paciente.sexo);
      getline(archivoPacientes, paciente.direccion);
      getline(archivoPacientes, paciente.NumeroTelefono);
    if (citas.paciente == paciente.NombreCompleto) {
      condicion = 0; //se utiliza el mismo sistema de validar el nombre del paciente que con la validación del nombre del médico
      break;
    } else {
      condicion = 1;
    }
  }
    archivoPacientes.close();
    if (condicion == 1) {
    cout << RED <<"No se ha encontrado un Paciente con ese nombre." << RESET<<endl;
  } else {
      cout << GREEN <<" " << setfill('*') << setw(123) << '\n' << setfill(' ')<< RESET;
      cout << BLACK << " - Especialidad agendada: " << RESET;
      getline(cin, citas.especialidad);
      cout << BLACK << " - Fecha agendada (dd-mm-aa): "<< RESET;
      getline(cin, citas.fecha);
      cout << BLACK << " - Hora agendada (Formato 24:00h): "<< RESET;
      getline(cin, citas.hora);
      cout << GREEN <<  " " << setfill('*') << setw(123) << '\n' << setfill(' ')<< RESET;
      cin.sync();
      }
  }
} //Función void que permite registrar una cita validando el nombre del doctor y del paciente.

void insertarCita(tListaCitas &listaCitas, tCitas citas, bool &okCitas) {
  okCitas = true;
  if (listaCitas.contadorCitas == maxCitas) {
    okCitas = false;
  } else {
    listaCitas.elementosCitas[listaCitas.contadorCitas] = citas;
    listaCitas.contadorCitas++;
  }
} //Función void que permite insertar la cita a la lista de citas.

void mostrarCita(tCitas citas) {
  cout << BLACK << citas.fecha << setw(14) << citas.hora << setw(22)
       << citas.especialidad << setw(35) << citas.doctor << setw(35)
       << citas.paciente << RESET<<endl;
} //Función void que muestra una cita.


void listadoCita(const tListaCitas listaCitas) {
  for (int i = 0; i < listaCitas.contadorCitas; i++) {
    cout << endl;
    cout << i + 1 << ": ";
    mostrarCita(listaCitas.elementosCitas[i]);
  }
} //Función void que con la lista de citas muestra todas las citas agendadas usando la función anterior de mostrar una cita.

void eliminarCita(tListaCitas &listaCitas, int posCitas, bool &okCitas) {
  if ((posCitas < 0) || (posCitas > listaCitas.contadorCitas - 1)) {
    okCitas = false;
  } else {
    okCitas = true;
    for (int i = posCitas; i < listaCitas.contadorCitas - 1; i++) {
      listaCitas.elementosCitas[i] = listaCitas.elementosCitas[i + 1];
    }
    listaCitas.contadorCitas--;
  }
} //Función void que permite eliminar una cita en base a su posición.

///////  Funcion utilizada para validar citas, por medio del paso por referencia se le asigna un valor a la variable condicion, dicha variable será utilizada en el main para realizar la validacion. Si la condición se le asigna valor de uno, en el programa principal se indicara que no pudo registrarse la cita. Con el cero pasaria el caso contrario////

void validar(tCitas citas, const tListaCitas &listaCitas, int &condicion) {

  for (int i = 0; i < listaCitas.contadorCitas - 1; i++) {
    
    if (citas.hora == listaCitas.elementosCitas[i].hora &&
        citas.fecha == listaCitas.elementosCitas[i].fecha &&
        citas.doctor == listaCitas.elementosCitas[i].doctor) {
      condicion = 1;
      i = 100;
    } else if (citas.hora != listaCitas.elementosCitas[i].hora) {
      condicion = 0;
    }
  }
}

void mostrarNombresDoctor(tMedicos infoMedico, const int contador) {
  ifstream leer_archivo_M;
  leer_archivo_M.open("medicos.txt", ios::in);
  if (leer_archivo_M.fail()) {
    cout << RED <<"ERROR: Falla en el sistema"<<RESET;
    exit(1);
  }
  cout << GREEN<<" " << setfill('*') << setw(123) << '\n' << setfill(' ')<<RESET;
  cout << GREEN << "|" << setw(60) <<ROSE<<"*Especialidad y Nombre De Doctores*" << RESET << setw(51) <<GREEN<<"|\n"<< RESET;
  cout <<GREEN<< " " << setfill('*') << setw(123) << '\n' << setfill(' ')<<RESET;
  for (int i = 1; i <= contador; i++) {
    leer_archivo_M >> infoMedico.cedula >> infoMedico.especialidad;
    getline(leer_archivo_M, infoMedico.nombre);
    cout << BLACK << "          "<<infoMedico.especialidad << 
      "          "<< setw(60) << infoMedico.nombre << RESET <<endl;
  }
  leer_archivo_M.close();
} //Función que muestra los nombres de los doctores y su especialidad para que el usuario los agende.


//Función utilizada para ordenar la lista de citas. Por orden alfabético.
void ordenar(tListaCitas &listaCitas) {
  int i, j;
  tCitas aux;
  for (i = 1; i < listaCitas.contadorCitas; i++)
    for (j = listaCitas.contadorCitas - 1; j >= i; j--)
      if (listaCitas.elementosCitas[j - 1].doctor >
          listaCitas.elementosCitas[j].doctor) {
        aux = listaCitas.elementosCitas[j - 1];
        listaCitas.elementosCitas[j - 1] = listaCitas.elementosCitas[j];
        listaCitas.elementosCitas[j] = aux;
      }
}
