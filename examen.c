#include "examen.h"

char* desofuscar(char* linea){
    char * ini_linea = linea, grupo[] = "abcdghijkoqtuv", *paux, *pcambio, *ini_grupo = grupo, *fin_grupo;
    int pos = 0, dim_regGrupo = strlen_copia(grupo) - 1;
    fin_grupo = grupo + dim_regGrupo; // usaremos ' fin_grupo ', junto a ' ini_grupo ', para recorrer la cadena ' grupo ' mediante un puntero de lectura, pudiendo orientar este �ltimo sin que exceda la correspondiente extensi�n
    while(*ini_linea) {
        if(esLetra1(*ini_linea)) { pos++; } // condicional fundamental para restringir el procesamiento enfocando una palabra a la vez (ya que si detecta cualquier otro caracter como espacios, signos, etc., resetea el �ndice de posicionamiento que se le enviar� a la fn. ' recorreDer ', el cual ser� la referencia principal para recuperar el caracter correcto)
        else { pos = 0; } // al detectar el fin de una palabra resetea la posici�n referente del caracter
        paux = strchr(grupo, *ini_linea);  // (1) paux verifica que el actual caracter est� incluido en ' grupo ' (y guarda la dir de aqu�l en este �ltimo)
        if(paux) { // si se encontr� el corriente caracter en ' grupo ', entonces procedemos a recuperarlo
            pcambio = recorreDer(grupo, &paux, pos, &ini_grupo, &fin_grupo); // pcambio almacena la dir de la posici�n original del caracter antes de efectuar su corrimiento acorde a su posici�n
            *ini_linea = *pcambio; // efectuamos la recuperaci�n del caracter
        }
        ini_linea++; // siguiente caracter del string ' linea '
    }
    return NULL;
}

char* recorreDer(char* cad, char** paux, int cant, char** pini, char** pfin) { // esta fn. se encarga de recuperar la dir. del caracter reemplazado tras haber ofuscado una palabra en particular (el condicional ' if ' de la l�nea 13 complementar� su funcionalidad)
    int i = 0;
    cad = *paux; // retomamos la instancia (dir. de memoria en ' grupo ') desde la que se encontr� la coincidencia - (1) -
    while(i < cant) { // cant se corresponde con ' pos ', ya que esta �ltima indica la ubicaci�n del caracter en la palabra, n�mero que determinar� cu�ntas veces se deber� adelantar lugares
        if(cad != (*pfin)) { // se regula que nuestro puntero que recorrer� ' grupo ' no se exceda del �ltimo elemento
            cad++; // enotnces adelanta de a un lugar
        }
        else { cad = (*pini); } // en caso de que nos encontremos en la �ltima posici�n v�lida, volveremos al inicio (lo cual sigue contando como un adelantamiento m�s)
        i++;
    }
    return cad; // finalmente retornamos la dir. que corresponde al caracter v�lido recuperado
}
