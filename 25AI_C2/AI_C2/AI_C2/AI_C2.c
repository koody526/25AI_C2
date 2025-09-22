#include <stdio.h>
#include <windows.h>

// 커서 이동 함수
void gotoXY(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

int main() {
    int x = 5;  // 시작 x좌표
    int y = 5;   // 시작 y좌표
    int i = 0;  // 반복을 위한 변수

    while (i < 26) {  // 총 26개의 별을 그릴 예정
        int px = x;
        int py = y;

        if (i < 10) {
            // 오른쪽 줄: 위 → 아래 방향
            px = x + i;
            py = y;
        }
        else if (i < 13) {
            // 아래줄: 오른쪽 → 왼쪽
            px = x + 9;
            py = y + (i - 9);
        }
        else if (i < 23) {
            // 왼쪽 줄: 아래 → 위
            px = x + (22 - i);
            py = y + 4;
        }
        else {
            // 윗줄: 왼쪽 → 오른쪽
            px = x;
            py = y + (26 - i);
        }

        gotoXY(px, py);
        printf("*");
        Sleep(100);
        i = i + 1;
    }

    gotoXY(0, y + 6);  // 커서를 그림 아래로 이동
    return 0;
}
