#include <iostream>
#include <graphics.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = getmaxx() / 2;
    int yc = getmaxy() / 2;
    int a = 200;
    int b = 100;

    int x = 0, y = b;
    int a_sqr = a * a;
    int b_sqr = b * b;
    int delta = 4 * b_sqr * ((x + 1) * (x + 1)) + a_sqr * ((2 * y - 1) * (2 * y - 1)) - 4 * a_sqr * b_sqr;

    while (a_sqr * (2 * y - 1) > 2 * b_sqr * (x + 1))
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (delta < 0)
        {
            x++;
            delta += 4 * b_sqr * (2 * x + 3);
        }
        else
        {
            x++;
            y--;
            delta += 4 * b_sqr * (2 * x + 3) - 8 * a_sqr * y;
        }
    }

    delta = b_sqr * ((2 * x + 1) * (2 * x + 1)) + 4 * a_sqr * ((y + 1) * (y + 1)) - 4 * a_sqr * b_sqr;

    while (y + 1 != 0)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (delta < 0)
        {
            y--;
            x++;
            delta += 4 * b_sqr * (2 * x + 2) - 8 * a_sqr * y;
        }
        else
        {
            y--;
            delta += 4 * b_sqr * (2 * x + 2);
        }
    }

    setfillstyle(SOLID_FILL, RED);
    fillellipse(xc, yc, a, b);

    setcolor(WHITE);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
    outtextxy(xc - textwidth("BC200409798") / 2, yc - b - textheight("BC200409798") - 10, "BC200409798");

    getch();
    closegraph();
    return 0;
}

