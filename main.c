#include <stdio.h>
#include "tabla_simbolos.h"

extern int yyparse();
extern FILE* yyin;

tipo_tabla TS;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Uso: %s archivo.ima\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Error abriendo el archivo");
        return 1;
    }

    iniciar(&TS);
    yyparse();
    fclose(yyin);
    return 0;
}
