#include <stdio.h>
#include "tabla_simbolos.h"
#include "imagen.h" /* Asumiendo que imagen.h incluye allegro.h */

extern int yyparse();
extern FILE* yyin;

tipo_tabla TS;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Uso: ./imagen archivo.ima\n");
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Error al abrir archivo");
        return 1;
    }

    // 1. Iniciar Tabla de Símbolos
    iniciar(&TS);

    // 2. Iniciar Entorno Gráfico (Allegro)
    // Esto abrirá la ventana principal o preparará el sistema
    iniciarImagen();

    // 3. Ejecutar Intérprete (Aquí se abrirán las ventanas y dibujarán)
    yyparse();

    // 4. Cerrar
    terminarImagen();
    
    fclose(yyin);
    return 0;
}