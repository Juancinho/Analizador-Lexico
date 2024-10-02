#include <stdio.h>
#include <stdlib.h>
#include "definiciones.h"
#include "analizadorFlex.h"

void iniciarAnalizador();

void iniciarAnalizador(){
    tipoelem e;
    e.id=NULL;

    siguienteComponenteLexico(&e);

    while(e.valor != FIN_FICHERO){
              
        //Liberamos la memoria del identificador
        if(e.id != NULL){
            printf("\n<\"%s\", %d>\n",e.id, e.valor);
            free(e.id);
            e.id = NULL;
        }
        
        siguienteComponenteLexico(&e);
    }
   
}