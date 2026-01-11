all: imagen

imagen: imagen.tab.o lex.yy.o main.o tabla_simbolos.o
	$(CC) -o imagen imagen.tab.o lex.yy.o main.o tabla_simbolos.o

imagen.tab.c imagen.tab.h imagen.output: imagen.y
	bison -v -d imagen.y

lex.yy.c: imagen.l imagen.tab.h
	flex imagen.l

main.o: main.c
	gcc -c main.c

tabla_simbolos.o: tabla_simbolos.c tabla_simbolos.h
	gcc -c tabla_simbolos.c

imagen.tab.o: imagen.tab.c
	gcc -c imagen.tab.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

clean:
	rm -f *.o imagen lex.yy.c imagen.tab.c imagen.tab.h imagen.output
