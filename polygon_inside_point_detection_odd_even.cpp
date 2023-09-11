#include <stdio.h>
#include <graphics.h>

// Define the polygon vertices as an array of x and y coordinates.
int polyVertices[] = {100, 100, 200, 100, 200, 200, 100, 200};
int numVertices = 4; // Number of vertices in the polygon

// Function to draw the polygon
void drawPolygon()
{
    drawpoly(numVertices, polyVertices);
}

// Function to check if a point is inside the polygon using the odd-even rule 
int isInsidePolygon(int x, int y)
{
    int oddNodes = 0;
    int j = numVertices - 1;

    for (int i = 0; i < numVertices; i++)
    {
        int xi = polyVertices[i * 2];
        int yi = polyVertices[i * 2 + 1];
        int xj = polyVertices[j * 2];
        int yj = polyVertices[j * 2 + 1];

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
    int testPointX = 350;
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

    // delay(5000); // Delay to display the result
    getch();
    closegraph();
    return 0;
}
