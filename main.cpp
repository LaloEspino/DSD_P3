//
//  main.cpp
//  
//
//  Created by Lalo Espino on 08/04/18.
//
//  Para compilar el archivo escriba el siguiente comando en terminal:
//  gcc main.cpp gfx.c -o main -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lm
//
//  Para ejecutar el programa escriba lo siguiente en terminal: (n es el número de barras que van a aparecer)
//  ./main n
//
//  Cuando la ventana de XQuartz esté abierta presione la tecla 'q' para salir
//

#include "gfx.h"
#include <iostream>

using namespace std;

int main (int argc, char* argv[]) {
    const int GFX_WIDTH = 500;
    const int GFX_HEIGHT = 500;
    const char GFX_TITLE[] = "Proyecto 3 DSD";
    
    const int barras = atoi(argv[1]);
    printf("Barras: %d\n", barras);
    
    char exit;
    
    gfx_open(GFX_WIDTH, GFX_HEIGHT, GFX_TITLE);
    gfx_color(0,200,100);
    
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;

//    int x1 = 0; // (50 + 20) * indice
//    int y1 = 500;
//
//    int x2 = 0; // (50 + 20) * indice
//    int y2 = 100; // Altura de algoritmo
//
//    int x1 = x2;
//    int y1 = y2;
//
//    int x2 = 50 // Grueso de la grafica
//    int y2 = 100;
//
//    int x1 = x2;
//    int y1 = y2;
//
//    int x2 = 50 // Grueso de la grafica
//    int y2 = 500;

//    gfx_line(0, 500, 0, 100);
//    gfx_line(0, 100, 50, 100);
//    gfx_line(50, 100, 50, 500);
//
//    gfx_line(70, 500, 70, 100);
//    gfx_line(70, 100, 120, 100);
//    gfx_line(120, 100, 120, 500);

    for (int j = 0; j < barras; j ++) {
        for (int i = 0; i < 3; i ++) {
            switch (i) {
                case 0:
                    x1 = (50 + 20) * j;
                    y1 = 500;
                    
                    x2 = (50 + 20) * j;
                    y2 = 100;
                    break;
                case 1:
                    x1 = (50 + 20) * j;
                    y1 = y2;
                    
                    x2 = (50 + 20) * j + 50;
                    y2 = 100;
                    break;
                case 2:
                    x1 = (50 + 20) * j + 50;
                    y1 = y2;
                    
                    x2 = (50 + 20) * j + 50;
                    y2 = 500;
                    break;
                default:
                    break;
            }
            
            gfx_line(x1, y1, x2, y2);
        }
    }

    while (1) {
        exit = gfx_wait();
        if (exit == 'q') {
            break;
        }
    }
    
    return 0;
}
