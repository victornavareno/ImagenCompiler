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

%type <real> expresion
%type <entero> expresion_booleana

%%

programa:
    saltos opt_variables saltos seccion_figuras saltos lista_imagenes saltos
;

saltos:
    /* vacío */
  | saltos '\n'
;

opt_variables:
    /* vacío */
  | VARIABLES saltos lista_declaraciones
;

lista_declaraciones:
    declaracion saltos
  | lista_declaraciones declaracion saltos
;

declaracion:
    tipo lista_identificadores
  | tipo IDENTIFICADOR ASIGNACION expresion
  | IDENTIFICADOR ASIGNACION expresion
;

tipo:
    ENTERO | REAL | BOOL
;

lista_identificadores:
    IDENTIFICADOR
  | lista_identificadores COMA IDENTIFICADOR
;

seccion_figuras:
    FIGURAS saltos lista_figuras saltos
;

lista_figuras:
    figura
  | lista_figuras saltos figura
;

figura:
    IDENTIFICADOR ASIGNACION MENOR tipo_figura3 COMA expresion COMA expresion COMA expresion COMA color MAYOR
  | IDENTIFICADOR ASIGNACION MENOR tipo_figura4 COMA expresion COMA expresion COMA expresion COMA expresion COMA color MAYOR
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

lista_imagenes:
    imagen
  | lista_imagenes saltos imagen
;

imagen:
    IMAGEN PAR_IZQ expresion COMA expresion COMA CADENA PAR_DER saltos lista_acciones FINIMAGEN
;

lista_acciones:
    instruccion
  | lista_acciones '\n' instruccion
;

instruccion:
      PONER IDENTIFICADOR
    | BORRAR IDENTIFICADOR
    | HORIZONTAL IDENTIFICADOR expresion
    | VERTICAL IDENTIFICADOR expresion
    | PAUSA expresion
    | IDENTIFICADOR ASIGNACION expresion
    | SI PAR_IZQ expresion_booleana PAR_DER LLLAVE lista_acciones RLLAVE
    | SI PAR_IZQ expresion_booleana PAR_DER LLLAVE lista_acciones RLLAVE SI_NO LLLAVE lista_acciones RLLAVE
    | REPE expresion LLLAVE lista_acciones RLLAVE
;

expresion:
      NUM            { $$ = (float)$1; }
    | NUMREAL        { $$ = $1; }
    | IDENTIFICADOR  { $$ = 0; }
    | expresion '+' expresion { $$ = $1 + $3; }
    | expresion '-' expresion { $$ = $1 - $3; }
    | expresion '*' expresion { $$ = $1 * $3; }
    | expresion '/' expresion { $$ = $1 / $3; }
    | PAR_IZQ expresion PAR_DER { $$ = $2; }
;

expresion_booleana:
      TRUE { $$ = 1; }
    | FALSE { $$ = 0; }
    | expresion IGUAL expresion { $$ = ($1 == $3); }
    | expresion_booleana AND expresion_booleana { $$ = $1 && $3; }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis en línea %d: %s\n", yylineno, s);
}
