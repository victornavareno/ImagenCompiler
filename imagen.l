%option yylineno
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
"IMAGEN"               return IMAGEN;
"FINIMAGEN"            return FINIMAGEN;

"poner"                return PONER;
"borrar"               return BORRAR;
"horizontal"           return HORIZONTAL;
"vertical"             return VERTICAL;
"pausa"                return PAUSA;

"si"                   return SI;
"si_no"                return SI_NO;
"repetir"              return REPE;
"{"                    return LLLAVE;
"}"                    return RLLAVE;

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
"<"                    return MENOR;
">"                    return MAYOR;

"+"                    return '+';
"-"                    return '-';
"*"                    return '*';
"/"                    return '/';
"=="                   return IGUAL;
"&&"                   return AND;

"cierto"               return TRUE;
"falso"                return FALSE;

\"[^\"]*\"             { yylval.str = strdup(yytext); return CADENA; }
[0-9]+\.[0-9]*         { yylval.real = atof(yytext); return NUMREAL; }  /* por ejemplo: 3.3 o 4.*/
\.[0-9]+                { yylval.real = atof(yytext); return NUMREAL; } /* por ejemplo: .3 */
[0-9]+                 { yylval.entero = atoi(yytext); return NUM; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return IDENTIFICADOR; }

.                      return yytext[0];

%%

int yywrap() {
    return 1;
}
