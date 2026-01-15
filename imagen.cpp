/**

 Teoría de lenguajes
 Curso 2024/2025

 Nombre: imagen.cpp
 Descripción: Implementación de la librería gráfica para el lenguaje IMAGEN
 Autor:	Profesorado de la asignatura
 Fecha:	05/04/2025

 */

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro5.h>


#include <stdlib.h>
#include <iostream>

#include <cstring>
#include "imagen.h"

using namespace std;


/*
 * DESCRIPCIÓN: tamaño del lado de la ventana
 */
const int TAM_VENTANA = 1000;
ALLEGRO_DISPLAY     *display;

ALLEGRO_COLOR makecolor2(int color) ;


void iniciarImagen () {
	if (al_init()){

	al_set_new_display_option(ALLEGRO_SINGLE_BUFFER, 1, ALLEGRO_REQUIRE);
	al_set_new_display_flags (ALLEGRO_WINDOWED);

	display = al_create_display(TAM_VENTANA,TAM_VENTANA);
	al_init_primitives_addon();

	// borra la ventana con el color negro
    al_clear_to_color(makecolor2(NEGRO));
    al_set_window_title(display, "IMAGEN");

    // se refresca la pantalla
    al_flip_display();

	}

}

void pausaImagen(float s) {
	al_rest(s);
}

void terminarImagen () {
	al_destroy_display          (display);
}


void nuevaVentanaImagen (string titulo, int alto, int ancho) {
	al_destroy_display (display);
	display = al_create_display(alto,ancho);
	al_clear_to_color(makecolor2(BLANCO));
	al_set_window_title(display, titulo.c_str());
    al_flip_display();
}

void rectanguloImagen (int fila, int columna, float alto, float ancho, int color) {
	al_draw_filled_rectangle(columna, fila, columna+ancho, fila+alto, makecolor2(color));
	al_flip_display();
}


void circuloImagen (int fila, int columna, float radio, int color) {
	al_draw_filled_circle(columna, fila, radio, makecolor2(color));
	al_flip_display();
}


// define el color en función de los valores makecol - allegro library
ALLEGRO_COLOR makecolor2(int color) {

	ALLEGRO_COLOR alColor;

	switch (color) {
	case BLANCO:
		alColor = al_map_rgb (255, 255, 255);
		break;
	case NEGRO:
		alColor = al_map_rgb (   0,   0,   0);
		break;
	case GRIS:
		alColor = al_map_rgb ( 232, 229, 222);
		break;
	case ROJO:
		alColor = al_map_rgb ( 253,  129, 118);
		break;
	case AMARILLO:
		alColor = al_map_rgb ( 255, 255, 166);
		break;
	case AZUL:
		alColor = al_map_rgb (72, 193, 193);
		break;
	case VERDE:
		alColor = al_map_rgb (134,181,153);
		break;
    case MARRON:
		alColor = al_map_rgb (128,64,0);
		break;
    case NARANJA:
		alColor = al_map_rgb (216,75,32);
		break;
	default:
		alColor = al_map_rgb (255, 255, 255);
		break; //color blanco
	}

	return alColor;
}


