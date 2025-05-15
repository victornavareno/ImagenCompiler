%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabla_simbolos.h"

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
%token TRUE FALSE IGUAL AND
%token COMA PAR_IZQ PAR_DER ASIGNACION

%left '+' '-'
%left '*' '/'

%type <real> expresion

%%

programa:
    saltos opt_variables saltos seccion_figuras saltos lista_imagenes saltos
;

saltos:
    /* vacío */ | saltos '\n'
;

opt_variables:
    /* vacío */ | VARIABLES saltos lista_declaraciones
;

lista_declaraciones:
    declaracion salto
  | lista_declaraciones declaracion salto
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
    FIGURAS saltos lista_figuras
;

lista_figuras:
    figura
  | lista_figuras saltos figura
;

figura:
    IDENTIFICADOR ASIGNACION PAR_IZQ tipo_figura lista_parametros COMA color PAR_DER
;

lista_parametros:
      expresion COMA expresion COMA expresion
    | expresion COMA expresion COMA expresion COMA expresion
;

tipo_figura:
    CIRCULO | RECTANGULO | CUADRADO
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
  | lista_acciones salto instruccion
;

instruccion:
    PONER IDENTIFICADOR
  | BORRAR IDENTIFICADOR
  | HORIZONTAL IDENTIFICADOR expresion
  | VERTICAL IDENTIFICADOR expresion
  | PAUSA expresion
  | IDENTIFICADOR ASIGNACION expresion
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

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis: %s\n", s);
}
