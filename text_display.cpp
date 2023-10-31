#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    // initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    initgraph(&gd, &gm, NULL);

    // Set text color and size
    setcolor(YELLOW);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);

    // Coordinates where the text will be displayed
    int x = 100, y = 100;

    // The string to display
    char text[] = "Hello, C Graphics!";

    // Display the string on the screen
    outtextxy(x, y, text);

    // Close the graphics window
    delay(5000); // Delay for 5 seconds before closing
    closegraph();

    return 0;
}
