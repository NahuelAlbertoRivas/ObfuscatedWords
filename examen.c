#include "examen.h"

char* desofuscar(char* linea){
    char * ini_linea = linea, grupo[] = "abcdghijkoqtuv", *paux, *pcambio, *ini_grupo = grupo, *fin_grupo;
    int pos = 0, dim_regGrupo = strlen_copia(grupo) - 1;
    fin_grupo = grupo + dim_regGrupo; // usaremos ' fin_grupo ', junto a ' ini_grupo ', para recorrer la cadena ' grupo ' mediante un puntero de lectura, pudiendo orientar este último sin que exceda la correspondiente extensión
    while(*ini_linea) {
        if(esLetra1(*ini_linea)) { pos++; } // condicional fundamental para restringir el procesamiento enfocando una palabra a la vez (ya que si detecta cualquier otro caracter como espacios, signos, etc., resetea el índice de posicionamiento que se le enviará a la fn. ' recorreDer ', el cual será la referencia principal para recuperar el caracter correcto)
        else { pos = 0; } // al detectar el fin de una palabra resetea la posición referente del caracter
        paux = strchr(grupo, *ini_linea);  // (1) paux verifica que el actual caracter esté incluido en ' grupo ' (y guarda la dir de aquél en este último)
        if(paux) { // si se encontró el corriente caracter en ' grupo ', entonces procedemos a recuperarlo
            pcambio = recorreDer(grupo, &paux, pos, &ini_grupo, &fin_grupo); // pcambio almacena la dir de la posición original del caracter antes de efectuar su corrimiento acorde a su posición
            *ini_linea = *pcambio; // efectuamos la recuperación del caracter
        }
        ini_linea++; // siguiente caracter del string ' linea '
    }
    return NULL;
}

char* recorreDer(char* cad, char** paux, int cant, char** pini, char** pfin) { // esta fn. se encarga de recuperar la dir. del caracter reemplazado tras haber ofuscado una palabra en particular (el condicional ' if ' de la línea 13 complementará su funcionalidad)
    int i = 0;
    cad = *paux; // retomamos la instancia (dir. de memoria en ' grupo ') desde la que se encontró la coincidencia - (1) -
    while(i < cant) { // cant se corresponde con ' pos ', ya que esta última indica la ubicación del caracter en la palabra, número que determinará cuántas veces se deberá adelantar lugares
        if(cad != (*pfin)) { // se regula que nuestro puntero que recorrerá ' grupo ' no se exceda del último elemento
            cad++; // enotnces adelanta de a un lugar
        }
        else { cad = (*pini); } // en caso de que nos encontremos en la última posición válida, volveremos al inicio (lo cual sigue contando como un adelantamiento más)
        i++;
    }
    return cad; // finalmente retornamos la dir. que corresponde al caracter válido recuperado
}
