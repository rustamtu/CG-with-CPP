// C graphics program to draw an ellipse using the Midpoint Ellipse Drawing Algorithm. 
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void drawEllipse(int x_center, int y_center, int a, int b) {
    int x = 0, y = b;
    int a_squared = a * a;
    int b_squared = b * b;
    int two_a_squared = 2 * a_squared;
    int two_b_squared = 2 * b_squared;
    int four_a_squared = 4 * a_squared;
    int four_b_squared = 4 * b_squared;
    int d = b_squared - a_squared * b + 0.25 * a_squared;

    while (two_a_squared * (y - 0.5) > two_b_squared * (x + 1)) {
        putpixel(x_center + x, y_center + y, WHITE);
        putpixel(x_center - x, y_center + y, WHITE);
        putpixel(x_center + x, y_center - y, WHITE);
        putpixel(x_center - x, y_center - y, WHITE);

        if (d < 0) {
            x++;
            d += four_b_squared * x + two_b_squared;
        } else {
            x++;
            y--;
            d += four_b_squared * x - four_a_squared * y + two_b_squared;
        }
    }

    d = b_squared * (x + 0.5) * (x + 0.5) + a_squared * (y - 1) * (y - 1) - a_squared * b_squared;

    while (y > 0) {
        putpixel(x_center + x, y_center + y, WHITE);
        putpixel(x_center - x, y_center + y, WHITE);
        putpixel(x_center + x, y_center - y, WHITE);
        putpixel(x_center - x, y_center - y, WHITE);

        if (d < 0) {
            x++;
            y--;
            d += four_b_squared * x - four_a_squared * y + two_a_squared;
        } else {
            y--;
            d += -four_a_squared * y + two_a_squared;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    // initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    initgraph(&gd, &gm, NULL);

    int x_center = getmaxx() / 2;
    int y_center = getmaxy() / 2;
    int a = 100;
    int b = 50;

    drawEllipse(x_center, y_center, a, b);

    delay(50000);
    closegraph();
    return 0;
}
