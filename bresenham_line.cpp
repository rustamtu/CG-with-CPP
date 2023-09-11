#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void drawLine(int x1, int y1, int x2, int y2)
{
}
void drawLineBresenham(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int slope = dy > dx;

    if (slope)
    {
        int temp = dx;
        dx = dy;
        dy = temp;
    }

    int x = x1, y = y1;
    int err = 2 * dy - dx;

    for (int i = 0; i <= dx; i++)
    {
        putpixel(x, y, WHITE);
        printf("%d, %d\n", x, y);
        while (err > 0)
        {
            if (slope)
                x += (x2 > x1 ? 1 : -1);
            else
                y += (y2 > y1 ? 1 : -1);
            err -= 2 * dx;
        }
        if (slope)
            y += (y2 > y1 ? 1 : -1);
        else
            x += (x2 > x1 ? 1 : -1);
        err += 2 * dy;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1 = 10, y1 = 10, x2 = 30, y2 = 20;

    // printf("Enter the starting point (x1 y1): ");
    // scanf("%d %d", &x1, &y1);

    // printf("Enter the ending point (x2 y2): ");
    // scanf("%d %d", &x2, &y2);

    drawLineBresenham(x1, y1, x2, y2);

    delay(10000);
    closegraph();

    return 0;
}
