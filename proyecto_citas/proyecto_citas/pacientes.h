#ifndef pacientes_h
#define pacientes_h

#include <string>
const int maxPacientes = 20;
using namespace std;
typedef struct{
  string NombreCompleto;
  string Cedula;
  string FechaNacimiento;
  string sexo;
  string direccion;
  string NumeroTelefono;
} tPacientes;
typedef struct{
  tPacientes elementosPacientes[maxPacientes];
  int contadorPacientes;
}tListaPacientes;

void guardarArchivoPacientes(const tListaPacientes &listaPacientes);

void cargarArchivoPacientes(tListaPacientes &listaPacientes, bool &okPacientes);

void buscarPacientes(const tListaPacientes listaPacientes, string nPacientes);

void leerPacientes(tPacientes &pacientes);

void insertarPacientes(tListaPacientes &listaPacientes, tPacientes pacientes, bool &okPacientes);

void mostrarPacientes(tPacientes pacientes);

void listadoPacientes(const tListaPacientes listaPacientes);

void eliminarPacientes(tListaPacientes &listaPacientes, int posPacientes, bool &okPacientes);

void modificarPacientes( tListaPacientes &listaPacientes);

#endif