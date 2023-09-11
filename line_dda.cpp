// dda_line.c
#include <stdio.h>
#include <graphics.h>
#include <cmath>

void dda(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    printf("steps= %d\n", steps);

    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;

    float x = x1;
    float y = y1;

    putpixel(x, y, WHITE);

    for (int i = 0; i < steps; i++)
    {
        x += xIncrement;
        y += yIncrement;
        putpixel(round(x), round(y), WHITE);
        printf("\n%d\t(%f, %f)", i, x, y);
        // printf("\n%d\t(%d, %d)", i, round(x), round(y));
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1 = 1, y1 = 1;
    int x2 = 150, y2 = 100;

    dda(x1, y1, x2, y2);

    delay(5000);
    closegraph();
    return 0;
}
