%{
#include "imagen.tab.h"
#include <string.h>
#include <stdlib.h>

/* Función auxiliar para copiar texto de forma segura al array de Bison */
void copiar_str(char* destino, const char* origen) {
    strncpy(destino, origen, 99);
    destino[99] = '\0'; // Asegurar fin de cadena
}
%}

%option yylineno

%%

[ \t\r]+                ; /* Ignorar espacios */
\n                      return '\n';

"//".* ; /* Comentarios: Ignorar hasta el enter */

"VARIABLES"             return VARIABLES;
"Entero"                return ENTERO;
"Real"                  return REAL;
"Bool"                  return BOOL;

"FIGURAS"               return FIGURAS;
"IMAGEN"                return IMAGEN;
"FINIMAGEN"             return FINIMAGEN;

"poner"                 return PONER;
"borrar"                return BORRAR;
"horizontal"            return HORIZONTAL;
"vertical"              return VERTICAL;
"pausa"                 return PAUSA;

"si"                    return SI;
"si_no"                 return SI_NO;
"repetir"               return REPE;
"{"                     return LLLAVE;
"}"                     return RLLAVE;

"cuadrado"              return CUADRADO;
"rectangulo"            return RECTANGULO;
"circulo"               return CIRCULO;

"rojo"                  return T_ROJO;
"verde"                 return T_VERDE;
"azul"                  return T_AZUL;
"naranja"               return T_NARANJA;
"marron"                return T_MARRON;
"amarillo"              return T_AMARILLO;
"negro"                 return T_NEGRO;
"gris"                  return T_GRIS;

":="                    return ASIGNACION;
","                     return COMA;
"("                     return PAR_IZQ;
")"                     return PAR_DER;
"<"                     return MENOR;
">"                     return MAYOR;

"+"                     return '+';
"-"                     return '-';
"*"                     return '*';
"/"                     return '/';
"=="                    return IGUAL;
"&&"                    return AND;

"cierto"                return TRUE;
"falso"                 return FALSE;

\"[^\"]*\"              { 
                          /* Copiamos la cadena (incluidas comillas) al array fijo */
                          copiar_str(yylval.str, yytext); 
                          return CADENA; 
                        }

[0-9]+\.[0-9]* { yylval.real = atof(yytext); return NUMREAL; }
\.[0-9]+                { yylval.real = atof(yytext); return NUMREAL; }
[0-9]+                  { yylval.entero = atoi(yytext); return NUM; }

[a-zA-Z_][a-zA-Z0-9_]* { 
                          /* Copiamos el nombre de la variable al array fijo */
                          copiar_str(yylval.str, yytext); 
                          return IDENTIFICADOR; 
                        }

.                       return yytext[0];

%%

int yywrap() { return 1; }