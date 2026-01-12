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
/* Eliminamos saltos redundantes. Usamos opt_saltos para limpiar basura entre secciones */

programa:
    opt_saltos opt_variables opt_saltos seccion_figuras opt_saltos lista_imagenes opt_saltos
;

/* Definición de saltos NO VACÍA para evitar bucles infinitos en Bison */
saltos:
    '\n'
  | saltos '\n'
;

/* Definición auxiliar para saltos que pueden no estar */
opt_saltos:
    /* vacío */
  | saltos
;

/* === VARIABLES === */

opt_variables:
    /* vacío */
  | VARIABLES saltos lista_declaraciones
;

lista_declaraciones:
    declaracion opt_saltos
  | lista_declaraciones declaracion opt_saltos
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

/* === FIGURAS === */

seccion_figuras:
    FIGURAS saltos lista_figuras
;

/* CAMBIO CLAVE: La figura lleva el salto pegado al final, no como separador intermedio */
lista_figuras:
    figura opt_saltos
  | lista_figuras figura opt_saltos
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