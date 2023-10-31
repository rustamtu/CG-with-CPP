#include <stdio.h>
#include <graphics.h>

// Function to clip a point to a rectangular window
void clipPoint(int x, int y, int x_min, int y_min, int x_max, int y_max)
{
    if (x >= x_min && x <= x_max && y >= y_min && y <= y_max)
    {
        // Point is inside the window, so draw it
        putpixel(x, y, WHITE);
    }
    else
    {
        printf("Given point is outside of the rectangular window\n");
    }
}

int main()
{
    int gd = DETECT, gm;
    // initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    initgraph(&gd, &gm, NULL);

    int x_min = 100, y_min = 100, x_max = 400, y_max = 300;

    // Draw the rectangular window
    rectangle(x_min, y_min, x_max, y_max);

    // Coordinates of the point to be clipped
    int x = 200, y = 200;
    // int x = 500, y = 200; //outside of the window

    // Clip the point to the rectangular window
    clipPoint(x, y, x_min, y_min, x_max, y_max);

    // Delay to view the result
    delay(50000);

    closegraph();

    return 0;
}
