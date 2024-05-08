#include <iomanip>
#include <iostream>
using namespace std;
#include "citas.h"
#include "medicos.h"
#include "pacientes.h"
#include "color.h"
// menú principal medicos, pacientes y citas
int menuPrincipal();
// menú medicos, pacientes y citas; buscar, ingresar, modificar, eliminar,
// imprimir
int menuMedicos();
int menuPacientes();
int menuCitas();

tListaPacientes listaPacientes;
tPacientes pacientes;
bool okPacientes;
int posPacientes;
string busPacientes;
char auxPacientes;

int main() {
  int opPrincipal, opMedico = 1, opPaciente = 1, opCitas = 1, condicion, salida;
  /// Variables Medicos
  bool archivo_lleno_M = false;
  int contador_M;
  tMedicos infoMedico;
  tCantMedicos lista_Medicos;
  char continuar_Ingresando_Medico;
  ///////////
  opPrincipal = menuPrincipal();
  switch (opPrincipal) {
  case (1):
    while (opMedico != 0) {
      opMedico = menuMedicos();
      switch (opMedico) {
      case (1):
        // caso que busca un médico
        contador_M = contar_Medicos(); //contador_M recibe el numero de lineas del archivo medicos.txt
        buscar_Medico(infoMedico, contador_M);
        break;
      case (2):
        // caso que ingresa un médico
        do { //El bucle permite ingresar medicos al archivo medicos.txt 
          ingresar_Medico(infoMedico);
          cargar_Medico(infoMedico, archivo_lleno_M);
          cout <<GREEN<< "'0'Para salir, otra tecla para continuar: "<<RESET;
          cin >> continuar_Ingresando_Medico;
        } while ((continuar_Ingresando_Medico != '0') && (!archivo_lleno_M)); 
        break;
      case (3):
        // caso que modifica un médico
        contador_M = contar_Medicos();
        cargar_Archivo_M(lista_Medicos, contador_M); //Carga los datos de medicos.txt a una estructura que contiene una lista
        modificar_Medico(lista_Medicos);
        guardar_en_archivo_M(lista_Medicos);   //Guarda la lista con la informacion modificada a medicos.txt
        break;
      case (4):
        // caso que elimina un médico
        contador_M = contar_Medicos();
        mostrar_Medicos(infoMedico, contador_M); //Muestra la lista de medicos antes de eliminar
        cout << endl;
        cargar_Archivo_M(lista_Medicos, contador_M);
        eliminar_Medico(lista_Medicos);
        guardar_en_archivo_M(lista_Medicos);
        break;
      case (5):
        // caso que muestra todos los medicos
        contador_M = contar_Medicos();
        mostrar_Medicos(infoMedico, contador_M);
        cout << YELLOW<< " " << setfill('-') << setw(123) << '\n' << setfill(' ')<<RESET;
        break;
      }
    }
    main();
    break;
  case (2):
    cargarArchivoPacientes(listaPacientes, okPacientes);
    if (!okPacientes) {
      cout <<RED<< "No se ha podido cargar el archivo Pacientes!" <<RESET<< endl;
    } else {
      while (opPaciente != 0) {
        opPaciente = menuPacientes();
        switch (opPaciente) {
        case (1):
          cin.sync();
          cin.ignore();
          cout <<BLACK<< " - Ingrese la cédula del paciente que quiere conocer: "<<RESET;
          getline(cin, busPacientes);
          cout << endl;
          buscarPacientes(listaPacientes, busPacientes);
          cout <<ORANGE << " " << setfill('-') << setw(121) << '\n' << setfill(' ')<<RESET;
          cout << endl;
          cin.sync();
          // funcion que busque un paciente
          break;
        case (2):
          leerPacientes(pacientes);
          insertarPacientes(listaPacientes, pacientes, okPacientes);
          if (!okPacientes) {
            cout <<RED<< "*" << setw(75)
                 << "------Lista de Pacientes llena, imposible ingresar!------"
                 <<RESET<< setw(48) << "*" << endl;
          }
          // funcion que ingrese un paciente
          break;
        case (3):
          cargarArchivoPacientes(listaPacientes, okPacientes);
          modificarPacientes(listaPacientes);
          guardarArchivoPacientes(listaPacientes);
          // funcion que modifique un paciente
          break;
        case (4):
          cout <<ORANGE << " " << setfill('-') << setw(123) << '\n' << setfill(' ')<< RESET;
          cout <<ROSE<< " Cédula" << setw(12) << "Fecha" << setw(12) << "Sexo"
               << setw(32) << "Dirección" << setw(24) << "Teléfono" << setw(31)
               << "Nombre" << RESET <<endl;
          cout <<ORANGE<< " " << setfill('-') << setw(123) << '\n' << setfill(' ')<< RESET;
          listadoPacientes(listaPacientes);
          cout <<ORANGE << " " << setfill('-') << setw(123) << '\n' << setfill(' ')<< RESET;
          cout <<BLACK<< " - Ingrese la posición del paciente que desea eliminar: "<<RESET;
          cin >> posPacientes;
          eliminarPacientes(listaPacientes, posPacientes - 1, okPacientes);
          if (!okPacientes) {
            cout <<RED<< "*" << setw(75) << "------Elemento inexistente!------"
                 << setw(48) << "*" <<RESET<< endl;
          }
          // funcion que elimine un paciente
          break;
        case (5):
          cout <<ORANGE << " " << setfill('-') << setw(123) << '\n' << setfill(' ')<< RESET;
          cout <<ROSE<< " Cédula" << setw(12) << "Fecha" << setw(12) << "Sexo"
               << setw(32) << "Dirección" << setw(24) << "Teléfono" << setw(31)
               << "Nombre" << RESET <<endl;
          cout <<ORANGE<< " " << setfill('-') << setw(123) << '\n' << setfill(' ')<< RESET;
          listadoPacientes(listaPacientes);
          cout <<ORANGE << " " << setfill('-') << setw(123) << '\n' << setfill(' ')<< RESET;
          
          // funcion que imprima a los paciententes
        }
        guardarArchivoPacientes(listaPacientes);
      }
      main();
    }
    // funcion que imprima a los paciententes
    break;
  case (3): //Comienza el módulo de citas.
    tListaCitas listaCitas;
    tCitas citas;
    bool exitoCitas;
    int posCitas, posicion;
    int salida = 1, condicion = 2;
    string busDoctorCitas, busPacienteCitas, busEspecialidadCitas,
        busFechaCitas;
    char aux;
    cargarArchivoCitas(listaCitas, exitoCitas); //Abrir el archivo de citas.txt.
    if (!exitoCitas) {
      cout <<RED<< "No se ha podido cargar el archivo de Citas!" <<RESET<< endl;
    } else {
      while (opCitas != 0) {
        opCitas = menuCitas(); //Despliega el menú de Citas
        switch (opCitas) {
        case (1):
          int opBusquedaCitas;
          //Buscar una cita
          cout << endl;
          cout <<ORANGE << " " << setfill('*') << setw(123) << '\n' << setfill(' ');
          cout << "|" <<RESET<< setw(71) << ROSE<< "*Busca de Citas Médicas*" << RESET << setw(62)<<ORANGE<< "|\n";
          cout <<ORANGE<< " " << setfill('*') << setw(123) << '\n' << setfill(' ');
          cout <<ORANGE<< " " << setfill('-') << setw(123) << '\n' << setfill(' ');
          cout << "|"<<RESET
               << BLACK<<"1." << setw(120) << right << "En base a Doctores."<< RESET<< ORANGE<<"|\n"<<RESET;
          cout <<ORANGE<< "|"
               <<BLACK<< "2." << setw(120) << "En base a Pacientes."<< RESET<< ORANGE<<"|\n"<<RESET;
          cout <<ORANGE<< "|"
               << BLACK<<"3." << setw(120) << "En base a Especialidades."<< RESET<< ORANGE<<"|\n"<<RESET;
          cout <<ORANGE<< "|"
               << BLACK<<"4." << setw(120) << "En base a Fechas."<< RESET<< ORANGE<<"|\n"<<RESET;
          cout << ORANGE<<"|"
               <<BLACK<< "0." << setw(120) << "Salir."<< RESET<< ORANGE<<"|\n"<<RESET;
          cout <<ORANGE << " " << setfill('-') << setw(123) << '\n' << setfill(' ');
          cout << BLACK <<"Opción: ";
          cin >> opBusquedaCitas; //Menú en el que el usuario decida en base a que buscar las citas.

          switch (opBusquedaCitas) {
          case (1): //En base a Medicos
            cout <<GREEN<< " " << setfill('*') << setw(123) << '\n' << setfill(' ');
            cout <<BLACK<< " - Ingrese el nombre del doctor cuyas citas quiere conocer: "<<RESET<< endl;
            cin.sync();
            cin.ignore();
            getline(cin, busDoctorCitas);
            cout << endl;
            cout <<GREEN<< " " << setfill('-') << setw(123) << '\n' << setfill(' ')<<RESET;
            cout <<ROSE<< "    Fecha" << setw(18) << "Hora" << setw(24)
                 << "Especialidad" << setw(32) << "Doctor" << setw(30)
                 << "Paciente" << RESET<<endl;
            cout <<GREEN<< " " << setfill('-') << setw(123) << '\n' << setfill(' ')<< RESET;
            buscarCitasDoctor(listaCitas, busDoctorCitas);
            cout <<GREEN<< " " << setfill('*') << setw(123) << '\n' << setfill(' ');
            cout << endl;
            cin.sync();
            break;
          case (2)://En base a Pacientes
            cout << endl;
            cout <<GREEN<< " " << setfill('-') << setw(123) << '\n' << setfill(' ')<<RESET;
            cout <<BLACK<< " - Ingrese el nombre del paciente cuyas citas quiere conocer: " <<RESET<< endl;
            cin.sync();
            cin.ignore();
            getline(cin, busPacienteCitas);
            cout << endl;
            cout <<GREEN<< " " << setfill('-') << setw(123) << '\n' << setfill(' ')<<RESET;
            cout <<ROSE<< "    Fecha" << setw(18) << "Hora" << setw(24)
                 << "Especialidad" << setw(32) << "Doctor" << setw(30)
                 << "Paciente" << RESET<<endl;
            cout <<GREEN<< " " << setfill('-') << setw(123) << '\n' << setfill(' ')<< RESET;
            buscarCitasPaciente(listaCitas, busPacienteCitas);
            cout <<GREEN<< " " << setfill('*') << setw(123) << '\n' << setfill(' ')<<RESET;
            cout << endl;
            cin.sync();
            break;
          case (3)://En base a Especialidades.
            cout <<GREEN<< " " << setfill('-') << setw(123) << '\n' << setfill(' ')<<RESET;
            cout <<BLACK<< " - Ingrese el nombre de la especialidad cuyas citas "
                    "quiere conocer: "
                 <<RESET<< endl;
            cin.sync();
            cin.ignore();
            getline(cin, busEspecialidadCitas);
            cout << endl;
            cout <<GREEN<< " " << setfill('-') << setw(123) << '\n' << setfill(' ')<<RESET;
            cout <<ROSE<< "    Fecha" << setw(18) << "Hora" << setw(24)
                 << "Especialidad" << setw(32) << "Doctor" << setw(30)
                 << "Paciente" << RESET<<endl;
            cout <<GREEN<< " " << setfill('-') << setw(123) << '\n' << setfill(' ')<< RESET;
            buscarCitasEspecialidad(listaCitas, busEspecialidadCitas);
            cout <<GREEN<< " " << setfill('*') << setw(123) << '\n' << setfill(' ')<<RESET;
            cout << endl;
            cin.sync();
            break;
          case (4)://En base a Fecha.
            cout << " " << setfill('*') << setw(121) << '\n' << setfill(' ');
            cout <<BLACK<< " - Ingrese la fecha que desea buscar: " <<RESET<< endl;
            cin.sync();
            cin.ignore();
            getline(cin, busFechaCitas);
            cout << endl;
            cout <<GREEN<< " " << setfill('-') << setw(123) << '\n' << setfill(' ')<<RESET;
            cout <<ROSE<< "    Fecha" << setw(18) << "Hora" << setw(24)
                 << "Especialidad" << setw(32) << "Doctor" << setw(30)
                 << "Paciente" << RESET<<endl;
            cout <<GREEN<< " " << setfill('-') << setw(123) << '\n' << setfill(' ')<< RESET;
            buscarCitasFecha(listaCitas, busFechaCitas);
            cout <<GREEN<< " " << setfill('*') << setw(123) << '\n' << setfill(' ')<<RESET;
            cout << endl;
            cin.sync();
            break;
          }
          break;
        case (2):
          //Ingresar una cita        
          salida = 3;
          cout << endl;
          cout << GREEN <<" " << setfill('*') << setw(123) << '\n' << setfill(' ')<< RESET;
          cout <<BLACK<< "Escoja el Doctor que desea agendar: " <<RESET<< endl;
          contador_M = contar_Medicos();
          mostrarNombresDoctor(infoMedico, contador_M);
          while (salida != 0) { 
            
            leerCita(citas, infoMedico, pacientes, contador_M, condicion);
            if (condicion == 1) {
              cout <<RED<< "---NO HA SIDO POSIBLE REGISTRAR LA CITA---" <<RESET<< endl;
              eliminarCita(listaCitas, listaCitas.contadorCitas - 1,
                           exitoCitas);
              salida = 0;
            } else {
              insertarCita(listaCitas, citas, exitoCitas);
              validar(citas, listaCitas, condicion);
              if (condicion == 1) {
                cout <<RED<< "---NO HA SIDO POSIBLE REGISTRAR LA CITA---" <<RESET<< endl;
                eliminarCita(listaCitas, listaCitas.contadorCitas - 1,
                             exitoCitas);
                salida = 0;
              } else if (condicion == 0) {
                cout <<GREEN<< "------LA CITA HA SIDO REGISTRADA CORRECTAMENTE-----"
                     <<RESET<< endl;
                salida = 0;
              }
              if (!exitoCitas) {
                cout << "*" << setw(75)
                     <<RED<< "------Lista de citas llena, imposible agendar!------"
                     <<RESET<< setw(48) << "*" << endl;
                salida = 0;
              }
            }
            //}
            break;
          case (3):
            // funcion que modifique una cita
            salida = 2;
            cout <<BLACK<< "Ingrese la posicion de la cita que desea modificar: "<<RESET;
            cin >> posicion;
            eliminarCita(listaCitas, posicion - 1, exitoCitas);
            if (!exitoCitas) {
              cout <<RED<< "*" << setw(75)
                   << "-----Cita no encontrada, por favor revise las citas del "
                      "sistema!------"
                   << setw(48) << "*" <<RESET<< endl;
            } else {
              while (salida != 0) {
                cout <<BLACK<< "Escoja el Doctor que desea agendar: " <<RESET<< endl;
                contador_M = contar_Medicos();
                mostrarNombresDoctor(infoMedico, contador_M);
                leerCita(citas, infoMedico, pacientes, contador_M, condicion);
                insertarCita(listaCitas, citas, exitoCitas);
                validar(citas, listaCitas, condicion);
                if (condicion == 1) {
                  cout <<RED<< "---NO HA SIDO POSIBLE MODIFICAR LA CITA---" <<RESET<< endl;
                  eliminarCita(listaCitas, listaCitas.contadorCitas - 1,
                               exitoCitas);
                  salida = 0;
                }

                else if (condicion == 0) {
                  cout <<GREEN<< "------LA CITA HA SIDO MODIFICADA CORRECTAMENTE-----"
                       <<RESET<< endl;
                  salida = 0;
                }
                if (!exitoCitas) {
                  cout <<RED<< "*" << setw(75)
                       << "------Lista de citas llena, imposible agendar!------"
                       << setw(48) << "*" <<RESET<< endl;
                  salida = 0;
                }
              }
            }

            break;
          case (4):
            // funcion que elimine una cita
            cout <<BLACK<< " - Ingrese la posición de la cita que desea eliminar: "<<RESET;
            cin >> posCitas;
            eliminarCita(listaCitas, posCitas - 1, exitoCitas);
            if (!exitoCitas) {
              cout <<RED<< "*" << setw(75) << "------Elemento inexistente!------"
                   << setw(48) << "*" <<RESET<< endl;
            }
            break;
            
          case (5):
            cout <<GREEN<< " " << setfill('-') << setw(123) << '\n' << setfill(' ')<<RESET;
            cout <<ROSE<< "    Fecha" << setw(18) << "Hora" << setw(24)
                 << "Especialidad" << setw(32) << "Doctor" << setw(30)
                 << "Paciente" << RESET<<endl;
            cout <<GREEN<< " " << setfill('-') << setw(123) << '\n' << setfill(' ')<<RESET;
            ordenar(listaCitas);
            listadoCita(listaCitas);
            cout << GREEN<<" " << setfill('-') << setw(123) << '\n' << setfill(' ')<<RESET;
            cout << endl;
            break;
          }
          guardarArchivoCitas(listaCitas);
        }
      }
      cout << endl;
      main();
      break;
    }
  }

  return 0;
}

int menuPrincipal() {
  int op;
  cout << endl;
  cout <<CYAN<< " " << setfill('*') << setw(123) << '\n' << setfill(' ');
  cout <<CYAN<< "|" << setw(71) <<ROSE<< "*Gestión Citas Médicas*" <<RESET<<setw(52) <<CYAN<<"|\n";
  cout <<CYAN<< " " << setfill('*') << setw(123) << '\n' << setfill(' ');
  cout <<CYAN<< " " << setfill('-') << setw(123) << '\n' << setfill(' ');
  cout <<CYAN<< "|"
       <<CYAN<< BLACK<<"1." << setw(122) << right << "Información Médicos." << RESET<< CYAN<<"|\n"<<RESET;
  cout <<CYAN<< "|"
      << BLACK<<"2." << setw(121) << "Información Pacientes." << RESET<< CYAN<<"|\n"<<RESET;
  cout <<CYAN<< "|"
       << BLACK<<"3." << setw(121) << "Información Citas." << RESET<< CYAN<<"|\n"<<RESET;
  cout <<CYAN<< "|"
       << BLACK<<"0." << setw(120) << "Salir." << RESET<< CYAN<<"|\n"<<RESET;
  cout <<CYAN<< " " << setfill('-') << setw(123) << '\n' << setfill(' ')<<RESET;
  do {
    cout << BLACK<<"Opción: "<<RESET;
    cin >> op;
    if (op == 0) {
      cout << endl;
      cout << "Gracias por utilizar este programa! Vuelva pronto!";
    }
  } while ((op < 0) || (op > 3));
  return op;
}
// menú medicos, pacientes y citas; buscar, ingresar, modificar, eliminar,
// imprimir
int menuMedicos() {
  int op;
  cout << endl;
  cout <<YELLOW<< " " << setfill('*') << setw(123) << '\n' << setfill(' ');
  cout <<YELLOW<< "|" << setw(71) <<ROSE<<"*Información de Médicos*" <<RESET<< setw(51) <<YELLOW<<"|\n";
  cout <<YELLOW<< " " << setfill('*') << setw(123) << '\n' << setfill(' ');
  cout <<YELLOW<< " " << setfill('-') << setw(123) << '\n' << setfill(' ');
  cout <<YELLOW<< "|"
       <<BLACK<< "1." << setw(121) << right << "Buscar un Médico." << RESET<< YELLOW<<"|\n"<<RESET;
  cout <<YELLOW<< "|"
       <<BLACK<< "2." << setw(121) << "Ingresar nuevo Médico." << RESET<< YELLOW<<"|\n"<<RESET;
  cout <<YELLOW<< "|"
       <<BLACK<< "3." << setw(122) << "Modificar Información de un Médico." << RESET<< YELLOW<<"|\n"<<RESET;
  cout <<YELLOW<< "|"
       << BLACK<<"4." << setw(122) << "Eliminar Información de un Médico." << RESET<< YELLOW<<"|\n"<<RESET;
  cout <<YELLOW<< "|"
       <<BLACK<<"5." << setw(121) << "Imprimir listado de Médicos." << RESET<< YELLOW<<"|\n"<<RESET;
  cout <<YELLOW<< "|"
       <<BLACK<<"0." << setw(120) << "Salir." << RESET<< YELLOW<<"|\n"<<RESET;
  cout <<YELLOW<< " " << setfill('-') << setw(123) << '\n' << setfill(' ')<<RESET;
  do {
    cout <<BLACK<< "Opción: ";
    cin >> op;
  } while ((op < 0) || (op > 5));
  return op;
}

int menuPacientes() {
  int op;
  cout << endl;
  cout <<ORANGE<< " " << setfill('*') << setw(123) << '\n' << setfill(' ');
  cout <<ORANGE<< "|" << setw(70) <<ROSE<<"*Información de Pacientes*" <<RESET<< setw(61) <<ORANGE<< "|\n"<<RESET;
  cout <<ORANGE<< " " << setfill('*') << setw(123) << '\n' << setfill(' ');
  cout <<ORANGE<< " " << setfill('-') << setw(123) << '\n' << setfill(' ');
  cout <<ORANGE<< "|"
       <<BLACK<< "1." << setw(120) << right << "Buscar un Paciente."<< RESET<< ORANGE<<"|\n"<<RESET;
  cout <<ORANGE<< "|"
       <<BLACK<< "2." << setw(120) << "Ingresar nuevo Paciente."<< RESET<< ORANGE<<"|\n"<<RESET;
  cout <<ORANGE<< "|"
       <<BLACK<< "3." << setw(121) << "Modificar Información de un Paciente."<< RESET<< ORANGE<<"|\n"<<RESET;
  cout <<ORANGE<< "|"
       <<BLACK<< "4." << setw(121) << "Eliminar Información de un Paciente."<< RESET<< ORANGE<<"|\n"<<RESET;
  cout <<ORANGE<< "|"
       <<BLACK<< "5." << setw(120) << "Imprimir listado de Pacientes."<< RESET<< ORANGE<<"|\n"<<RESET;
  cout <<ORANGE<< "|"
       <<BLACK<< "0." << setw(120) << "Salir."<< RESET<< ORANGE<<"|\n"<<RESET;
  cout <<ORANGE<< " " << setfill('-') << setw(123) << '\n' << setfill(' ');
  do {
    cout <<BLACK<< "Opción: "<<RESET;
    cin >> op;
  } while ((op < 0) || (op > 5));
  return op;
}

int menuCitas() {
  int op;
  cout << endl;
  cout <<GREEN<< " " << setfill('*') << setw(123) << '\n' << setfill(' ')<<RESET;
  cout <<GREEN<< "|" << setw(71) <<ROSE<< "*Información de Citas*" <<RESET<< setw(53) <<GREEN<< "|\n";
  cout <<GREEN<< " " << setfill('*') << setw(123) << '\n' << setfill(' ');
  cout <<GREEN<< " " << setfill('-') << setw(123) << '\n' << setfill(' ');
  cout <<GREEN<< "|"
       <<BLACK<< "1." << setw(120) << right << "Buscar una Cita."<< RESET<< GREEN<<"|\n"<<RESET;
  cout <<GREEN<< "|"
       <<BLACK<< "2." << setw(120) << "Ingresar nueva Cita."<< RESET<< GREEN<<"|\n"<<RESET;
  cout <<GREEN<< "|"
       <<BLACK<< "3." << setw(120) << "Modificar Cita."<< RESET<< GREEN<<"|\n"<<RESET;
  cout <<GREEN<< "|"
       <<BLACK<< "4." << setw(120) << "Eliminar Cita."<< RESET<< GREEN<<"|\n"<<RESET;
  cout <<GREEN<< "|"
       <<BLACK<< "5." << setw(120) << "Imprimir listado de Citas."<< RESET<< GREEN<<"|\n"<<RESET;
  cout <<GREEN<< "|"
       <<BLACK<< "0." << setw(120) << "Salir.|"<< RESET<< GREEN<<"|\n"<<RESET;
  cout <<GREEN<< " " << setfill('-') << setw(123) << '\n' << setfill(' ');
  do {
    cout << "Opción: ";
    cin >> op;
  } while ((op < 0) || (op > 5));
  return op;
}
