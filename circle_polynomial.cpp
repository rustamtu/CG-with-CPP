#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <cmath>

int abss(int x)
{
    return x < 0 ? -x : x;
}
void drawCircle_by_Polynomial(int xc, int yc, int r)
{
    int x = 0, y = r;

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
        printf("%d\t%d\n", x, y);
        x++;
        y = abss(sqrt(r * r - x * x));
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
    int r = 15;
    // int r = 20;

    drawCircle_by_Polynomial(xc, yc, r);

    getch();
    closegraph();
    return 0;
}
