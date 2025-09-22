#include <stdio.h>
#include <windows.h>

int drawPoint(int x, int y) {
    printf("\x1B[%d;%dH*", y, x);
    return 0;
}

int main() {
    int posx = 3, posy = 3;      // 시작점
    int dir = 0;                  // 0:→, 1:↓, 2:←, 3:↑
    int steps[4] = { 10, 5, 10, 5 };
    int dx[4] = { 1, 0,-1, 0 };
    int dy[4] = { 0, 1, 0,-1 };

    system("cls");

    while (dir < 4) {
        int len = 0;
        // 수평은 10칸, 수직은 5칸
        // (모서리 중복을 피하고 싶으면 시작/끝 인덱스를 조절)
        while (len < steps[dir]) {
            posx += dx[dir];
            posy += dy[dir];
            drawPoint(posx, posy);
            Sleep(100);
            len = len + 1;
        }
        dir = dir + 1;
    }

    // 커서 아래로
    printf("\x1B[%d;%dH", posy + 2, 0);
    return 0;
}
