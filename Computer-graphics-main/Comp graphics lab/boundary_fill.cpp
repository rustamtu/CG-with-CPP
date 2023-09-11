#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void bf(int x, int y, int bc, int color)
{
    int cc = getpixel(x, y);
    printf("%d %d %d %d %d \n", x, y, cc, bc, color);
    
    if (cc != bc && cc != color)
    { // printf("%d %d %d %d %d \n",x,y,cc,bc,color)
        putpixel(x, y, color);
        bf(x + 1, y, bc, color);
        bf(x - 1, y, bc, color);
        bf(x, y + 1, bc, color);
        bf(x, y - 1, bc, color);
        bf(x + 1, y + 1, bc, color);
        bf(x - 1, y + 1, bc, color);
        bf(x + 1, y - 1, bc, color);
        bf(x - 1, y - 1, bc, color);
    }
}

int main()
{
    int gd = DETECT, gm;
    // clrscr();
    // initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    initgraph(&gd, &gm, NULL);
    setcolor(15);
    ellipse(400, 300, 0, 360, 200, 100);
    bf(400, 300, 15, 2);
    getch();
    closegraph();
    
    return 0;
}
