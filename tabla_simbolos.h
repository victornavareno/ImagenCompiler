#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#include <stdbool.h>

/* === CONSTANTES DE TIPOS === */
#define T_ENTERO 0
#define T_REAL 1
#define T_BOOL 2
#define T_FIGURA 3

/* === SUBTIPOS DE FIGURA === */
#define F_CUADRADO 0
#define F_RECTANGULO 1
#define F_CIRCULO 2

/* STRUCT INFO_FIGURA */
typedef struct {
    int subtipo;      // F_CUADRADO, etc.
    float p1;         // Fila (Y) calculada
    float p2;         // Columna (X) calculada
    float p3;         // Dimensión 1 (lado/radio/alto)
    float p4;         // Dimensión 2 (ancho, solo rectangulo)
    char color[20];   // Color como texto ("ROJO")
} info_figura;

/* 
   O guardamos un ENTERO REAL O FIGURA
*/
typedef union {
    int valor_entero;       // Para Enteros y Booleanos
    float valor_real;       // Para Reales
    info_figura valor_figura; 
} tipo_valor;

/* 
   Usamos arrays fijos para el nombre (char[100]) 
*/
typedef struct {
    char identificador[100]; 
    int tipo;                // T_ENTERO, T_REAL...
    tipo_valor valor;        // El contenido real de la variable
} tipo_datoTS;

/* 
   TABLA DE SIMBOLOS
*/
typedef struct {
    tipo_datoTS simbolos[100];
    int num_elementos;
} tipo_tabla;

/* Funciones */
void iniciar(tipo_tabla *t);
bool insertar(tipo_tabla *t, tipo_datoTS d);
bool buscar(tipo_tabla t, char *nombre, tipo_datoTS *res);
void actualizar(tipo_tabla *t, char *nombre, tipo_valor nuevo_valor, int nuevo_tipo); // ESTO ES NUEVO AL SER INTERPRETE

#endif