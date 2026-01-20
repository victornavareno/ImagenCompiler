#!/bin/bash

echo "Limpiando..."
rm *.o imagen.tab.c imagen.tab.h lex.yy.c interprete 2>/dev/null

echo "Generando Bison y Flex..."
bison -d imagen.y
flex imagen.l

echo "Compilando Librería del Profesor..."
g++ -c imagen.cpp

echo "Compilando Interprete..."
g++ -c -fpermissive imagen.tab.c lex.yy.c tabla_simbolos.c main.c

echo "Enlazando..."
g++ -o interprete imagen.tab.o lex.yy.o tabla_simbolos.o main.o imagen.o -lallegro -lallegro_main -lallegro_primitives -lallegro_image -lallegro_font -lallegro_ttf

echo "Ejecutando!!!"
echo "-----------------------------------"
./interprete $1