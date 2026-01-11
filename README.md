## Proyecto IMAGEN (Fase 1)

Víctor Navareño 


Esta primera fase del proyecto consiste solo en un analizador sintáctico básico que detectará la sintaxis del lenguaje IMAGEN. No detecta comentarios ni estructuras avanzadas, solo palabras básicas de la sintaxis imagen según lo indicado en la fase 1 de la entrega.
Para compilar esta primera entrega, asegúrate de estar en el directorio del proyecto y ejecuta:
make
Esto generará el ejecutable imagen.

Si necesitas limpiar los archivos generados compilados, puedes usar:
make clean

--- 
Para ejecutar el analizador sintáctico sobre un archivo .ima, utiliza:
./imagen ejemplo.ima

---
Archivos incluidos:

- imagen.l → Análisis léxico.

- imagen.y → Análisis sintáctico.

- main.c → Código principal del programa.

- Makefile → Automatiza la compilación.

- ejemplo.ima → Archivo de entrada de prueba.
