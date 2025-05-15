#include "tabla_simbolos.h"
#include <string.h>
#include <stdio.h>

void iniciar(tipo_tabla *TS) {
    TS->num_elementos = 0;
}

int buscar(tipo_tabla TS, const char* nombre, tipo_datoTS *dato) {
    for (int i = 0; i < TS.num_elementos; ++i) {
        if (strcmp(TS.tabla[i].identificador, nombre) == 0) {
            *dato = TS.tabla[i];
            return 1;
        }
    }
    return 0;
}

int insertar(tipo_tabla *TS, tipo_datoTS dato) {
    tipo_datoTS existente;
    if (buscar(*TS, dato.identificador, &existente)) {
        // ya existe: actualiza valor
        for (int i = 0; i < TS->num_elementos; ++i) {
            if (strcmp(TS->tabla[i].identificador, dato.identificador) == 0) {
                TS->tabla[i].valor = dato.valor;
                return 1;
            }
        }
    } else {
        if (TS->num_elementos >= MAX) return 0;
        TS->tabla[TS->num_elementos++] = dato;
        return 1;
    }
    return 0;
}
