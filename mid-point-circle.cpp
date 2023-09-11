// Mid Point Circle algorithm
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void drawCircle(int centerX, int centerY, int radius)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
        printf("(%d, %d)\n", x, y);
        putpixel(centerX + x, centerY + y, WHITE);
        putpixel(centerX + y, centerY + x, WHITE);
        putpixel(centerX - y, centerY + x, WHITE);
        putpixel(centerX - x, centerY + y, WHITE);
        putpixel(centerX - x, centerY - y, WHITE);
        putpixel(centerX - y, centerY - x, WHITE);
        putpixel(centerX + y, centerY - x, WHITE);
        putpixel(centerX + x, centerY - y, WHITE);

        if (err <= 0)
        {
            y += 1;
            err += 2 * y + 1;
        }

        if (err > 0)
        {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    // initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
    initgraph(&gd, &gm, NULL);

    int centerX = 320; // Change this value to position the circle's center
    int centerY = 240; // Change this value to position the circle's center
    int radius = 100;  // Change this value to adjust the circle's radius

    drawCircle(centerX, centerY, radius);

    getch();
    closegraph();
    return 0;
}
