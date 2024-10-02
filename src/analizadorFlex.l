%{
#include "definiciones.h"
#include "tablaSimbolos.h"
#include "errores.h"
tipoelem elementoActual; // Variable global para almacenar el token actual
%}

/*OPCIONES*/
/*Solo lee un fichero de entrada*/
%option noyywrap 
%option nounput
%option noinput

/*ESPACIOS*/
ESPACIO       [ \t\n\r]
INDENTACION   {ESPACIO}+

LETRA     [a-zA-Z]
/*NÚMEROS ENTEROS*/
DIGIT        [0-9]
NONZERODIGIT [1-9]
BINDIGIT     [01]
OCTDIGIT     [0-7]
HEXDIGIT     [0-9a-fA-F]
BININTEGER   0(b|B)(\_?{BINDIGIT})+
HEXINTEGER   0(x|X)(\_?{HEXDIGIT})+
OCTINTEGER   0(o|O)(\_?{OCTDIGIT})+
DECINTEGER   {DIGIT}(\_?{DIGIT})*
INTEGER      ({BININTEGER}|{HEXINTEGER}|{OCTINTEGER}|{DECINTEGER})

/*NÚMEROS FLOTANTES*/   
DIGITPART     {DIGIT}(\_?{DIGIT})*
FRACTION      \.{DIGITPART}*
EXPONENT      (e|E)[+-]?{DIGITPART}
POINTFLOAT    {DIGITPART}?{FRACTION}
EXPONENTFLOAT ({POINTFLOAT}{EXPONENT}|{DIGITPART}{EXPONENT})
FLOAT         ({POINTFLOAT}|{EXPONENTFLOAT})


/*OPERADORES Y DELIMITADORES*/
OPERADOR    (\+|\-|\*|\/|\%|\@|\<|\>|\&|\||\^|\~|\:|\<|\>|\(|\)|\[|\]|\{|\}|\,|\.|\;|\=)


MAYOR_IGUAL (\>\=)
MENOR_IGUAL (\<\=)
IGUAL_IGUAL (\=\=)
POTENCIA    (\*\*)
POR_IGUAL   (\*\=)

/*COMENTARIOS*/
COMENTARIO  \#[^\n]*

/*IDENTIFICADORES Y PALABRAS RESERVADAS*/
ID ({LETRA}|\_)({LETRA}|{DIGIT}|\_)*


/*STRINGS*/
STRINGPREFIX  [rRuUfF]?([rRfF][rRfF])?
SHORTSTRING   (\'[^\n\'\\]*\')|(\"[^\n\"\\]*\") 


STRING        ({STRINGPREFIX})?(({SHORTSTRING}))
COMILLAS_SIMPLES \'\'\'
COMILLAS_DOBLES \"\"\"
%x STR_SIMPLE
%x STR_DOBLE


%%
{INDENTACION}   {/*Ignorar los espacios y saltos de línea*/}



{INTEGER}       { elementoActual.valor = INT; elementoActual.id = strdup(yytext);return INT;}
{OPERADOR}      { elementoActual.valor = (int) *yytext; elementoActual.id = strdup(yytext); return OPERADOR;}
{FLOAT}         { elementoActual.valor = FLOAT; elementoActual.id = strdup(yytext);return FLOAT;}
{STRING}        { elementoActual.valor = STRING; elementoActual.id = strdup(yytext); return STRING;}
{MAYOR_IGUAL}   { elementoActual.valor = MAYOR_IGUAL; elementoActual.id = strdup(yytext);return MAYOR_IGUAL;}
{MENOR_IGUAL}   { elementoActual.valor = MENOR_IGUAL; elementoActual.id = strdup(yytext);return MENOR_IGUAL;}
{IGUAL_IGUAL}   { elementoActual.valor = IGUAL_IGUAL; elementoActual.id = strdup(yytext);return IGUAL_IGUAL;}
{POTENCIA}      { elementoActual.valor = POTENCIA; elementoActual.id = strdup(yytext);return POTENCIA;}
{POR_IGUAL}     { elementoActual.valor = POR_IGUAL; elementoActual.id = strdup(yytext);return POR_IGUAL;}
{COMENTARIO}    { /* Ignorar comentarios */ }
{ID}            { elementoActual.valor = ID; elementoActual.id = strdup(yytext);buscarElemento(&elementoActual); return ID;}

{COMILLAS_DOBLES}     { BEGIN(STR_DOBLE);}
<STR_DOBLE>{COMILLAS_DOBLES} { BEGIN(INITIAL); }
<STR_DOBLE>.|\n    { /*Ignoramos los strings multilínea tratándolos como comentarios*/ }

{COMILLAS_SIMPLES}     { BEGIN(STR_SIMPLE);}
<STR_SIMPLE>{COMILLAS_SIMPLES} { BEGIN(INITIAL); }
<STR_SIMPLE>.|\n    { /*Ignoramos los strings multilínea tratándolos como comentarios*/ }
.               {elementoActual.valor= ERROR_LEXICO; elementoActual.id=strdup(yytext);error(1); return -2;}
<<EOF>>      {elementoActual.valor = FIN_FICHERO; elementoActual.id = NULL;yyterminate();}
%%


void abrirArchivo(char *nombreArchivo){
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r");
    if(archivo == NULL){
        error(2); //No se encuentra el archivo con dicho nombre
    }
    yyin = archivo;
}

void siguienteComponenteLexico(tipoelem *e){
    yylex();  // Actualizamos elementoActual
    *e = elementoActual;  // Copia la información a la variable pasada por el analizador sintáctico
}


void cerrarArchivo(){
    if (elementoActual.id != NULL) { //liberamos la variable global elementoActual
        free(elementoActual.id);
        elementoActual.id = NULL; 
    }
    fclose(yyin);
    yylex_destroy();
}