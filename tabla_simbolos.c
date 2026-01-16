#include <stdio.h>
#include <string.h>
#include "tabla_simbolos.h"

void iniciar(tipo_tabla *t) {
    t->num_elementos = 0;
}

bool buscar(tipo_tabla t, char *nombre, tipo_datoTS *res) {
    for (int i = 0; i < t.num_elementos; i++) {
        if (strcmp(t.simbolos[i].identificador, nombre) == 0) {
            *res = t.simbolos[i]; // Copiamos el dato encontrado
            return true;
        }
    }
    return false;
}

bool insertar(tipo_tabla *t, tipo_datoTS d) {
    // Primero miramos si ya existe para no duplicar
    for (int i = 0; i < t->num_elementos; i++) {
        if (strcmp(t->simbolos[i].identificador, d.identificador) == 0) {
            // Ya existe: actualizamos
            t->simbolos[i] = d;
            return true;
        }
    }
    
    // Si no existe y hay sitio, insertamos
    if (t->num_elementos < 100) {
        t->simbolos[t->num_elementos] = d;
        t->num_elementos++;
        return true;
    }
    
    printf("ERROR: Tabla de simbolos llena\n");
    return false;
}

// Función auxiliar para cambiar solo el valor de una variable
void actualizar(tipo_tabla *t, char *nombre, tipo_valor nuevo_valor, int nuevo_tipo) {
    for (int i = 0; i < t->num_elementos; i++) {
        if (strcmp(t->simbolos[i].identificador, nombre) == 0) {
            t->simbolos[i].valor = nuevo_valor;
            t->simbolos[i].tipo = nuevo_tipo;
            return;
        }
    }
    printf("ERROR EN TIEMPO DE EJECUCION: Variable '%s' no definida antes de asignar.\n", nombre);
}