#include <stdio.h>
#include <windows.h>
#include <math.h>

// 커서 이동 함수
void gotoXY(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

int main() {
    int x0 = 40;  // 원의 중심 x 좌표
    int y0 = 12;  // 원의 중심 y 좌표
    int r = 5;    // 반지름
    double angle = 0;  // 초기 각도

    while (1) {
        // 이전 화면 지우기
        gotoXY(0, 0);
        printf("\033[2J"); // 전체 화면 지우기 (선택사항)

        // 회전하는 점의 위치 계산
        int x = (int)(x0 + r * cos(angle));
        int y = (int)(y0 + r * sin(angle));

        // 별 출력
        gotoXY(x, y);
        printf("*");

        // 잠시 대기
        Sleep(100);

        // 각도 증가
        angle += 0.1;

        // 너무 커지지 않게 angle 값 제한
        if (angle > 6.28) { // 2π 넘어가면 리셋
            angle = 0;
        }
    }

    return 0;
}
