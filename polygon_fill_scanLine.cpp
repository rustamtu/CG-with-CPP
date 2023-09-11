#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

// Function to draw a horizontal line segment
void drawHorizontalLine(int x1, int x2, int y)
{
    for (int i = x1; i <= x2; i++)
    {
        putpixel(i, y, WHITE);
    }
}

// Function to implement the scan-line fill algorithm
void scanLineFill(int x[], int y[], int n)
{
    int ymin = y[0], ymax = y[0];

    // Find the minimum and maximum y-coordinates
    for (int i = 1; i < n; i++)
    {
        if (y[i] < ymin)
            ymin = y[i];
        if (y[i] > ymax)
            ymax = y[i];
    }

    // For each scan line from ymin to ymax
    for (int y_scan = ymin; y_scan <= ymax; y_scan++)
    {
        int intersections = 0;
        int x_intersections[100];

        // Find intersections with each edge
        for (int i = 0; i < n; i++)
        {
            int j = (i + 1) % n; // Next vertex
            int xi = x[i], yi = y[i];
            int xj = x[j], yj = y[j];

            if (yi <= y_scan && yj >= y_scan || yj <= y_scan && yi >= y_scan)
            {
                // Compute the x-coordinate of the intersection point
                int x_intersection = xi + (float)(y_scan - yi) * (xj - xi) / (yj - yi);
                x_intersections[intersections++] = x_intersection;
            }
        }

        // Sort the intersection points in increasing order
        for (int i = 0; i < intersections - 1; i++)
        {
            for (int j = 0; j < intersections - i - 1; j++)
            {
                if (x_intersections[j] > x_intersections[j + 1])
                {
                    int temp = x_intersections[j];
                    x_intersections[j] = x_intersections[j + 1];
                    x_intersections[j + 1] = temp;
                }
            }
        }

        // Fill the scan line by drawing horizontal segments between intersection points
        for (int i = 0; i < intersections; i += 2)
        {
            int x1 = x_intersections[i];
            int x2 = x_intersections[i + 1];
            drawHorizontalLine(x1, x2, y_scan);
        }

        // Delay to visualize the filling process
        delay(100);
    }
}

int main()
{
    int gd = DETECT, gm;
    // initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    initgraph(&gd, &gm, NULL);

    int n; // Number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int x[100], y[100]; // Arrays to store the coordinates of vertices

    // Input the coordinates of vertices
    printf("Enter the coordinates of the vertices (x, y):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
    }

    // Draw the polygon
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        line(x[i], y[i], x[j], y[j]);
    }

    // Call the scan-line fill function
    scanLineFill(x, y, n);

    getch();
    closegraph();
    return 0;
}
