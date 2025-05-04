#include <stdio.h>

extern int yyparse();
extern FILE* yyin;

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

    yyparse();
    fclose(yyin);
    return 0;
}
