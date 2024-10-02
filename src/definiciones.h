#ifndef DEFINICIONES_H
#define DEFINICIONES_H

#define FALSE 300
#define AWAIT 301
#define ELSE 302
#define IMPORT 303
#define PASS 304
#define NONE 305
#define BREAK 306
#define EXCEPT 307
#define IN 308
#define RAISE 309
#define TRUE 310
#define CLASS 311
#define FINALLY 312
#define IS 313
#define RETURN 314
#define AND 315
#define CONTINUE 316
#define FOR 317
#define LAMBDA 318
#define TRY 319
#define AS 320
#define DEF 321
#define FROM 322
#define NONLOCAL 323
#define WHILE 324
#define ASSERT 325
#define DEL 326
#define GLOBAL 327
#define NOT 328
#define WITH 329
#define ASYNC 330
#define ELIF 331
#define IF 332
#define OR 333
#define YIELD 334
#define INT 335
#define FLOAT 336
#define STRING 337
#define MAYOR_IGUAL 338
#define MENOR_IGUAL 339
#define MAS_IGUAL 342
#define IGUAL_IGUAL 343
#define POTENCIA 344
#define POR_IGUAL 345
#define OPERADOR 346
#define ERROR_LEXICO 347


#define ID 360
#define FIN_FICHERO 400

// TIPOELEM (lexema, valor del componente lexico)
typedef struct  {
    char *id;
    int valor;
}tipoelem;

#endif // DEFINICIONES_H