// Codigo generado por el traductor IMAGEN
#include "imagen.h"
#include <allegro5/allegro5.h>

using namespace std;

int main() {
    // Iniciar entorno grafico
    iniciarImagen();

    int x, y;
    float  tiempo = 0.50;
    x = 100;
    y = 150;

    // Nueva Ventana: "TEST IF"
    nuevaVentanaImagen("TEST IF", 500, 500);
    rectanguloImagen(x, y, 50, 50, ROJO);
    if (x == 100) {
    // Movimiento Horizontal de Cuad (Valor: 50)
    pausaImagen(1);
    }
    if (x == 200) {
    // Movimiento Vertical de Cuad (Valor: 50)
    }

    // Finalizar entorno grafico
    terminarImagen();
    return 0;
}
