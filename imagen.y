%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%union {
    char* str;
    int entero;
    float real;
}

// TOKENS CON TIPOS
%token <entero> NUM
%token <real> NUMREAL
%token <str> IDENTIFICADOR

// Palabras clave
%token VARIABLES ENTERO REAL FIGURAS IMAGEN FINIMAGEN
%token PONER BORRAR HORIZONTAL VERTICAL PAUSA

// Tipos de figuras y colores
%token CIRCULO RECTANGULO CUADRADO
%token ROJO VERDE AZUL NARANJA

// Símbolos
%token COMA DOSPUNTOS PUNTOYCOMA PAR_IZQ PAR_DER
%token ASIGNACION
%token MENOS POR
%token CADENA

// Prioridad de operaciones (si las usas)
%left '+' '-'
%left '*' '/'

%type <entero> expresion_entera
%type <real> expresion_real

%%

programa:
    seccion_variables seccion_figuras lista_imagenes
;

seccion_variables:
    VARIABLES lista_declaraciones
;

lista_declaraciones:
    declaracion
    | lista_declaraciones declaracion
;

declaracion:
    tipo lista_identificadores
    | IDENTIFICADOR ASIGNACION expresion
;

tipo:
    ENTERO
    | REAL
;

lista_identificadores:
    IDENTIFICADOR
    | lista_identificadores COMA IDENTIFICADOR
;

expresion:
    expresion_entera
    | expresion_real
;

expresion_entera:
    NUM
    | IDENTIFICADOR { $$ = atoi($1); }  // convierte string a entero
;

expresion_real:
    NUMREAL
    | IDENTIFICADOR { $$ = atof($1); }  // convierte string a real
;

seccion_figuras:
    FIGURAS lista_figuras
;

lista_figuras:
    figura
    | lista_figuras figura
;

figura:
    IDENTIFICADOR ASIGNACION PAR_IZQ tipo_figura COMA expresion COMA expresion COMA expresion COMA color PAR_DER
    | IDENTIFICADOR ASIGNACION PAR_IZQ tipo_figura COMA expresion COMA expresion COMA expresion COMA expresion COMA color PAR_DER
;

tipo_figura:
    CIRCULO
    | RECTANGULO
    | CUADRADO
;

color:
    ROJO | VERDE | AZUL | NARANJA
;

lista_imagenes:
    imagen
    | lista_imagenes imagen
;

imagen:
    IMAGEN PAR_IZQ expresion COMA expresion COMA CADENA PAR_DER
    lista_acciones
    FINIMAGEN
;

lista_acciones:
    instruccion
    | lista_acciones instruccion
;

instruccion:
    PONER IDENTIFICADOR
    | BORRAR IDENTIFICADOR
    | HORIZONTAL IDENTIFICADOR expresion
    | VERTICAL IDENTIFICADOR expresion
    | PAUSA expresion
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis: %s\n", s);
}
