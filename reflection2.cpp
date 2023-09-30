#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void showMatrix(float a[3][3])
{
    int i, j;
    printf("\n---------Matrix---------");
    for (i = 0; i < 3; i++)
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
    showMatrix(m);
}

int main()
{
    int gd = DETECT, gm;
    float t1[3][3] = {{1, 0, 0}, {0, 1, 0}, {3, 0, 1}};
    float t2[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 2, 1}};
    float t3[3][3] = {{1, 0, 0}, {0, 1, 0}, {1, .5, 1}};
    float t4[3][3] = {{1, 0, 0}, {0, 1, 0}, {-4, -0.66, 1}};
    float r[3][3];

    showMatrix(t1);
    showMatrix(t2);
    showMatrix(t3);
    showMatrix(t4);

    printf("\n---------Multiplication------------");
    MatrixMult(t1, t2, r);
    MatrixMult(r, t3, r);
    MatrixMult(r, t4, r);

    // Initialize graphics mode
    // initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    // initgraph(&gd, &gm, NULL);

    // // Coordinates of the original object
    // int originalObject[] = {100, 100, 200, 100, 150, 200, 100, 100};
    // outtextxy(originalObject[0] - 10, originalObject[1] - 15, "A");
    // outtextxy(originalObject[2] + 5, originalObject[3] - 15, "B");
    // outtextxy(originalObject[4] - 10, originalObject[5] + 5, "C");
    // // outtextxy(200, 150, "Hello Geek, Have a good day !");

    // // Drawing the original object
    // drawpoly(4, originalObject);

    // // Coordinates of the reflected object
    // int reflectedObject[8];

    // // Reflect the original object horizontally
    // for (int i = 0; i < 4; i++)
    // {
    //     reflectedObject[i * 2] = getmaxx() - originalObject[i * 2];
    //     reflectedObject[i * 2 + 1] = originalObject[i * 2 + 1];
    // }

    // // Drawing the reflected object
    // drawpoly(4, reflectedObject);

    getch();
    // closegraph();

    return 0;
}
