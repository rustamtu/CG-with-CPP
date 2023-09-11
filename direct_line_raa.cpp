// dda_line.c
#include <stdio.h>
#include <graphics.h>
#include <cmath>

int min(int a, int b)
{
    return a < b ? a : b;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
void dda(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;

    float x = x1;
    float y = y1;

    putpixel(x, y, WHITE);
    printf("\n%d\t(%f, %f)", 0, x, y);
    for (int i = 0; i < steps; i++)
    {
        x += xIncrement;
        y += yIncrement;
        putpixel(round(x), round(y), WHITE);
        // printf("\n%d\t(%f, %f)", i, x, y);
    }
}

void drawLineDirect(int x1, int y1, int x2, int y2)
{
    // float m = (float)(y2 - y1) / (x2 - x1);

    // for (int x = x1; x <= x2; x++)
    // {
    //     int y = m * x + b;
    //     putpixel(x, y, WHITE);
    //     printf("%d\t%d\n", x, y);
    // }

    float m = (float)(y2 - y1) / (x2 - x1);
    float b = y1 - m * x1;
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    if (dx >= dy)
    {
        for (int x = min(x1, x2); x <= max(x1, x2); x++)
        {
            int y = y1 + m * (x - x1);
            putpixel(x, y, WHITE);
            printf("%d\t%d\n", x, y);
        }
    }
    else
    {
        for (int y = min(y1, y2); y <= max(y1, y2); y++)
        {
            int x = x1 + (y - y1) / m;
            putpixel(x, y, WHITE);
            printf("%d\t%d\n", x, y);
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1 = 150, y1 = 50;
    int x2 = 157, y2 = 350;
    // int x1 = 150, y1 = 350;
    // int x2 = 157, y2 = 50;

    drawLineDirect(x1, y1, x2, y2);
    setcolor(RED);
    dda(x1 + 20, y1 + 20, x2 + 20, y2 + 20);

    // delay(10000);
    getch();
    closegraph();
    return 0;
}
