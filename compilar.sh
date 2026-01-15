#!/bin/bash
./imagen $1 > salida.cpp
g++ salida.cpp imagen.cpp -o resultado -lallegro -lallegro_main -lallegro_primitives -lallegro_image -lallegro_font -lallegro_ttf
./resultado