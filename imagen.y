%{
#include <stdio.h>
#include <stdlib.h>
#include "imagen.tab.h"
int yylex(void);
void yyerror(const char *s);


%}

%union {
    char* str;
    int num;
 
}

%token <str> ID
%token <num> NUM

%token FIGURA CIRCULO RECTANGULO COLOR POSICION RADIO BASE ALTURA
%token ROJO AZUL VERDE
%token COMA PAR_IZQ PAR_DER

%%

programa:
    lista_figuras
    ;

lista_figuras:
    figura
    | lista_figuras figura
    ;

figura:
    FIGURA ID tipo COLOR color POSICION PAR_IZQ NUM COMA NUM PAR_DER atributos
    ;

tipo:
    CIRCULO
    | RECTANGULO
    ;

color:
    ROJO | AZUL | VERDE
    ;

atributos:
    RADIO NUM
    | BASE NUM ALTURA NUM
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis: %s\n", s);
}