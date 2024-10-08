# README

Este proyecto es un analizador léxico diseñado para procesar un subconjunto del lenguaje Python mediante la herramienta Flex.

## Características

- Procesamiento de entrada con sistema de doble buffer.
- Análisis léxico para identificar componentes léxicos (tokens) como identificadores, palabras clave, números, strings y comentarios.
- Tabla de símbolos implementada con un árbol binario de búsqueda para almacenar y buscar palabras clave e identificadores.
- Reporte de errores básico para entradas no reconocidas o problemas de archivo.
- Los strings multilínea son ignorados tratándose como comentarios.

## Requisitos Previos

Para compilar y ejecutar este proyecto se requiere:

- GCC (GNU Compiler Collection) o cualquier compilador de C compatible.
- Tener instalado Flex (en este caso se usó la versión 2.6.4)
- Sistema operativo Unix/Linux (en mi caso he utilizado la distribución Pop_OS! con el kernel 6.1.11).

## Compilación y Ejecución

Para compilar el proyecto, navegue hasta el directorio src del proyecto y ejecute:

```bash
./compilar.sh
```

Para ejecutar el programa y analizar un archivo:

```bash
./analizador <ruta_al_archivo>
```

Por ejemplo, usando el fichero de ejemplo que acompaña a la práctica y que se incluye en el directorio donde se encuentran los códigos fuente:

```bash
./analizador wilcoxon.py
```
