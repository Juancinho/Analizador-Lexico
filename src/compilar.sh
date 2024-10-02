#!/bin/bash


flex -o analizadorFlex.c analizadorFlex.l

# Verifica si flex se ejecutó exitosamente
if [ $? -eq 0 ]; then
    echo "Flex ejecutado con éxito, ahora ejecutando make..."
    # Ejecuta make para compilar el proyecto
    make
else
    echo "Flex falló, abortando..."
fi
