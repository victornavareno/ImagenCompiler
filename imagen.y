%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h> 
#include <stdbool.h> 
#include "tabla_simbolos.h"

extern int yylineno;
int yylex(void);
void yyerror(const char *s);

/* Tabla de Símbolos Global */
extern tipo_tabla TS;

/* Funcion auxiliar para concatenar cadenas */
char* generar_cadena(const char* formato, ...) {
    char buffer[1024];
    va_list args;
    va_start(args, formato);
    vsnprintf(buffer, 1024, formato, args);
    va_end(args);
    return strdup(buffer);
}

/* Constantes para tipo de figuras */
#define F_CUADRADO 0
#define F_RECTANGULO 1
#define F_CIRCULO 2

%}

/* STRUCT PARA EXPRESIONES */
%code requires {
    #include <stdbool.h>
    
    typedef struct {
        char* codigo;  
        bool esReal;   
    } info_expr;
}

%union {
    char* str;
    int entero;
    float real;
    info_expr expr;  
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

/* === TIPOS ACTUALIZADOS === */
%type <expr> expresion
%type <str> expresion_booleana /* ¡IMPORTANTE! Debe ser string para escribir el if */
%type <entero> tipo_figura3 tipo_figura4
%type <str> color

%start programa

%%

/* === ESTRUCTURA PRINCIPAL === */

programa:
    opt_saltos opt_variables seccion_figuras lista_imagenes
;

saltos:
    '\n'
  | saltos '\n'
;

opt_saltos:
    /* vacío */
  | opt_saltos '\n'
;

/* === VARIABLES === */

opt_variables:
    /* vacío */
  | VARIABLES saltos lista_declaraciones
;

lista_declaraciones:
    declaracion
  | lista_declaraciones declaracion
;

declaracion:
    tipo lista_identificadores saltos 
    { 
        printf(";\n"); 
    }
  | tipo IDENTIFICADOR ASIGNACION expresion saltos
    {
        printf(" %s = %s;\n", $2, $4.codigo);
        tipo_datoTS d; strcpy(d.identificador, $2); d.tipo = T_ENTERO; insertar(&TS, d); 
    }
  | IDENTIFICADOR ASIGNACION expresion saltos
    {
        printf("    %s = %s;\n", $1, $3.codigo);
    }
;

tipo:
    ENTERO { printf("    int "); }
  | REAL   { printf("    float "); }
  | BOOL   { printf("    bool "); }
;

lista_identificadores:
    IDENTIFICADOR
    {
        printf("%s", $1);
        tipo_datoTS d; strcpy(d.identificador, $1); d.tipo = T_ENTERO; insertar(&TS, d);
    }
  | lista_identificadores COMA IDENTIFICADOR
    {
        printf(", %s", $3);
        tipo_datoTS d; strcpy(d.identificador, $3); d.tipo = T_ENTERO; insertar(&TS, d);
    }
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
    {
        tipo_datoTS d; strcpy(d.identificador, $1); d.tipo = T_FIGURA;
        d.valor.valor_figura.subtipo = $4;
        strcpy(d.valor.valor_figura.p1, $6.codigo);  
        strcpy(d.valor.valor_figura.p2, $8.codigo);  
        strcpy(d.valor.valor_figura.p3, $10.codigo); 
        strcpy(d.valor.valor_figura.color, $12);     
        insertar(&TS, d);
    }
  | IDENTIFICADOR ASIGNACION MENOR tipo_figura4 COMA expresion COMA expresion COMA expresion COMA expresion COMA color MAYOR saltos
    {
        tipo_datoTS d; strcpy(d.identificador, $1); d.tipo = T_FIGURA;
        d.valor.valor_figura.subtipo = $4;
        strcpy(d.valor.valor_figura.p1, $6.codigo);
        strcpy(d.valor.valor_figura.p2, $8.codigo);
        strcpy(d.valor.valor_figura.p3, $10.codigo); 
        strcpy(d.valor.valor_figura.p4, $12.codigo); 
        strcpy(d.valor.valor_figura.color, $14);
        insertar(&TS, d);
    }
;

tipo_figura3: CUADRADO { $$ = F_CUADRADO; } | CIRCULO { $$ = F_CIRCULO; };
tipo_figura4: RECTANGULO { $$ = F_RECTANGULO; };

color:
    ROJO { $$ = strdup("ROJO"); } | VERDE { $$ = strdup("VERDE"); }
  | AZUL { $$ = strdup("AZUL"); } | NARANJA { $$ = strdup("NARANJA"); }
  | MARRON { $$ = strdup("MARRON"); } | AMARILLO { $$ = strdup("AMARILLO"); }
  | NEGRO { $$ = strdup("NEGRO"); } | GRIS { $$ = strdup("GRIS"); }
;

/* === IMAGENES Y ACCIONES === */

lista_imagenes:
    imagen opt_saltos
  | lista_imagenes imagen opt_saltos
;

imagen:
    IMAGEN PAR_IZQ expresion COMA expresion COMA CADENA PAR_DER 
    {
        printf("\n    // Nueva Ventana: %s\n", $7);
        printf("    nuevaVentanaImagen(%s, %s, %s);\n", $7, $3.codigo, $5.codigo);
    }
    opt_saltos lista_acciones FINIMAGEN
    {
        printf("    pausaImagen(1.5);\n");
    }
;

lista_acciones:
    instruccion opt_saltos
  | lista_acciones instruccion opt_saltos
;

/* REGLA AUXILIAR PARA EVITAR CONFLICTOS R/R EN EL IF */
cabecera_si:
    SI PAR_IZQ expresion_booleana PAR_DER 
    { 
        printf("    if (%s) {\n", $3); 
    }
;

instruccion:
    PONER IDENTIFICADOR
    {
        tipo_datoTS d;
        if (buscar(TS, $2, &d) && d.tipo == T_FIGURA) {
            if (d.valor.valor_figura.subtipo == F_RECTANGULO) {
                printf("    rectanguloImagen(%s, %s, %s, %s, %s);\n", d.valor.valor_figura.p1, d.valor.valor_figura.p2, d.valor.valor_figura.p3, d.valor.valor_figura.p4, d.valor.valor_figura.color);
            } else if (d.valor.valor_figura.subtipo == F_CUADRADO) {
                printf("    rectanguloImagen(%s, %s, %s, %s, %s);\n", d.valor.valor_figura.p1, d.valor.valor_figura.p2, d.valor.valor_figura.p3, d.valor.valor_figura.p3, d.valor.valor_figura.color);
            } else if (d.valor.valor_figura.subtipo == F_CIRCULO) {
                printf("    circuloImagen(%s, %s, %s, %s);\n", d.valor.valor_figura.p1, d.valor.valor_figura.p2, d.valor.valor_figura.p3, d.valor.valor_figura.color);
            }
        }
    }
  | BORRAR IDENTIFICADOR
    {
         tipo_datoTS d;
         if (buscar(TS, $2, &d) && d.tipo == T_FIGURA) {
             if (d.valor.valor_figura.subtipo == F_RECTANGULO) printf("    rectanguloImagen(%s, %s, %s, %s, BLANCO);\n", d.valor.valor_figura.p1, d.valor.valor_figura.p2, d.valor.valor_figura.p3, d.valor.valor_figura.p4);
             else if (d.valor.valor_figura.subtipo == F_CUADRADO) printf("    rectanguloImagen(%s, %s, %s, %s, BLANCO);\n", d.valor.valor_figura.p1, d.valor.valor_figura.p2, d.valor.valor_figura.p3, d.valor.valor_figura.p3);
             else if (d.valor.valor_figura.subtipo == F_CIRCULO) printf("    circuloImagen(%s, %s, %s, BLANCO);\n", d.valor.valor_figura.p1, d.valor.valor_figura.p2, d.valor.valor_figura.p3);
         }
    }
  | HORIZONTAL IDENTIFICADOR expresion
    {
        printf("    // Movimiento Horizontal de %s (Valor: %s)\n", $2, $3.codigo);
    }
  | VERTICAL IDENTIFICADOR expresion
    {
        printf("    // Movimiento Vertical de %s (Valor: %s)\n", $2, $3.codigo);
    }
  | PAUSA expresion
    {
        printf("    pausaImagen(%s);\n", $2.codigo);
    }
  | IDENTIFICADOR ASIGNACION expresion
    {
        printf("    %s = %s;\n", $1, $3.codigo);
    }
    
  /* --- ESTRUCTURAS DE CONTROL CORREGIDAS --- */
  
  /* Usamos cabecera_si para reutilizar la accion de imprimir 'if' */
  | cabecera_si LLLAVE opt_saltos lista_acciones RLLAVE
    { 
        printf("    }\n"); 
    }
  | cabecera_si LLLAVE opt_saltos lista_acciones RLLAVE SI_NO 
    { 
        printf("    } else {\n"); 
    }
    LLLAVE opt_saltos lista_acciones RLLAVE
    { 
        printf("    }\n"); 
    }
    
  | REPE expresion 
    { printf("    for(int _i=0; _i < %s; _i++) {\n", $2.codigo); }
    LLLAVE opt_saltos lista_acciones RLLAVE
    { printf("    }\n"); }
;

/* === EXPRESIONES === */

expresion:
      NUM             { $$.codigo = generar_cadena("%d", $1); $$.esReal = false; }
    | NUMREAL         { $$.codigo = generar_cadena("%.2f", $1); $$.esReal = true; }
    | IDENTIFICADOR   { $$.codigo = strdup($1); $$.esReal = false; }
    | expresion '+' expresion { $$.codigo = generar_cadena("%s + %s", $1.codigo, $3.codigo); $$.esReal = $1.esReal || $3.esReal; }
    | expresion '-' expresion { $$.codigo = generar_cadena("%s - %s", $1.codigo, $3.codigo); $$.esReal = $1.esReal || $3.esReal; }
    | expresion '*' expresion { $$.codigo = generar_cadena("%s * %s", $1.codigo, $3.codigo); $$.esReal = $1.esReal || $3.esReal; }
    | expresion '/' expresion { $$.codigo = generar_cadena("%s / %s", $1.codigo, $3.codigo); $$.esReal = true; }
    | PAR_IZQ expresion PAR_DER { $$.codigo = generar_cadena("(%s)", $2.codigo); $$.esReal = $2.esReal; }
    | '-' expresion %prec UMINUS { $$.codigo = generar_cadena("-(%s)", $2.codigo); $$.esReal = $2.esReal; }
;

/* Expresiones booleanas: Ahora devuelven TEXTO C++ */
expresion_booleana:
      TRUE { $$ = strdup("true"); }
    | FALSE { $$ = strdup("false"); }
    | expresion IGUAL expresion 
      { 
          $$ = generar_cadena("%s == %s", $1.codigo, $3.codigo); 
      }
    | expresion_booleana AND expresion_booleana 
      { 
          $$ = generar_cadena("%s && %s", $1, $3); 
      }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error de sintaxis en línea %d: %s\n", yylineno, s);
}