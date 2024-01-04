#ifndef OFUSCADO_INCLUDED
#define OFUSCADO_INCLUDED

#include "VectorChar.h"

size_t quieroUnaLineaDeTextoOfuscadaV1(char* linea);
char* desofuscar(char* linea);
char* recorreDer(char*, char**, int, char**, char**);

#endif // OFUSCADO_INCLUDED
