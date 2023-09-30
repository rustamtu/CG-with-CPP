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
    float t1[3][3] = {{1, 0, 0}, {0, 1, 0}, {30, 0, 1}};
    float t2[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 30, 1}};
    float t3[3][3] = {{1, 0, 0}, {0, 1, 0}, {50, -10, 1}};
    float t4[3][3] = {{1, 0, 0}, {0, 1, 0}, {10, -5, 1}};
    float r1[3][3];
    float r2[3][3];
    float r3[3][3];
    // Coordinates of the original object
    float pointMatrix[3][3] = {{100, 100, 1}, {200, 100, 1}, {150, 200, 1}};
    float newPointMatrix[3][3];
    int rows = 3;

    showMatrix(t1);
    showMatrix(t2);
    showMatrix(t3);
    showMatrix(t4);
    showMatrix(pointMatrix, rows);

    printf("\n---------Multiplication------------");
    MatrixMult(t1, t2, r1); // r1=a*t1
    MatrixMult(r1, t3, r2); // r2=r1*t3
    MatrixMult(r2, t4, r3); // r3=r2*t4 ie t1*t2*t3*t4

    // Get New Coordinates of the transformed object
    printf("\nNew Coordinates of the transformed object");
    getNewPoints(pointMatrix, r3, newPointMatrix, rows); // newPointMatrix=pointMatrix*r3

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
