#ifndef citas_h
#define citas_h
//Bibliotecas y headers usados.
#include <string>
#include "medicos.h"
#include "pacientes.h"


//Constantes y estructuras usados en el módulo citas.
const int maxCitas = 20;
using namespace std;
typedef struct{
  string doctor;
  string hora;
  string paciente;
  string especialidad;
  string fecha;
} tCitas;
typedef struct{
  tCitas elementosCitas[maxCitas];
  int contadorCitas;
}tListaCitas;

//Prototipos de los procedimientos usados en el módulo citas.
void guardarArchivoCitas(const tListaCitas &listaCitas);

void cargarArchivoCitas(tListaCitas &listaCitas, bool &okCitas);

void buscarCitasDoctor(const tListaCitas listaCitas, string doctorCitas);
void buscarCitasPaciente(const tListaCitas listaCitas, string pacienteCitas);
void buscarCitasEspecialidad(const tListaCitas listaCitas, string especialidadCitas);
void buscarCitasFecha(const tListaCitas listaCitas, string fechaCitas);

void leerCita(tCitas &citas, tMedicos infoMedico, tPacientes paciente, const int contador, int &condicion);

void insertarCita(tListaCitas &listaCitas, tCitas citas, bool &okCitas);

void mostrarCita(tCitas citas);

void listadoCita(const tListaCitas listaCitas);

void eliminarCita(tListaCitas &listaCitas, int posCitas, bool &okCitas);

void validar(tCitas citas, const tListaCitas &listaCitas, int &condicion);

void mostrarNombresDoctor(tMedicos infoMedico, const int contador);

void ordenar (tListaCitas &listaCitas);


#endif