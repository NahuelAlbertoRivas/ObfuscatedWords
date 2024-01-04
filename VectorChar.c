#include "VectorChar.h"

int esLetra1(char letra) {
    int r;
    r = (letra >= 'A' && letra <= 'Z') || (letra >= 'a' && letra <= 'z')?1:0;
    return r;
}

size_t strlen_copia(const char* cad) {
    int cant = 0;
    while(*cad) {
        cant++;
        cad++;
    }
    return cant;
}

void strcpy_copia(char* cad_destino, const char* cad_fuente) {
    while(*cad_fuente) {
        *cad_destino = *cad_fuente;
        cad_destino++;
        cad_fuente++;
    }
}

/* int strcmp_copia() { // 0 si son iguales, positivo si cad1 >, negativo ca1 <

} */

char* strchr_copia(const char* cad, int car) {
    int r = 1;
    while(*cad && r) {
        if(car == *cad) {
            r = 0;
        }
        cad++;
    }
    return cad;
}

int proximaPalabra1(const char* cad, char** pini, char** pfin) { // Busca todas las palabras de la cadena hasta que se encuentra con el \0
    char *plect, *pfin_aux = (*pfin) + 1;
    int f = 1, reg = 1, cont = 0;
    if(!(*pfin_aux)) { plect = *pini; } // acá se verifica si anteriormente ya se ejecutó la fn con la cadena en cuestión (ya que en la primer llamada ' *pfin ' apuntará al final ('\0') de la cadena-frase, caso contrario será cualquier otro char), por lo tanto si: 1) es la primera vez que se llama, plect (puntero de lectura) deberá comenzar a recorrer desde el comienzo de la frase, *pini tendrá la dir del inicio de la cadena que debemos asignarle a aquél puntero (plect); 2) en caso de que anteriormente ya se haya reconocido una palabra, entonces plect debe retomar desde la instancia siguiente al último caracter de tal última palabra
    else { plect = (*pfin) + 1; } // j servirá para indicar próximamente a *pini dónde comienza la próxima palabra luego de la primer llamada a la fn.
    while((*plect) && reg) { // reg: en complemento con ' f ', quien delimita el comienzo de una palabra, reg se encargará de determinar el fin de la misma.; el término (*plect) se encargará de definir a nivel frase cuándo es que se termina el string, osea, al detectar un ' \0 '
        if(esLetra1(*plect)) {
            if(f) { *pini = plect; } // guardamos la primer instancia reconocida de la palabra (una vez que ' f ' se desactive, *pini se establecerá en el inicio de la misma)
            plect++;
            cont++;
            f = 0;
        }
        else { // al no ser letra el caracter tenemos dos contextos: o bien puede ser que efectivamente haya terminado la extensión de la palabra (ya que se presenta un espacio, coma, signo, etc.) [línea 44], o bien que todavía no se haya detectado el incio de una palabra, por lo tanto deberíamos seguir recorriendo [línea 45]
            if(f == 0) { reg = 0; *pfin = plect - 1; } // entonces, como ' f ' nos indica que ya se inició una palabra, y la línea 38 deriva que el actual caracter no es letra, podemos concluir en que finalizó la extensión de la palabra; ya que el actual caracter no es letra, corresponde ajustar el puntero pfin a la instancia anterior de plect
            else { plect++; } // caso contrario, el actual caracter no es letra pero de igual manera no se inició ninguna secuencia de palabra, por lo tanto seguimos recorriendo
        }
    }
    if(!(*plect)) {*pfin = plect - 1;} // esta línea ajusta el *pfin de la última palabra de la frase, ya que si por ej. aquella no es precedida por otro caracter no considerado letra (como lo puede ser un punto, espacio, signo, etc.), debido a la condición del while automáticamente finaliza el proceso, no pasando por la línea 47 que delimita dicho puntero en cuestión
    return cont;
}

/* int proximaPalabra1(const char* cad, char** pini) { // Busca todas las palabras de la cadena hasta que se encuentra con el \0
    char *start, *end, palabra[30] = "", *ppal = palabra;
    int dim = strlen_copia(cad), i = 0, f = 1, reg = 1, cont = 0;
    start = cad;
    end = cad + (dim-1);
    while((**pini) && (i < dim) && reg) { //
        if(esLetra1(**pini)) {
            *ppal = **pini;
            ppal++; //
            (*pini)++;
            cont++;
            f = 0; // f: se encarga de informar que ya se consideró el primer caracter de la palabra, por lo tanto al detectar en una próxima instancia cualquier otro que no sea considerado ' letra ' (como espacios, signos de puntuación, etc.) servirá como complemento junto a ' reg ' para delimitar el reconocimiento de la palabra
        }
        else {
            if(f == 0) {reg = 0;}
            else { (*pini)++; }
        }
        i++;
    }
    return cont;
} */
