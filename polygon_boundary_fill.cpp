#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

// Function to perform 8-connected boundary fill
void boundaryFill8(int x, int y, int boundaryColor, int fillColor)
{
    int currentColor = getpixel(x, y);
    printf("x= %d, y= %d, boundaryColor= %d, fillColor= %d\n", x,  y,  boundaryColor, fillColor);
    // Base case: If the current pixel color is not the boundary color or is the fill color, return
    if (currentColor != boundaryColor && currentColor != fillColor)
    {
        putpixel(x, y, fillColor);

        // Recursively fill in 8-connected neighbors
        boundaryFill8(x + 1, y, boundaryColor, fillColor);
        boundaryFill8(x - 1, y, boundaryColor, fillColor);
        boundaryFill8(x, y + 1, boundaryColor, fillColor);
        boundaryFill8(x, y - 1, boundaryColor, fillColor);
        boundaryFill8(x + 1, y + 1, boundaryColor, fillColor);
        boundaryFill8(x - 1, y + 1, boundaryColor, fillColor);
        boundaryFill8(x + 1, y - 1, boundaryColor, fillColor);
        boundaryFill8(x - 1, y - 1, boundaryColor, fillColor);
    }
}

int main()
{
    int gd = DETECT, gm;
    // initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    initgraph(&gd, &gm, NULL);

    int x, y; // Seed point coordinates
    printf("Enter the seed point (x, y): ");
    scanf("%d%d", &x, &y);

    int boundaryColor = getpixel(x, y); // Get the boundary color from the seed point
    int fillColor;                      // Fill color
    printf("Enter the fill color (integer value): ");
    scanf("%d", &fillColor);

    boundaryFill8(x, y, boundaryColor, fillColor);

    getch();
    closegraph();
    return 0;
}
