#include <stdio.h>
#include <windows.h>
#include <math.h>

// 커서 이동
void gotoXY(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

int main() {
    int cx = 20;   // 중심 x
    int cy = 10;   // 중심 y
    int w = 10;    // 가로길이
    int h = 5;     // 세로길이

    double angle = 0.0;

    // 0 ~ 2π 까지 0.1씩 증가
    while (angle < 2 * 3.14) {
        int x, y;

        // 각도를 90도 단위로 나눠서 사각형 테두리 좌표를 만들어냄
        if (angle < 3.14 / 2) {
            // 위쪽 (왼쪽 → 오른쪽)
            x = cx + (int)(w * cos(angle));
            y = cy;
        }
        else if (angle < 3.14) {
            // 오른쪽 (위쪽 → 아래쪽)
            x = cx + w;
            y = cy + (int)(h * sin(angle - 3.14 / 2));
        }
        else if (angle < 3 * 3.14 / 2) {
            // 아래쪽 (오른쪽 → 왼쪽)
            x = cx + (int)(w * cos(angle - 3.14));
            y = cy + h;
        }
        else {
            // 왼쪽 (아래쪽 → 위쪽)
            x = cx;
            y = cy + (int)(h * sin(angle - 3 * 3.14 / 2));
        }

        gotoXY(x, y);
        printf("*");
        Sleep(100);

        angle += 0.2; // 각도 조금씩 증가
    }

    gotoXY(0, cy + h + 3);
    return 0;
}

