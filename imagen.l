%{
#include "imagen.tab.h"
#include <string.h>
#include <stdlib.h>
%}

%%

[ \t\r]+                ;
"//".*                  ;
\n                      return '\n';

"VARIABLES"            return VARIABLES;
"Entero"               return ENTERO;
"Real"                 return REAL;
"Bool"                 return BOOL;

"FIGURAS"              return FIGURAS;
"Imagen"               return IMAGEN;
"FINIMAGEN"            return FINIMAGEN;

"poner"                return PONER;
"borrar"               return BORRAR;
"horizontal"           return HORIZONTAL;
"vertical"             return VERTICAL;
"pausa"                return PAUSA;

"cierto"               return TRUE;
"falso"                return FALSE;
"=="                   return IGUAL;
"&&"                   return AND;

"cuadrado"             return CUADRADO;
"rectangulo"           return RECTANGULO;
"circulo"              return CIRCULO;

"rojo"                 return ROJO;
"verde"                return VERDE;
"azul"                 return AZUL;
"naranja"              return NARANJA;
"marron"               return MARRON;
"amarillo"             return AMARILLO;
"negro"                return NEGRO;
"gris"                 return GRIS;

":="                   return ASIGNACION;
","                    return COMA;
"("                    return PAR_IZQ;
")"                    return PAR_DER;

"+"                    return '+';
"-"                    return '-';
"*"                    return '*';
"/"                    return '/';

[0-9]+\.[0-9]+         { yylval.real = atof(yytext); return NUMREAL; }
[0-9]+                 { yylval.entero = atoi(yytext); return NUM; }
\"[^\"]*\"             { yylval.str = strdup(yytext); return CADENA; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return IDENTIFICADOR; }

.                      return yytext[0];

%%

int yywrap() {
    return 1;
}
