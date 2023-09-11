#include <stdio.h>
#include <graphics.h>

void drawLineDirect(int x1, int y1, int x2, int y2)
{
    float m = (float)(y2 - y1) / (x2 - x1);

    for (int x = x1; x <= x2; x++)
    {
        int y = y1 + m * (x - x1);
        // putpixel(x, y, WHITE);
        printf("%d\t%d\n", x, y);
    }
}

int main()
{
    int gd = DETECT, gm;
    // initgraph(&gd, &gm, NULL);

    int x1 = 2, y1 = 5;
    int x2 = 7, y2 = 15;

    drawLineDirect(x1, y1, x2, y2);

    // delay(5000);
    // closegraph();
    return 0;
}
