#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#define MAX 100
typedef char tipo_cadena[50];

typedef union {
    int valor_entero;
    float valor_real;
    int valor_bool;
} tipo_valor;

typedef struct {
    tipo_cadena identificador;
    int tipo; // 0: entero, 1: real, 2: bool
    tipo_valor valor;
} tipo_datoTS;

typedef struct {
    tipo_datoTS tabla[MAX];
    int num_elementos;
} tipo_tabla;

void iniciar(tipo_tabla *TS);
int insertar(tipo_tabla *TS, tipo_datoTS dato);
int buscar(tipo_tabla TS, const char* nombre, tipo_datoTS *dato);

#endif
