#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tablaSimbolos.h"
#include "analizadorSintactico.h"
#include "errores.h"
#include "analizadorFlex.h"

int main(int argc, char *argv[]){
    
    // Comprobar que se ha pasado al menos un argumento (el nombre del archivo)
    if(argc < 2) {
        error(4);
    }
    abrirArchivo(argv[1]);

    // Inicializar tabla de símbolos y mostrarla por pantalla
    inicializarTabla();
    imprimirTabla();
    //Iniciar analizador sintáctico
    iniciarAnalizador(); 

    // Volver a imprimir la tabla de símbolos
    imprimirTabla();
    //Limpiar la tabla de símbolos
    limpiarTabla();
    cerrarArchivo();

    return 0;
}
