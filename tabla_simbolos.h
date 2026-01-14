#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h> 

#define MAX_SIMBOLOS 100

// Tipos de datos soportados
typedef enum {
    T_ENTERO = 0,
    T_REAL = 1,
    T_BOOL = 2,
    T_CADENA = 3,
    T_FIGURA = 4  // figuras
} tipo_dato;

// Tipos de figuras
typedef enum { F_CUADRADO, F_RECTANGULO, F_CIRCULO } tipo_forma;

typedef char tipo_cadena[50];

// Estructura para guardar la info de una figura
typedef struct {
    tipo_forma subtipo;
    tipo_cadena p1, p2, p3, p4; // Parámetros como texto (x, y, ancho...)
    tipo_cadena color;
} info_figura;

// El valor cambia según el tipo 
typedef union {
    int valor_entero;
    float valor_real;
    bool valor_bool;
    tipo_cadena valor_cad;
    info_figura valor_figura; // guardar figuras
} tipo_valor;

// EL DATO DE LA TABLA 
typedef struct {
    tipo_cadena identificador;
    tipo_dato tipo;
    tipo_valor valor;
} tipo_datoTS;

// LA TABLA COMPLETA
typedef struct {
    tipo_datoTS simbolos[MAX_SIMBOLOS];
    int num_elementos;
} tipo_tabla;


// funciones basicas
void iniciar(tipo_tabla *TS);
int insertar(tipo_tabla *TS, tipo_datoTS dato); 
int buscar(tipo_tabla TS, const char *nombre, tipo_datoTS *dato);

#endif