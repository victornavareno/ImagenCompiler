%{
#include "imagen.tab.h"
#include <string.h>
#include <stdlib.h>
%}

%%

[ \t\r\n]+                ;

"Variables"               return VARIABLES;
"entero"                  return ENTERO;
"real"                    return REAL;
"Figuras"                 return FIGURAS;
"Imagen"                  return IMAGEN;
"FinImagen"               return FINIMAGEN;
"Poner"                   return PONER;
"Borrar"                  return BORRAR;
"Horizontal"              return HORIZONTAL;
"Vertical"                return VERTICAL;
"Pausa"                   return PAUSA;

"circulo"                 return CIRCULO;
"rectangulo"              return RECTANGULO;
"cuadrado"                return CUADRADO;

"rojo"                    return ROJO;
"verde"                   return VERDE;
"azul"                    return AZUL;
"naranja"                 return NARANJA;

":"                       return DOSPUNTOS;
";"                       return PUNTOYCOMA;
","                       return COMA;
"("                       return PAR_IZQ;
")"                       return PAR_DER;
"="                       return ASIGNACION;
"-"                       return MENOS;
"*"                       return POR;

[0-9]+\.[0-9]+            { yylval.real = atof(yytext); return NUMREAL; }
[0-9]+                    { yylval.entero = atoi(yytext); return NUM; }
\"[^\"]*\"                { yylval.str = strdup(yytext); return CADENA; }
[a-zA-Z_][a-zA-Z0-9_]*    { yylval.str = strdup(yytext); return IDENTIFICADOR; }

.                         { printf("Caracter inesperado: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}
