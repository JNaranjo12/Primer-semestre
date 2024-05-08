#include <iostream>
using namespace std;
#ifndef medicos_h
#define medicos_h
const int TAM = 30;

typedef struct{
  string nombre;
  string cedula;
  string especialidad;
} tMedicos;

typedef struct{
  tMedicos medico[TAM];
  int cont_lista;
} tCantMedicos;

//Procedimientos y funciones que ayudan al programa pero interactuan directamente con el usuario
int contar_Medicos();
void cargar_Archivo_M(tCantMedicos &lista_Medicos, const int contador);
void guardar_en_archivo_M(const tCantMedicos lista_Medicos);

//Procedimientos que interactuan con el usuario
void cargar_Medico(const tMedicos infoMedico, bool &archivo_lleno);
void ingresar_Medico(tMedicos &infoMedico);
void buscar_Medico(tMedicos infoMedico, const int contador);
void modificar_Medico(tCantMedicos &lista_Medicos);
void eliminar_Medico(tCantMedicos &lista_Medicos);
void mostrar_Medicos(tMedicos infoMedico, const int contador);

#endif