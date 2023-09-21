#include <stdio.h>
#include <conio.h>
#include <graphics.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to scale a point about a fixed point
void scalePointAboutFixedPoint(int *x, int *y, float scaleX, float scaleY, int fixedX, int fixedY) {
    *x = fixedX + (*x - fixedX) * scaleX;
    *y = fixedY + (*y - fixedY) * scaleY;
}

int main() {
    int gd=DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int x1, y1;
    int x2, y2;
    int x3, y3;
    int fixedX, fixedY;

    // Input the coordinates of the triangle vertices
    printf("Enter the coordinates of the first point (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2 y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the coordinates of the third point (x3 y3): ");
    scanf("%d %d", &x3, &y3);
    // Draw the original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Input the pivot point coordinates for rotation
    printf("Enter the pivot point coordinates (px py)\n (0, 0) for origin: ");
    scanf("%d %d", &fixedX, &fixedY);

    float scaleX, scaleY;
    printf("Enter the scaling factor along X-axis and Y-axis: ");
    scanf("%f %f", &scaleX, &scaleY);

    // Draw the fixed point
    putpixel(fixedX, fixedY, WHITE);

    // Scale triangle about the fixed point
    scalePointAboutFixedPoint(&x1, &y1, scaleX, scaleY, fixedX, fixedY);
    scalePointAboutFixedPoint(&x2, &y2, scaleX, scaleY, fixedX, fixedY);
    scalePointAboutFixedPoint(&x3, &y3, scaleX, scaleY, fixedX, fixedY);

    // Draw the scaled triangle about the fixed point
    drawTriangle(x1, y1, x2, y2, x3, y3);

    getch();
    closegraph();
    return 0;
}
