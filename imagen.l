%{
#include "imagen.tab.h"
#include "imagen.tab.h"
%}

%option noyywrap

%%

"figura"           return FIGURA;
"circulo"          return CIRCULO;
"rectangulo"       return RECTANGULO;
"color"            return COLOR;
"posicion"         return POSICION;
"radio"            return RADIO;
"base"             return BASE;
"altura"           return ALTURA;

"rojo"             return ROJO;
"azul"             return AZUL;
"verde"            return VERDE;

[a-zA-Z_][a-zA-Z0-9_]*   { yylval.str = strdup(yytext); return ID; }
[0-9]+                   { yylval.num = atoi(yytext); return NUM; }
","                      return COMA;
"("                      return PAR_IZQ;
")"                      return PAR_DER;

[ \t\r]+                 ;  // Ignora espacios
\n                       { /* puedes contar líneas si quieres */ }

.                        { printf("Caracter inesperado: %s\n", yytext); }

%%
