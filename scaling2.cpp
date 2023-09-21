#include <stdio.h>
#include <conio.h>
#include <graphics.h>

// Function to draw a circle using Bresenham's algorithm
void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 3 - 2 * r;
    
    while (x <= y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        
        if (p < 0) {
            p = p + 4 * x + 6;
        } else {
            p = p + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

// Function to scale a point about a fixed point
void scalePointAboutFixedPoint(int *x, int *y, float scaleX, float scaleY, int fixedX, int fixedY) {
    *x = fixedX + (*x - fixedX) * scaleX;
    *y = fixedY + (*y - fixedY) * scaleY;
}

int main() {
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int xc, yc;
    int r;
    int fixedX, fixedY;

    // Input the coordinates of the circle center
    printf("Enter the coordinates of the circle center (xc yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter the radius of the circle: ");
    scanf("%d", &r);

    // Draw the original circle
    drawCircle(xc, yc, r);

    // Input the pivot point coordinates for scaling
    printf("Enter the pivot point coordinates (px py)\n (0, 0) for origin: ");
    scanf("%d %d", &fixedX, &fixedY);

    float scaleX, scaleY;
    printf("Enter the scaling factor along X-axis and Y-axis: ");
    scanf("%f %f", &scaleX, &scaleY);

    // Draw the fixed point
    putpixel(fixedX, fixedY, WHITE);

    // Scale the circle about the fixed point
    scalePointAboutFixedPoint(&xc, &yc, scaleX, scaleY, fixedX, fixedY);
    r *= scaleX;

    // Draw the scaled circle about the fixed point
    drawCircle(xc, yc, r);

    getch();
    closegraph();
    return 0;
}
