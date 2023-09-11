#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void drawCircle(int cx, int cy, int radius, int color)
{
    int x = radius;
    int y = 0;
    int err = 0;
    printf("\nCircle for Center (%d,%d):\n", x + cx, y + cy);
    while (x >= y)
    {
        printf("(%d,%d)\n", x, y);
        putpixel(cx + x, cy + y, color);
        putpixel(cx + x, cy - y, color);
        putpixel(cx - x, cy + y, color);
        putpixel(cx - x, cy - y, color);
        putpixel(cx + y, cy + x, color);
        putpixel(cx + y, cy - x, color);
        putpixel(cx - y, cy + x, color);
        putpixel(cx - y, cy - x, color);

        if (err <= 0)
        {
            y += 1;
            err += (2 * y) + 1;
        }
        if (err > 0)
        {
            x -= 1;
            err -= (2 * x) + 1;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    int cx = 330;
    int cy = 300;
    int r = 80;
    initgraph(&gd, &gm, NULL);
    drawCircle(cx, cy, r, WHITE);
    drawCircle(cx, cy + r, r, WHITE);
    drawCircle(cx, cy - r, r, WHITE);
    drawCircle(cx + r, cy, r, WHITE);
    drawCircle(cx - r, cy, r, WHITE);
    // drawCircle(230, 200, 50, WHITE);
    // drawCircle(210, 200, 50, WHITE);
    // drawCircle(220, 200, 50, WHITE);
    // drawCircle(220, 210, 50, WHITE);
    // drawCircle(220, 190, 50, WHITE);
    getch();
    closegraph();

    return 0;
}