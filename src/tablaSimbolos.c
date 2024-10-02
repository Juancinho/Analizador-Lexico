#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"
#include "definiciones.h"



abb tablaSimbolos;

void insertarEnTabla(char *id, int valor);
void inicializarTabla();
void limpiarTabla();
void imprimirTabla();
void buscarElemento(tipoelem *e);
void _impresionRecursivaArbol(abb A);

void inicializarTabla(){
    crear(&tablaSimbolos); // Creamos el abb que constituirá nuestra tabla de símbolos

    char *claves[35];
    int valores[35];
    claves[0]="False";
    claves[1]="await";
    claves[2]="else";
    claves[3]="import";
    claves[4]="pass";
    claves[5]="None";
    claves[6]="break";
    claves[7]="except";
    claves[8]="in";
    claves[9]="raise";
    claves[10]="True";
    claves[11]="class";
    claves[12]="finally";
    claves[13]="is";
    claves[14]="return";
    claves[15]="and";
    claves[16]="continue";
    claves[17]="for";
    claves[18]="lambda";
    claves[19]="try";
    claves[20]="as";
    claves[21]="def";
    claves[22]="from";
    claves[23]="nonlocal";
    claves[24]="while";
    claves[25]="assert";
    claves[26]="del";
    claves[27]="global";
    claves[28]="not";
    claves[29]="with";
    claves[30]="async";
    claves[31]="elif";
    claves[32]="if";
    claves[33]="or";
    claves[34]="yield";


    valores[0]=FALSE;
    valores[1]=AWAIT;
    valores[2]=ELSE;
    valores[3]=IMPORT;
    valores[4]=PASS;
    valores[5]=NONE;
    valores[6]=BREAK;
    valores[7]=EXCEPT;
    valores[8]=IN;
    valores[9]=RAISE;
    valores[10]=TRUE;
    valores[11]=CLASS;
    valores[12]=FINALLY;
    valores[13]=IS;
    valores[14]=RETURN;
    valores[15]=AND;
    valores[16]=CONTINUE;
    valores[17]=FOR;
    valores[18]=LAMBDA;
    valores[19]=TRY;
    valores[20]=AS;
    valores[21]=DEF;
    valores[22]=FROM;
    valores[23]=NONLOCAL;
    valores[24]=WHILE;
    valores[25]=ASSERT;
    valores[26]=DEL;
    valores[27]=GLOBAL;
    valores[28]=NOT;
    valores[29]=WITH;
    valores[30]=ASYNC;
    valores[31]=ELIF;
    valores[32]=IF;
    valores[33]=OR;
    valores[34]=YIELD;

    // Insertamos cada clave con su valor correspondiente en la tabla de símbolos.
    for (int i = 0; i < 35; i++) {
        insertarEnTabla(claves[i], valores[i]);
    }
}

    void insertarEnTabla(char* id, int valor){
        tipoelem e;
        int tam = strlen(id) + 1;
        e.id = (char*)malloc(sizeof(char)*tam); 
        strcpy(e.id, id);
        e.valor = valor;
        insertar(&tablaSimbolos, e); //Insertamos el elemento en el árbol binario que es la tabla
    }


    void buscarElemento(tipoelem *e){
        if(es_miembro(tablaSimbolos, *e)){
            tipoelem aux;
            buscar_nodo(tablaSimbolos, e->id, &aux);
            e->valor = aux.valor;
        }else{
            e->valor = ID;
            insertarEnTabla(e->id, e->valor);
        }
    }

    void limpiarTabla(){
        destruir(&tablaSimbolos);
    }

    
void _impresionRecursivaArbol(abb A){
    tipoelem e;
    if(!es_vacio(A)){
        _impresionRecursivaArbol(izq(A));
        leer(A,&e);
        printf("%s -> %d\n",e.id,e.valor);
        _impresionRecursivaArbol(der(A));
    }
}


    void imprimirTabla(){
        printf("-----------INICIO TABLA DE SIMBOLOS -----------\n");
        _impresionRecursivaArbol(tablaSimbolos);
        printf("-----------FIN TABLA DE SIMBOLOS -----------\n");
    }



