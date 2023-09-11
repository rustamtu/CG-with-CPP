#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

// Function to check if a point is inside a polygon
int isInside(int x, int y, int polyX[], int polyY[], int n)
{
    int i, j, c = 0;
    for (i = 0, j = n - 1; i < n; j = i++)
    {
        if (((polyY[i] > y) != (polyY[j] > y)) &&
            (x < (polyX[j] - polyX[i]) * (y - polyY[i]) / (polyY[j] - polyY[i]) + polyX[i]))
            c = !c;
    }
    return c;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int polyX[] = {100, 200, 300, 200};
    int polyY[] = {100, 200, 100, 50};
    int n = sizeof(polyX) / sizeof(polyX[0]);

    // Draw the polygon
    drawpoly(n, polyX);
    setfillstyle(SOLID_FILL, BLUE);
    fillpoly(n, polyX);

    int x, y;

    printf("Enter a point (x y): ");
    scanf("%d %d", &x, &y);

    if (isInside(x, y, polyX, polyY, n))
    {
        printf("The point is inside the polygon.\n");
        floodfill(x, y, WHITE); // Fill the point
    }
    else
    {
        printf("The point is outside the polygon.\n");
    }

    delay(5000); // Display for 5 seconds
    closegraph();
    return 0;
}
