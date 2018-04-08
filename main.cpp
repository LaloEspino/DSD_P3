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
    
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;

    for (int i = 0; i < 3; i ++) {
        switch (i) {
            case 0:
                x1 = 0;
                y1 = 500;
                
                x2 = 0;
                y2 = 100;
                break;
            case 1:
                x1 = x2;
                y1 = y2;
                
                x2 = 50;
                y2 = 100;
                break;
            case 2:
                x1 = x2;
                y1 = y2;
                
                x2 = 50;
                y2 = 500;
                break;
            default:
                break;
        }
        
        gfx_line(x1, y1, x2, y2);
    }

    while (1) {
        exit = gfx_wait();
        if (exit == 'q') {
            break;
        }
    }
    
    return 0;
}
