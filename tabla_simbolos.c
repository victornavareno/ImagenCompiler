#include "tabla_simbolos.h"
#include <string.h>
#include <stdio.h>

/*
 * Inicializa la tabla de simbolos poniendo el contador de elementos a 0
 */
void iniciar(tipo_tabla *TS) {
    TS->num_elementos = 0;
}

/*
 * Busca un identificador en la tabla
 * - Si lo encuentra: devuelve 1 (true) y copia los datos en *dato
 * - Si no lo encuentra: devuelve 0 
 */
int buscar(tipo_tabla TS, const char *nombre, tipo_datoTS *dato) {
    for (int i = 0; i < TS.num_elementos; i++) {
        if (strcmp(TS.simbolos[i].identificador, nombre) == 0) {
            if (dato != NULL) {
                *dato = TS.simbolos[i]; // Copiamos toda la estructura
            }
            return 1;
        }
    }
    return 0; // No encontrado
}

/*
 * Inserta un nuevo simbolo o actualiza uno existente
 * - Si ya existe: actualiza su tipo y valor
 * - Si no existe: lo añade al final si hay hueco
 * Devuelve 1 si ha ido bien, 0 si hay error (tabla llena)
 */
int insertar(tipo_tabla *TS, tipo_datoTS dato) {
    // Primero comprobamos si ya existe para actualizarlo
    for (int i = 0; i < TS->num_elementos; i++) {
        if (strcmp(TS->simbolos[i].identificador, dato.identificador) == 0) {
            // El identificador YA EXISTE, actualizamos valor y tipo
            TS->simbolos[i].tipo = dato.tipo;
            TS->simbolos[i].valor = dato.valor;
            return 1; // Actualización correcta
        }
    }

    // Si no existe, comprobamos si cabe en la tabla
    if (TS->num_elementos < MAX_SIMBOLOS) {
        // Añadimos el nuevo dato en la siguiente posición libre
        TS->simbolos[TS->num_elementos] = dato;
        TS->num_elementos++;
        return 1; // inserción correcta
    } else {
        printf("Error: Tabla de simbolos llena (Max %d).\n", MAX_SIMBOLOS);
        return 0;
    }
}