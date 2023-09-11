#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

// Function to perform flood fill
void floodFill(int x, int y, int boundaryColor, int fillColor)
{
    int currentColor = getpixel(x, y);

    // Base case: If the current pixel color is not the boundary color or is the fill color, return
    if (currentColor != boundaryColor && currentColor != fillColor)
    {
        putpixel(x, y, fillColor);

        // Recursive flood fill in 4-connected neighbors
        floodFill(x + 1, y, boundaryColor, fillColor);
        floodFill(x - 1, y, boundaryColor, fillColor);
        floodFill(x, y + 1, boundaryColor, fillColor);
        floodFill(x, y - 1, boundaryColor, fillColor);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x, y; // Seed point coordinates
    printf("Enter the seed point (x, y): ");
    scanf("%d%d", &x, &y);

    int boundaryColor = getpixel(x, y); // Get the boundary color from the seed point
    int fillColor;                      // Fill color
    printf("Enter the fill color (integer value): ");
    scanf("%d", &fillColor);

    floodFill(x, y, boundaryColor, fillColor);

    getch();
    closegraph();
    return 0;
}
