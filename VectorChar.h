#ifndef VECTORCHAR_H_INCLUDED
#define VECTORCHAR_H_INCLUDED

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAXLINE 1024

int esLetra1(char);
size_t strlen_copia(const char*);
void strcpy_copia(char *, const char*);
char * strchr_copia(const char*, int);
int proximaPalabra1(const char*, char**, char** pfin);

#endif // VECTORCHAR_H_INCLUDED
