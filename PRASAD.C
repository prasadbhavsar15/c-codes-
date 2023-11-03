#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

int x, y, az, w, xa, ya, ra, ch, ch1, ch2, i;
float x1, y1, az1, w1, dx, dy, theta, x1s, y1s, sx, sy;
int a[10], b[10], da, db;
float a1[10], b1[10];

void main() {
    int gm, gr;
    clrscr();
    detectgraph(&gm, &gr);
    initgraph(&gm, &gr, "d:\\tc\\BGI");
    printf("Enter the upper left corner of rectangle: \n");
    scanf("%d%d", &x, &y);
    printf("Enter the Lower Right Corner Of The Rectangle: \n");
    scanf("%d%d", &az, &w);
    rectangle(x, y, az, w);
    da = az - x;
    db = w - y;
    a[0] = x;
    b[0] = y;
    a[1] = x + da;
    b[1] = y;
    a[2] = x + da;
    b[2] = y + db;
    a[3] = x;
    b[3] = y + db;

    while (1) {
        printf("***** 2D TRANSFORMATIONS*****\n");
        printf("1. Translation.\n2. Rotation.\n3. Scaling\n4. Reflection\n5. Shearing\n6. Exit\n\nEnter your choice\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                detectgraph(&gm, &gr);
                initgraph(&gm, &gr, "d:\\tc\\BGI");
                rectangle(x, y, az, w);
                printf("*****Translation******");
                printf("Enter the value of shift vector :\n");
                scanf("%f,%f", &dx, &dy);
                x1 = x + dx;
                y1 = y + dy;
                az1 = az + dx;
                w1 = w + dy;
                rectangle(x1, y1, az1, w1);
                break;

            case 2:
                detectgraph(&gm, &gr);
                initgraph(&gm, &gr, "d:\\tc\\BGI");
                rectangle(x, y, az, w);
                printf("*****Rotation*****");
                printf("Enter the value of fixed point and angle of rotation:\n");
                scanf("%d,%d,%d", &xa, &ya, &ra);
                theta = (float)(ra * (3.14 / 180));
                for (i = 0; i < 4; i++) {
                    a1[i] = (xa + ((a[i] - xa) * cos(theta) - (b[i] - ya) * sin(theta)));
                    b1[i] = (ya + ((a[i] - xa) * sin(theta) + (b[i] - ya) * cos(theta)));
                }
                for (i = 0; i < 4; i++) {
                    if (i != 3)
                        line(a1[i], b1[i], a1[i + 1], b1[i + 1]);
                    else
                        line(a1[i], b1[i], a1[0], b1[0]);
                }
                break;

            case 3:
                detectgraph(&gm, &gr);
                initgraph(&gm, &gr, "d:\\tc\\BGI");
                rectangle(x, y, az, w);
                printf("*****Scaling*****");
                printf("Enter the Value of Scaling Factor :\n");
                scanf("%f,%f", &sx, &sy);
                x1 = x * sx;
                y1 = y * sy;
                az1 = az * sx;
                w1 = w * sy;
                rectangle(x1, y1, az1, w1);
                break;

            case 4:
                detectgraph(&gm, &gr);
                initgraph(&gm, &gr, "d:\\tc\\BGI");
                rectangle(x, y, az, w);
                printf("*****Reflection*****");
                printf("1. About x-axis\n2. About y-axis\n3. About Both Axes\nEnter Your Choice:\n");
                scanf("%d", &ch1);
                switch (ch1) {
                    case 1:
                        printf("Enter The Fixed Point\n");
                        scanf("%d,%d", &xa, &ya);
                        theta = (float)(90 * (3.14 / 180));
                        for (i = 0; i < 4; i++) {
                            a1[i] = (xa + ((a[i] - xa) * cos(theta) - (-b[i] - ya) * sin(theta)));
                            b1[i] = (ya + ((a[i] - xa) * sin(theta) + (-b[i] - ya) * cos(theta)));
                        }
                        for (i = 0; i < 4; i++) {
                            if (i != 3)
                                line(a1[i], b1[i], a1[i + 1], b1[i + 1]);
                            else
                                line(a1[i], b1[i], a1[0], b1[0]);
                        }
                        break;

                    case 2:
                        printf("Enter The Fixed Point\n");
                        scanf("%d,%d", &xa, &ya);
                        theta = (float)(270 * (3.14 / 180));
                        for (i = 0; i < 4; i++) {
                            a1[i] = (xa + ((-a[i] - xa) * cos(theta) - (b[i] - ya) * sin(theta)));
                            b1[i] = (ya + ((-a[i] - xa) * sin(theta) - (b[i] - ya) * cos(theta)));
                        }
                        for (i = 0; i < 4; i++) {
                            if (i != 3)
                                line(a1[i], b1[i], a1[i + 1], b1[i + 1]);
                            else
                                line(a1[i], b1[i], a1[0], b1[0]);
                        }
                        break;

                    case 3:
                        printf("Enter The Fixed Point\n");
                        scanf("%d,%d", &xa, &ya);
                        theta = (float)(180 * (3.14 / 180));
                        for (i = 0; i < 4; i++) {
                            a1[i] = (xa + ((-a[i] - xa) * cos(theta) - (b[i] - ya) * sin(theta)));
                            b1[i] = (ya + ((-a[i] - xa) * sin(theta) - (b[i] - ya) * cos(theta)));
                        }
                        for (i = 0; i < 4; i++) {
                            if (i != 3)
                                line(a1[i], b1[i], a1[i + 1], b1[i + 1]);
                            else
                                line(a1[i], b1[i], a1[0], b1[0]);
                        }
                        break;
                }
                break;

            case 5:
                // Shearing
                detectgraph(&gm, &gr);
                initgraph(&gm, &gr, "d:\\tc\\BGI");
                rectangle(x, y, az, w);
                printf("***Shearing****\n\n");
                printf("1. x-direction Shear\n2. y-direction shear\nEnter your choice :\n");
                scanf("%d", &ch2);
                switch (ch2) {
                    case 1:
                        // x-direction Shear
                        printf("Enter the Value Of Shear :\n");
                        scanf("%f", &x1s);
                        x1 = x + (y * x1s);
                        y1 = y;
                        az1 = az + (w * x1s);
                        w1 = w;
                        rectangle(x1, y1, az1, w1);
                        break;

                    case 2:
                        // y-direction shear
                        printf("Enter the value of shear");
                        scanf("%f", &y1s);
                        x1 = x;
                        y1 = y + (x * y1s);
                        az1 = az;
                        w1 = w + (az * y1s);
                        rectangle(x1, y1, az1, w1);
                        break;
                }
                break;

            case 6:
                // Exit the program
                exit(0);
        }
    }
    getch();
}
