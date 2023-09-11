#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void drawCircleDDA(int xc, int yc, int radius)
{
    int x = radius;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    while (x >= y)
    {
        // putpixel(xc + x, yc + y, WHITE);
        // putpixel(xc - x, yc + y, WHITE);
        // putpixel(xc + x, yc - y, WHITE);
        // putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        if (err <= 0)
        {
            y++;
            err += dy;
            dy += 2;
        }

        if (err > 0)
        {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int xc = getmaxx() / 2;
    int yc = getmaxy() / 2;
    int radius = 100;

    drawCircleDDA(xc, yc, radius);

    getch();
    closegraph();
    return 0;
}
