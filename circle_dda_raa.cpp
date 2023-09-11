#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void drawCircle(int xc, int yc, int radius)
{
    int y = radius;
    int x = 0;
    int err = 0;
    printf("err\tx\ty\n");

    while (x <= y)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        printf("%d\t%d\t%d\n", err, x, y);
        if (err <= 0)
        {
            x += 1;
            err += 2 * x + 1;
        }

        if (err > 0)
        {

            y -= 1;
            err -= 2 * y + 1;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int xc = 320; // X-coordinate of center
    int yc = 240; // Y-coordinate of center
    int radius = 300;
    // int radius = 20;

    drawCircle(xc, yc, radius);

    getch();
    closegraph();
    return 0;
}
