//
//  main.cpp
//  
//
//  Created by Lalo Espino on 08/04/18.
//
//  Para compilar el archivo escriba el siguiente comando en terminal:
//  gcc main.cpp gfx.c -o main -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lm
//
//  Para ejecutar el programa escriba lo siguiente en terminal:
//  (n es el número de barras que van a aparecer y m el límite superior que tendrán)
//  ./main n m
//
//  Cuando la ventana de XQuartz esté abierta presione la tecla 'q' para salir
//

#include "gfx.h"
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

class Barra {
    int x1;
    int y1;
    int x2;
    int y2;
    
public:
    void graficarBarra();
    void setX1(int x);
    void setY1(int y);
    void setX2(int x);
    void setY2(int y);
    int getX1();
    int getY1();
    int getX2();
    int getY2();
};

/*  Dibuja la linea correspondiente con los parametros establecidos  */

void Barra::graficarBarra() {
    gfx_line(x1, y1, x2, y2);
}

/*  Setters  */

void Barra::setX1(int x) {
    x1 = x;
}

void Barra::setY1(int y) {
    y1 = y;
}

void Barra::setX2(int x) {
    x2 = x;
}

void Barra::setY2(int y) {
    y2 = y;
}

/*  Getters  */

int Barra::getX1() {
    return x1;
}

int Barra::getY1() {
    return y1;
}

int Barra::getX2() {
    return x2;
}

int Barra::getY2() {
    return y2;
}

int main (int argc, char* argv[]) {
    
    /*  Variables de gfx  */
    const int GFX_WIDTH         = 1000;
    const int GFX_HEIGHT        = 500;
    const char GFX_TITLE[]      = "Proyecto 3 DSD";
    
    /*  Variables de negocio  */
    const int BARRAS_DESEADAS   = atoi(argv[1]);
    const int LIMITE_SUPERIOR   = atoi(argv[2]);
    
    int xMax = 0;
    
    Barra barras[BARRAS_DESEADAS];

    printf("\n\tBarras: %d\n\tLímite superior: %d\n\n", BARRAS_DESEADAS, LIMITE_SUPERIOR);

    /*  Creación de ventana de gfx y asignación de colores a lineas  */
    gfx_open(GFX_WIDTH, GFX_HEIGHT, GFX_TITLE);
    gfx_color(0, 200, 100);
    
    char exit; /*  Variable para fin de ejecución de programa  */
    
    srand (time(NULL)); /*  Random seed  */

    for (int j = 0; j < BARRAS_DESEADAS; j ++) { /*  Se ejecuta por el número deseado de barras  */

        xMax = rand() % LIMITE_SUPERIOR + 1;

        for (int i = 0; i < 3; i ++) { /*  Genera las lineas de una barra  */
            
            switch (i) {
                case 0: /*  Para crear primera linea  */
                    
                    barras[j].setX1((50 + 20) * j);
                    barras[j].setY1(500);
                    
                    barras[j].setX2((50 + 20) * j);
                    barras[j].setY2(100 * xMax);

                    break;
                case 1: /*  Para crear linea interseptora */
                    
                    barras[j].setX1((50 + 20) * j);
                    barras[j].setY1(barras[j].getY2());
                    
                    barras[j].setX2((50 + 20) * j + 50);
                    barras[j].setY2(100 * xMax);

                    break;
                case 2: /*  Para crear segunda linea  */
                    
                    barras[j].setX1((50 + 20) * j + 50);
                    barras[j].setY1(barras[j].getY2());

                    barras[j].setX2((50 + 20) * j + 50);
                    barras[j].setY2(500);

                    break;
                default:
                    break;
            }

            barras[j].graficarBarra();
            
        }
    }
    
    
    /*  Mientras no se escriba por teclado una letra 'q' se ejecuta el programa  */

    while (1) {
        exit = gfx_wait();
        
        if (exit == 'q') {
            break;
        }
    }
    
    return 0;
}
