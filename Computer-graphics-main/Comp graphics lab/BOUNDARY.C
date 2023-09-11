// C Implementation for Boundary Filling Algorithm
#include <stdio.h>
#include <graphics.h>
#include <conio.h>

// Function for 4 connected Pixels
void boundaryfill(int x, int y, int f_color, int b_color)
{
    printf("x= %d, y= %d, b_color= %d, f_color= %d\n", x,  y,  b_color, f_color);
    if (getpixel(x, y) != b_color && getpixel(x, y) != f_color)
    {
        putpixel(x, y, f_color);
        boundaryfill(x + 1, y, f_color, b_color);
        boundaryfill(x, y + 1, f_color, b_color);
        boundaryfill(x - 1, y, f_color, b_color);
        boundaryfill(x, y - 1, f_color, b_color);
    }
}
// getpixel(x,y) gives the color of specified pixel

int main()
{
    int gm, gd = DETECT, radius;
    int x, y;
    
    radius=50;
    x=200, y=200;
    initgraph(&gd, &gm, NULL);

    circle(x, y, radius);
    boundaryfill(x, y, 4, 15);
    getch();
    closegraph();
    return 0;
}