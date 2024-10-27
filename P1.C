#include <graphics.h>
#include <conio.h>
#include <math.h>

int main() {
    int gd = DETECT, gm;
    int centerX, centerY;
    int earthX,earthY;
    int sunRadius = 50;
    int earthRadius = 10;
    int angle = 0;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    centerX = getmaxx() / 2;
    centerY = getmaxy() / 2;

    while (!kbhit()) {
        cleardevice();

        // Draw the Sun
        setcolor(YELLOW);
        circle(centerX, centerY, sunRadius);
        floodfill(centerX, centerY, YELLOW);

        // Calculate Earth's position
	earthX = centerX + 100 * cos(angle * 3.14159265 / 180);
	earthY = centerY + 100 * sin(angle * 3.14159265 / 180);

        // Draw the Earth
        setcolor(LIGHTBLUE);
        circle(earthX, earthY, earthRadius);
        floodfill(earthX, earthY, LIGHTBLUE);

        delay(50); // Adjust the speed of rotation
        angle++;
        if (angle >= 360) {
            angle = 0;
        }
    }

    closegraph();
    return 0;
}
