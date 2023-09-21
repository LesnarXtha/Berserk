#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

void drawLine(int x1, int y1, int x2, int y2) {
    line(x1, y1, x2, y2);
}

void translateLine(int *x1, int *y1, int *x2, int *y2, int tx, int ty) {
    *x1 += tx;
    *y1 += ty;
    *x2 += tx;
    *y2 += ty;
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void rotatePointOrigin(int *x, int *y, float theta) {
    int x_new = (*x) * cos(theta) - (*y) * sin(theta);
    int y_new = (*x) * sin(theta) + (*y) * cos(theta);
    *x = x_new;
    *y = y_new;
}

void rotatePointFixed(int px, int py, int *x, int *y, float theta) {
    int x_new = px + (*x - px) * cos(theta) - (*y - py) * sin(theta);
    int y_new = py + (*x - px) * sin(theta) + (*y - py) * cos(theta);
    *x = x_new;
    *y = y_new;
}

void drawCircle(int x, int y, int radius) {
    circle(x, y, radius);
}

void scaleCircle(int x, int y, int radius, int scaleFactor, int fixedX, int fixedY) {
    x -= fixedX;
    y -= fixedY;
    radius *= scaleFactor;
    x += fixedX;
    y += fixedY;
    drawCircle(x, y, radius);
}

void scaleTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int scaleFactor) {
    x1 *= scaleFactor;
    y1 *= scaleFactor;
    x2 *= scaleFactor;
    y2 *= scaleFactor;
    x3 *= scaleFactor;
    y3 *= scaleFactor;
    drawTriangle(x1, y1, x2, y2, x3, y3);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    int choice;

    printf("Choose the shape to draw and transform:\n");
    printf("1. Line\n");
    printf("2. Triangle\n");
    printf("3. Circle\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            // Line
            int line_x1 = 100, line_y1 = 100, line_x2 = 300, line_y2 = 100;
            drawLine(line_x1, line_y1, line_x2, line_y2);

            // Translate the line
            int tx = 50, ty = 50;
            translateLine(&line_x1, &line_y1, &line_x2, &line_y2, tx, ty);
            drawLine(line_x1, line_y1, line_x2, line_y2);
            break;
        }

        case 2: {
            // Triangle
            int tri_x1 = 100, tri_y1 = 300, tri_x2 = 200, tri_y2 = 100, tri_x3 = 300, tri_y3 = 300;
            drawTriangle(tri_x1, tri_y1, tri_x2, tri_y2, tri_x3, tri_y3);

            printf("Choose the transformation for the triangle:\n");
            printf("1. Rotate around the origin\n");
            printf("2. Rotate around a fixed point\n");
            printf("3. Scale with respect to the origin\n");
            printf("4. Scale with respect to a fixed point\n");
            int transform_choice;
            scanf("%d", &transform_choice);

            switch (transform_choice) {
                case 1: {
                    // Rotate the triangle around the origin
                    float angle = 45 * M_PI / 180.0f;
                    rotatePointOrigin(&tri_x1, &tri_y1, angle);
                    rotatePointOrigin(&tri_x2, &tri_y2, angle);
                    rotatePointOrigin(&tri_x3, &tri_y3, angle);
                    drawTriangle(tri_x1, tri_y1, tri_x2, tri_y2, tri_x3, tri_y3);
                    break;
                }

                case 2: {
                    // Rotate the triangle around a fixed point (200, 200)
                    float angle = 45 * M_PI / 180.0f;
                    int fixedX = 200, fixedY = 200;
                    rotatePointFixed(fixedX, fixedY, &tri_x1, &tri_y1, angle);
                    rotatePointFixed(fixedX, fixedY, &tri_x2, &tri_y2, angle);
                    rotatePointFixed(fixedX, fixedY, &tri_x3, &tri_y3, angle);
                    drawTriangle(tri_x1, tri_y1, tri_x2, tri_y2, tri_x3, tri_y3);
                    break;
                }

                case 3: {
                    // Scale the triangle with respect to the origin
                    int scaleFactor = 2;
                    scaleTriangle(tri_x1, tri_y1, tri_x2, tri_y2, tri_x3, tri_y3, scaleFactor);
                    break;
                }

                case 4: {
                    // Scale the triangle with respect to a fixed point (200, 200)
                    int scaleFactor = 2;
                    int fixedX = 200, fixedY = 200;
                    scaleTriangle(tri_x1, tri_y1, tri_x2, tri_y2, tri_x3, tri_y3, scaleFactor);
                    break;
                }

                default:
                    printf("Invalid choice for transformation!\n");
                    break;
            }
            break;
        }

        case 3: {
            // Circle
            int circle_x = 400, circle_y = 200, circle_radius = 50;
            drawCircle(circle_x, circle_y, circle_radius);

            printf("Choose the transformation for the circle:\n");
            printf("1. Scale with respect to the origin\n");
            printf("2. Scale with respect to a fixed point\n");
            int transform_choice;
            scanf("%d", &transform_choice);

            switch (transform_choice) {
                case 1: {
                    // Scale the circle with respect to the origin
                    int scaleFactor = 2;
                    scaleCircle(circle_x, circle_y, circle_radius, scaleFactor, 0, 0);
                    break;
                }

                case 2: {
                    // Scale the circle with respect to a fixed point (400, 200)
                    int scaleFactor = 2;
                    int fixedX = 400, fixedY = 200;
                    scaleCircle(circle_x, circle_y, circle_radius, scaleFactor, fixedX, fixedY);
                    break;
                }

                default:
                    printf("Invalid choice for transformation!\n");
                    break;
            }
            break;
        }

        default:
            printf("Invalid choice for shape!\n");
            break;
    }

    getch();
    closegraph();

    return 0;
}
