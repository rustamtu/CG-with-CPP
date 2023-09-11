#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        printf("(%d, %d)\n", x1, y1);
        putpixel(x1, y1, WHITE);
        if (x1 == x2 && y1 == y2)
        {
            break;
        }
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

int main()
{
    int x1, y1, x2, y2;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    x1 = 100, y1 = 100;
    x2 = 150, y2 = 130;

    x1 = 150, y1 = 100;
    x2 = 50, y2 = 120;

    // printf("Enter the starting point (x1 y1): ");
    // scanf("%d %d", &x1, &y1);

    // printf("Enter the ending point (x2 y2): ");
    // scanf("%d %d", &x2, &y2);

    printf("Coordinates on the line:\n");
    drawLine(x1, y1, x2, y2);
    getch();
    return 0;
}
