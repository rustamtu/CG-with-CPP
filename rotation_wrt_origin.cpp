// rotation_wrt_origin
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <string.h>

void showMatrix(float a[][3], int rows = 3)
{
    int i, j;
    printf("\n---------Matrix---------");
    for (i = 0; i < rows; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%.2f\t", a[i][j]);
        }
    }
}

void MatrixMult(float a[3][3], float b[3][3], float m[3][3] = {0})
{
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            m[i][j] = 0;
            for (k = 0; k < 3; k++)
            {
                m[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    showMatrix(m, 3);
}

void drawPolygonFromMatrix(float x[][3], int n)
{
    int i, j, pointArray[100];
    char pNames[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char pName[2] = "x";
    for (i = 0; i < n; i++)
    {
        pointArray[i * 2] = round(x[i][0]);
        pointArray[i * 2 + 1] = round(x[i][1]);
        // outtextxy(pointArray[i * 2], pointArray[i * 2 + 1], strcat("A()", "&pName="));
        pName[0] = pNames[i];
        outtextxy(pointArray[i * 2], pointArray[i * 2 + 1], pName);
    }
    pointArray[n * 2] = round(x[0][0]);
    pointArray[n * 2 + 1] = round(x[0][1]);

    printf("\nPoints= ");
    for (i = 0; i < n; i++)
    {
        printf("%c(%d, %d) ", pNames[i], pointArray[i * 2], pointArray[i * 2 + 1]);
    }
    drawpoly(n + 1, pointArray);
}

void getNewPoints(float pointMatrix[][3], float Transformation[3][3], float newPointMatrix[][3] = {0}, int rows = 3)
{
    int i, j, k;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < 3; j++)
        {
            newPointMatrix[i][j] = 0;
            for (k = 0; k < 3; k++)
            {
                newPointMatrix[i][j] += pointMatrix[i][k] * Transformation[k][j];
            }
        }
    }
    showMatrix(newPointMatrix, rows);
}

int main()
{
    int gd = DETECT, gm;
    // float theta = 45 * 3.14159265 / 180;
    float theta = 20 * 3.14159265 / 180;
    float rotation[3][3] = {{cos(theta), sin(theta), 0}, {-sin(theta), cos(theta), 0}, {0, 0, 1}};

    // Coordinates of the original object
    float pointMatrix[3][3] = {{200, 100, 1}, {300, 100, 1}, {250, 200, 1}};
    float newPointMatrix[3][3];
    int rows = 3;

    showMatrix(rotation);
    showMatrix(pointMatrix, rows);

    // Get New Coordinates of the transformed object
    printf("\nNew Coordinates of the transformed object");
    getNewPoints(pointMatrix, rotation, newPointMatrix, rows); // newPointMatrix=pointMatrix*r3

    // Initialize graphics mode
    // initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    initgraph(&gd, &gm, NULL);

    // Drawing the original object
    drawPolygonFromMatrix(pointMatrix, rows);
    drawPolygonFromMatrix(newPointMatrix, rows);

    getch();
    closegraph();

    return 0;
}
