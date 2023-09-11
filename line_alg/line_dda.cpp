#include <stdio.h>
#include <graphics.h>
#include <math.h>

void drawDDALine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++)
    {
        putpixel(round(x), round(y), WHITE);
        printf("(%d, %d)\n", round(x), round(y));
        x += xIncrement;
        y += yIncrement;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1 = 100, y1 = 100, x2 = 300, y2 = 200;

    drawDDALine(x1, y1, x2, y2);

    delay(50000);
    closegraph();
    return 0;
}
