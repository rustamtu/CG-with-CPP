#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    
    // Initialize graphics mode
    // initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    initgraph(&gd, &gm, NULL);
    
    // Coordinates of the original object
    int originalObject[] = {100, 100, 200, 100, 150, 200, 100, 100};
    
    // Drawing the original object
    drawpoly(4, originalObject);
    
    // Coordinates of the reflected object
    int reflectedObject[8];
    
    // Reflect the original object horizontally
    for (int i = 0; i < 4; i++) {
        reflectedObject[i * 2] = getmaxx() - originalObject[i * 2];
        reflectedObject[i * 2 + 1] = originalObject[i * 2 + 1];
    }
    
    // Drawing the reflected object
    drawpoly(4, reflectedObject);
    
    getch();
    closegraph();
    
    return 0;
}
