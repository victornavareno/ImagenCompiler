%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

#include "imagen.h" 
#include "tabla_simbolos.h"

extern int yylineno;
int yylex(void);
void yyerror(const char *s);

/* TABLA DE SIMBOLOS */
extern tipo_tabla TS;

/* Funcion para mapear el texto "rojo" al código de color de Allegro */
/* Asumimos que imagen.h define constantes o usamos las de Allegro */
int obtener_color(char* nombre_color) {
    // Nota: Estas constantes deben coincidir con las que use imagen.h/allegro
    if (strcmp(nombre_color, "ROJO") == 0) return ROJO;
    if (strcmp(nombre_color, "VERDE") == 0) return VERDE;
    if (strcmp(nombre_color, "AZUL") == 0) return AZUL;
    if (strcmp(nombre_color, "NARANJA") == 0) return NARANJA;
    if (strcmp(nombre_color, "MARRON") == 0) return MARRON;
    if (strcmp(nombre_color, "AMARILLO") == 0) return AMARILLO;
    if (strcmp(nombre_color, "GRIS") == 0) return GRIS;
    return NEGRO; // Por defecto
}
%}

/* DEFINIMOS EL STRUCT DENTRO DEL UNION PARA GESTIONAR TIPOS  */
%code requires {
    typedef struct {
        float valor;   // El numero (sea entero o real, lo guardamos como float)
        int tipo;      // T_ENTERO o T_REAL la bandera
    } info_expr;
}

%union {
    char str[100];     // Para nombres (arrays fijos)
    int entero;        // Para numeros enteros
    float real;        // Para números reales
    info_expr expr;    // PARA EXPRESIONES (Valor + Bandera)
}

/* Tokens */
%token <entero> NUM
%token <real> NUMREAL
%token <str> IDENTIFICADOR CADENA

%token VARIABLES ENTERO REAL BOOL
%token FIGURAS IMAGEN FINIMAGEN
%token PONER BORRAR HORIZONTAL VERTICAL PAUSA
%token CIRCULO RECTANGULO CUADRADO
%token T_ROJO T_VERDE T_AZUL T_NARANJA T_MARRON T_AMARILLO T_NEGRO T_GRIS

%token SI SI_NO REPE LLLAVE RLLAVE
%token TRUE FALSE IGUAL AND OR
%token MENOR MAYOR
%token COMA PAR_IZQ PAR_DER ASIGNACION

%left '+' '-'
%left '*' '/'
%left OR
%left AND
%nonassoc IGUAL
%right UMINUS

/* Tipos */
%type <expr> expresion 
%type <entero> expresion_booleana
%type <entero> tipo_figura3 tipo_figura4
%type <str> color

%start programa

%%

programa:
    opt_saltos opt_variables seccion_figuras lista_imagenes
;

saltos: '\n' | saltos '\n' ;
opt_saltos: /* vacio */ | opt_saltos '\n' ;

/* === VARIABLES === */
/* Guardamos los valores iniciales en la tabla (Memoria) */

opt_variables: /* vacio */ | VARIABLES saltos lista_declaraciones ;
lista_declaraciones: declaracion | lista_declaraciones declaracion ;

declaracion:
    tipo lista_identificadores saltos 
  | tipo IDENTIFICADOR ASIGNACION expresion saltos
    {
        tipo_datoTS d; 
        strcpy(d.identificador, $2);
        
        // Asignamos el tipo segun lo que ha dicho la bandera
        d.tipo = $4.tipo; 
        
        // Guardamos el valor en el hueco correcto del union
        if (d.tipo == T_ENTERO) d.valor.valor_entero = (int)$4.valor;
        else d.valor.valor_real = $4.valor;
        
        insertar(&TS, d);
    }
  | IDENTIFICADOR ASIGNACION expresion saltos
    {
        tipo_valor val;
        if ($3.tipo == T_ENTERO) val.valor_entero = (int)$3.valor;
        else val.valor_real = $3.valor;
        
        actualizar(&TS, $1, val, $3.tipo);
    }
;

tipo: ENTERO | REAL | BOOL ;

lista_identificadores:
    IDENTIFICADOR
    {
        tipo_datoTS d; strcpy(d.identificador, $1); d.tipo = T_ENTERO; d.valor.valor_entero = 0;
        insertar(&TS, d);
    }
  | lista_identificadores COMA IDENTIFICADOR
    {
        tipo_datoTS d; strcpy(d.identificador, $3); d.tipo = T_ENTERO; d.valor.valor_entero = 0;
        insertar(&TS, d);
    }
;

/* === FIGURAS === */
/* Calculamos las posiciones y las guardamos en memoria */

seccion_figuras: FIGURAS saltos lista_figuras ;
lista_figuras: figura | lista_figuras figura ;

figura:
    IDENTIFICADOR ASIGNACION MENOR tipo_figura3 COMA expresion COMA expresion COMA expresion COMA color MAYOR saltos
    {
        tipo_datoTS d; strcpy(d.identificador, $1); d.tipo = T_FIGURA;
        d.valor.valor_figura.subtipo = $4;
        
        // Evaluamos y guardamos los valores numéricos
        d.valor.valor_figura.p1 = $6.valor;  // posF
        d.valor.valor_figura.p2 = $8.valor;  // posC
        d.valor.valor_figura.p3 = $10.valor; // lado/radio
        strcpy(d.valor.valor_figura.color, $12);
        
        insertar(&TS, d);
    }
  | IDENTIFICADOR ASIGNACION MENOR tipo_figura4 COMA expresion COMA expresion COMA expresion COMA expresion COMA color MAYOR saltos
    {
        tipo_datoTS d; strcpy(d.identificador, $1); d.tipo = T_FIGURA;
        d.valor.valor_figura.subtipo = $4; // Rectangulo
        
        d.valor.valor_figura.p1 = $6.valor;
        d.valor.valor_figura.p2 = $8.valor;
        d.valor.valor_figura.p3 = $10.valor; // Alto
        d.valor.valor_figura.p4 = $12.valor; // Ancho
        strcpy(d.valor.valor_figura.color, $14);
        
        insertar(&TS, d);
    }
;

tipo_figura3: CUADRADO { $$ = F_CUADRADO; } | CIRCULO { $$ = F_CIRCULO; };
tipo_figura4: RECTANGULO { $$ = F_RECTANGULO; };

color:
    T_ROJO { strcpy($$, "ROJO"); } | T_VERDE { strcpy($$, "VERDE"); }
  | T_AZUL { strcpy($$, "AZUL"); } | T_NARANJA { strcpy($$, "NARANJA"); }
  | T_MARRON { strcpy($$, "MARRON"); } | T_AMARILLO { strcpy($$, "AMARILLO"); }
  | T_NEGRO { strcpy($$, "NEGRO"); } | T_GRIS { strcpy($$, "GRIS"); }
;

/* === IMAGENES === */
/* abrimos ventanas y pintamos */

lista_imagenes: imagen opt_saltos | lista_imagenes imagen opt_saltos ;

imagen:
    IMAGEN PAR_IZQ expresion COMA expresion COMA CADENA PAR_DER 
    {
        nuevaVentanaImagen($7, (int)$3.valor, (int)$5.valor);
    }
    opt_saltos lista_acciones FINIMAGEN
    {
        pausaImagen(1.5);
    }
;

lista_acciones: instruccion opt_saltos | lista_acciones instruccion opt_saltos ;

cabecera_si: SI PAR_IZQ expresion_booleana PAR_DER ;

instruccion:
    PONER IDENTIFICADOR
    {
        tipo_datoTS d;
        if (buscar(TS, $2, &d) && d.tipo == T_FIGURA) {
            // RECUPERAMOS DATOS DE MEMORIA Y PINTAMOS
            float f = d.valor.valor_figura.p1;
            float c = d.valor.valor_figura.p2;
            float dim1 = d.valor.valor_figura.p3;
            float dim2 = d.valor.valor_figura.p4;
            int col = obtener_color(d.valor.valor_figura.color);
            
            if (d.valor.valor_figura.subtipo == F_RECTANGULO)
                rectanguloImagen(f, c, dim1, dim2, col);
            else if (d.valor.valor_figura.subtipo == F_CUADRADO)
                rectanguloImagen(f, c, dim1, dim1, col);
            else if (d.valor.valor_figura.subtipo == F_CIRCULO)
                circuloImagen(f, c, dim1, col);
        }
    }
  | BORRAR IDENTIFICADOR
    {
         tipo_datoTS d;
         if (buscar(TS, $2, &d)) {
             float f = d.valor.valor_figura.p1;
             float c = d.valor.valor_figura.p2;
             float dim1 = d.valor.valor_figura.p3;
             float dim2 = d.valor.valor_figura.p4;
             
             if (d.valor.valor_figura.subtipo == F_CIRCULO)
                circuloImagen(f, c, dim1, BLANCO);
             else if (d.valor.valor_figura.subtipo == F_RECTANGULO)
                 rectanguloImagen(f, c, dim1, dim2, BLANCO);
             else // Cuadrado
                 rectanguloImagen(f, c, dim1, dim1, BLANCO);
         }
    }
  | HORIZONTAL IDENTIFICADOR expresion
    {
        // actualiza la coordenada X (p2) en memoria
        tipo_datoTS d;
        if (buscar(TS, $2, &d) && d.tipo == T_FIGURA) {
            d.valor.valor_figura.p2 += $3.valor; 
            // guardamos en la tabla de simbolos
            actualizar(&TS, $2, d.valor, T_FIGURA);
        }
    }
  | VERTICAL IDENTIFICADOR expresion
    {
        // Actualizamos la coordenada Y  en memoria
        tipo_datoTS d;
        if (buscar(TS, $2, &d) && d.tipo == T_FIGURA) {
            d.valor.valor_figura.p1 += $3.valor; 
            actualizar(&TS, $2, d.valor, T_FIGURA);
        }
    }
  | PAUSA expresion { pausaImagen($2.valor); }
  | IDENTIFICADOR ASIGNACION expresion 
    { 
        // x := 5
        tipo_valor v; 
        if ($3.tipo == T_ENTERO) v.valor_entero = (int)$3.valor;
        else v.valor_real = $3.valor;
        actualizar(&TS, $1, v, $3.tipo);
    }
    
  /* IGNORAMOS BUCLES E IFs (Reglas vacías) */
  | cabecera_si LLLAVE opt_saltos lista_acciones RLLAVE { /* No hacemos nada */ }
  | cabecera_si LLLAVE opt_saltos lista_acciones RLLAVE SI_NO LLLAVE opt_saltos lista_acciones RLLAVE { /* Nada */ }
  | REPE expresion LLLAVE opt_saltos lista_acciones RLLAVE { /* Nada */ }
;

/* === EXPRESIONES === */
expresion:
      NUM 
      { 
          $$.valor = (float)$1; 
          $$.tipo = T_ENTERO; // Bandera: Es entero
      }
    | NUMREAL 
      { 
          $$.valor = $1; 
          $$.tipo = T_REAL;   // Bandera: Es real
      }
    | IDENTIFICADOR 
      { 
          // Leemos de la memoria
          tipo_datoTS d;
          if (buscar(TS, $1, &d)) {
              if (d.tipo == T_ENTERO) {
                  $$.valor = (float)d.valor.valor_entero;
                  $$.tipo = T_ENTERO;
              } else {
                  $$.valor = d.valor.valor_real;
                  $$.tipo = T_REAL;
              }
          } else {
              $$.valor = 0; $$.tipo = T_ENTERO; // Error handling basico
          }
      }
    | expresion '+' expresion 
      { 
          $$.valor = $1.valor + $3.valor; 
          // Si alguno es Real, el resultado es Real (Promoción)
          if ($1.tipo == T_REAL || $3.tipo == T_REAL) $$.tipo = T_REAL;
          else $$.tipo = T_ENTERO;
      }
    | expresion '-' expresion 
      { 
          $$.valor = $1.valor - $3.valor;
          if ($1.tipo == T_REAL || $3.tipo == T_REAL) $$.tipo = T_REAL;
          else $$.tipo = T_ENTERO;
      }
    | expresion '*' expresion 
      { 
          $$.valor = $1.valor * $3.valor;
          if ($1.tipo == T_REAL || $3.tipo == T_REAL) $$.tipo = T_REAL;
          else $$.tipo = T_ENTERO;
      }
    | expresion '/' expresion 
      { 
          $$.valor = $1.valor / $3.valor;
          $$.tipo = T_REAL; // División siempre real
      }
    | PAR_IZQ expresion PAR_DER { $$ = $2; }
    | '-' expresion %prec UMINUS { $$.valor = -$2.valor; $$.tipo = $2.tipo; }
;

expresion_booleana:
      TRUE { $$ = 1; }
    | FALSE { $$ = 0; }
    | expresion IGUAL expresion { $$ = ($1.valor == $3.valor); }
    | expresion_booleana AND expresion_booleana { $$ = $1 && $3; }
    | expresion_booleana OR expresion_booleana { $$ = $1 || $3; }

;

%%
void yyerror(const char *s) { fprintf(stderr, "Error línea %d: %s\n", yylineno, s); }