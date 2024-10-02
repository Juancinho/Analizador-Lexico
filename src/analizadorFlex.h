#ifndef ANALIZADOR_LEX_H
#define ANALIZADOR_LEX_H
#include "definiciones.h"
void iniciarAnalizador();
void abrirArchivo(char *nombreArchivo);
void siguienteComponenteLexico(tipoelem *actual);
void cerrarArchivo();

#endif //ANALIZADOR_LEX