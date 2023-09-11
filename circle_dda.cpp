#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void drawCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int p = 1 - r;

    while (x <= y)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        x++;

        if (p < 0)
            p = p + 2 * x + 1;
        else
        {
            y--;
            p = p + 2 * (x - y) + 1;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // int xc, yc, r;
    // printf("Enter the center coordinates (xc, yc) of the circle: ");
    // scanf("%d %d", &xc, &yc);
    // printf("Enter the radius of the circle: ");
    // scanf("%d", &r);

    int xc = 320; // X-coordinate of center
    int yc = 240; // Y-coordinate of center
    int r = 50;
    // int r = 20;

    drawCircle(xc, yc, r);

    getch();
    closegraph();
    return 0;
}
