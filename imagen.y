%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla_simbolos.h"

extern int yylineno;
int yylex(void);
void yyerror(const char *s);
%}

%union {
    char* str;
    int entero;
    float real;
}

%token <entero> NUM
%token <real> NUMREAL
%token <str> IDENTIFICADOR
%token <str> CADENA

%token VARIABLES ENTERO REAL BOOL
%token FIGURAS IMAGEN FINIMAGEN
%token PONER BORRAR HORIZONTAL VERTICAL PAUSA
%token CIRCULO RECTANGULO CUADRADO
%token ROJO VERDE AZUL NARANJA MARRON AMARILLO NEGRO GRIS

%token SI SI_NO REPE LLLAVE RLLAVE
%token TRUE FALSE IGUAL AND
%token MENOR MAYOR

%token COMA PAR_IZQ PAR_DER ASIGNACION

%left '+' '-'
%left '*' '/'
%left AND
%nonassoc IGUAL
%right UMINUS

%type <real> expresion
%type <entero> expresion_booleana

%start programa

%%

/* === ESTRUCTURA PRINCIPAL === */
/* usa opt_saltos para saltos entre secciones */

programa:
    opt_saltos opt_variables seccion_figuras lista_imagenes
;

/* definimos saltos NO VACIA para evitar bucles infinitos en Bison */
saltos:
    '\n'
  | saltos '\n'
;

opt_saltos:
  | opt_saltos '\n'
;

/* === VARIABLES === */

opt_variables:
  | VARIABLES saltos lista_declaraciones
;

lista_declaraciones:
    declaracion
  | lista_declaraciones declaracion
;

declaracion:
    tipo lista_identificadores saltos
  | tipo IDENTIFICADOR ASIGNACION expresion saltos      // int x := 3 tabla de simbolos: guardar identificador tipo y valor, 
                                                            hacer 2 tablas de símbolos, una para variables y otra para figuras
  | IDENTIFICADOR ASIGNACION expresion saltos
;

tipo:
    ENTERO | REAL | BOOL
;

lista_identificadores:
    IDENTIFICADOR
  | lista_identificadores COMA IDENTIFICADOR
;

/* === FIGURAS === */

seccion_figuras:
    FIGURAS saltos lista_figuras
;

lista_figuras:
    figura 
  | lista_figuras figura
;

figura:
    IDENTIFICADOR ASIGNACION MENOR tipo_figura3 COMA expresion COMA expresion COMA expresion COMA color MAYOR saltos
  | IDENTIFICADOR ASIGNACION MENOR tipo_figura4 COMA expresion COMA expresion COMA expresion COMA expresion COMA color MAYOR saltos
;

tipo_figura3:
    CUADRADO | CIRCULO
;

tipo_figura4:
    RECTANGULO
;

color:
    ROJO | VERDE | AZUL | NARANJA | MARRON | AMARILLO | NEGRO | GRIS
;

/* === IMAGENES === */

lista_imagenes:
    imagen opt_saltos
  | lista_imagenes imagen opt_saltos
;

imagen:
    /* Usamos opt_saltos antes de las acciones por si hay hueco */
    IMAGEN PAR_IZQ expresion COMA expresion COMA CADENA PAR_DER opt_saltos lista_acciones FINIMAGEN
;

lista_acciones:
    instruccion opt_saltos
  | lista_acciones instruccion opt_saltos
;

instruccion:
    PONER IDENTIFICADOR
  | BORRAR IDENTIFICADOR
  | HORIZONTAL IDENTIFICADOR expresion
  | VERTICAL IDENTIFICADOR expresion
  | PAUSA expresion
  | IDENTIFICADOR ASIGNACION expresion
  | SI PAR_IZQ expresion_booleana PAR_DER LLLAVE opt_saltos lista_acciones RLLAVE
  | SI PAR_IZQ expresion_booleana PAR_DER LLLAVE opt_saltos lista_acciones RLLAVE SI_NO LLLAVE opt_saltos lista_acciones RLLAVE
  | REPE expresion LLLAVE opt_saltos lista_acciones RLLAVE
;

/* === EXPRESIONES === */

expresion:
      NUM             { $$ = (float)$1; }
    | NUMREAL         { $$ = $1; }
    | IDENTIFICADOR   { $$ = 0; }
    | expresion '+' expresion { $$ = $1 + $3; }
    | expresion '-' expresion { $$ = $1 - $3; }
    | expresion '*' expresion { $$ = $1 * $3; }
    | expresion '/' expresion { $$ = $1 / $3; }
    | PAR_IZQ expresion PAR_DER { $$ = $2; }
    | '-' expresion %prec UMINUS { $$ = -$2; }
;

/* solo se permiten identificadores en expresiones aritmeticas * /
expresion_booleana:
      TRUE { $$ = 1; }
    | FALSE { $$ = 0; }
    | expresion IGUAL expresion { $$ = ($1 == $3); }
    | expresion_booleana AND expresion_booleana { $$ = $1 && $3; }  / * añadir expresiones booleanas */
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis en línea %d: %s\n", yylineno, s);
}