all: imagen

imagen: imagen.tab.o lex.yy.o main.o
	$(CC) -o imagen imagen.tab.o lex.yy.o main.o

imagen.tab.c imagen.tab.h: imagen.y
	bison -d imagen.y

lex.yy.c: imagen.l imagen.tab.h
	flex imagen.l

main.o: main.c
	gcc -c main.c

imagen.tab.o: imagen.tab.c
	gcc -c imagen.tab.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

clean:
	rm -f *.o imagen lex.yy.c imagen.tab.c imagen.tab.h
