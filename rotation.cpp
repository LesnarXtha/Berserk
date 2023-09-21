#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to rotate a point (x, y) about a pivot point (px, py) by angle theta (in radians)
void rotatePoint(int px, int py, int *x, int *y, float theta) {
    int x_new = px + (*x - px) * cos(theta) - (*y - py) * sin(theta);
    int y_new = py + (*x - px) * sin(theta) + (*y - py) * cos(theta);
    *x = x_new;
    *y = y_new;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int x1, y1, x2, y2, x3, y3; // Coordinates of the triangle vertices
    int pivot_x, pivot_y; // Pivot point coordinates for rotation
    float angle; // Angle of rotation (in degrees)

    // Input the coordinates of the triangle vertices
    printf("Enter the coordinates of the first point (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point (x2 y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the coordinates of the third point (x3 y3): ");
    scanf("%d %d", &x3, &y3);

    // Draw the initial triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Input the pivot point coordinates for rotation
    printf("Enter the pivot point coordinates (px py)\n (0, 0) for origin: ");
    scanf("%d %d", &pivot_x, &pivot_y);

    // Input the angle of rotation (in degrees)
    printf("Enter the angle of rotation (in degrees): ");
    scanf("%f", &angle);

    // Convert the angle from degrees to radians
    angle = angle * M_PI / 180.0f;

    // Rotate each vertex of the triangle about the origin
    rotatePoint(pivot_x, pivot_y, &x1, &y1, angle);
    rotatePoint(pivot_x, pivot_y, &x2, &y2, angle);
    rotatePoint(pivot_x, pivot_y, &x3, &y3, angle);

    // Draw the rotated triangle
    setcolor(BLUE);
    drawTriangle(x1, y1, x2, y2, x3, y3);

    getch();
    closegraph();

    return 0;
}
