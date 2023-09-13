#include <stdio.h>
#include <graphics.h>

// Define the polygon vertices as an array of x and y coordinates.
int polyVertices[] = {100, 100, 200, 100, 200, 200, 100, 200, 100, 100};
int numVertices = 4; // Number of vertices in the polygon

// Function to draw the polygon
void drawPolygon()
{
    drawpoly(numVertices + 1, polyVertices);
}

// Function to check if a point is inside the polygon using the odd-even rule
int isInsidePolygon(int x, int y)
{
    int oddNodes = 0;
    int j = numVertices - 1;
    putpixel(x, y, RED);
    printf("\nPoint Position: %d\t%d\n", x, y);

    for (int i = 0; i < numVertices; i++)
    {
        j = i + 1;
        int xi = polyVertices[i * 2];
        int yi = polyVertices[i * 2 + 1];
        int xj = polyVertices[j * 2];
        int yj = polyVertices[j * 2 + 1];

        printf("%d\t%d\t%d\t%d\n", xi, yi, xj, yj);

        if ((yi < y && yj >= y) || (yj < y && yi >= y))
        {
            if (xi + (y - yi) / (double)(yj - yi) * (xj - xi) < x)
            {
                oddNodes = !oddNodes;
            }
        }
        j = i;
    }

    return oddNodes;
}

int main()
{
    int gd = DETECT, gm;
    // initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    initgraph(&gd, &gm, NULL);

    drawPolygon();
    int testPointX = 120;
    int testPointY = 150;

    if (isInsidePolygon(testPointX, testPointY))
    {
        // outtextxy(10, 10, "Point is inside the polygon.");
        printf("Point is inside the polygon.\n");
    }
    else
    {
        // outtextxy(10, 10, "Point is outside the polygon.");
        printf("Point is outside the polygon.\n");
    }

    // test with 2nd point
    testPointX = 320;
    testPointY = 150;
    if (isInsidePolygon(testPointX, testPointY))
    {
        // outtextxy(10, 10, "Point is inside the polygon.");
        printf("Point is inside the polygon.\n");
    }
    else
    {
        // outtextxy(10, 10, "Point is outside the polygon.");
        printf("Point is outside the polygon.\n");
    }

    // delay(5000); // Delay to display the result
    getch();
    closegraph();
    return 0;
}
