//
//  main.cpp
//  
//
//  Created by Lalo Espino on 08/04/18.
//
// To compile file use:
// gcc main.cpp gfx.c -o main -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lm
//
// To run file:
// ./main
//
// When XQuartz window is open, and you want to exit type 'q'
//

#include "gfx.h"
#include <iostream>

using namespace std;

int main(int args, char* argv[]) {
    const int GFX_WIDTH = 500;
    const int GFX_HEIGHT = 500;
    const char GFX_TITLE[] = "Proyecto 3 DSD";
    
    char exit;
    
    gfx_open(GFX_WIDTH, GFX_HEIGHT, GFX_TITLE);
    gfx_color(0,200,100);
    
    gfx_line(0, 500, 0, 100);
    gfx_line(0, 100, 50, 100);
    gfx_line(50, 100, 50, 500);
    
    gfx_line(70, 500, 70, 100);
    gfx_line(70, 100, 120, 100);
    gfx_line(120, 100, 120, 500);
    
    while (1) {
        exit = gfx_wait();
        if (exit == 'q') {
            break;
        }
    }
    
    return 0;
}
