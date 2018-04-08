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
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int main (int argc, char* argv[]) {
    
    /*  Variables de gfx  */
    const int GFX_WIDTH         = 1000;
    const int GFX_HEIGHT        = 500;
    const char GFX_TITLE[]      = "Proyecto 3 DSD";
    
    /*  Variables de negocio  */
    const int BARRAS            = atoi(argv[1]);
    const int LIMITE_SUPERIOR   = atoi(argv[2]);

    printf("Barras: %d\nLímite superior: %d\n", BARRAS, LIMITE_SUPERIOR);

    gfx_open(GFX_WIDTH, GFX_HEIGHT, GFX_TITLE);
    gfx_color(0,200,100);
    
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    
    char exit;
    
    int xMax = 0;
    srand (time(NULL));

    for (int j = 0; j < BARRAS; j ++) {
        xMax = rand() % LIMITE_SUPERIOR + 1;
        for (int i = 0; i < 3; i ++) {
            switch (i) {
                case 0:
                    x1 = (50 + 20) * j;
                    y1 = 500;
                    
                    x2 = (50 + 20) * j;
                    y2 = 100 * xMax;
                    break;
                case 1:
                    x1 = (50 + 20) * j;
                    y1 = y2;
                    
                    x2 = (50 + 20) * j + 50;
                    y2 = 100 * xMax;
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
