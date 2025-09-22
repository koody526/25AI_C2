#include <stdio.h>
#include <windows.h>

// 커서 이동 함수
void gotoXY(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

int main() {
    int ox = 10, oy = 5; // 왼쪽 위 기준 좌표

    // 폭탄 본체 (B)
    gotoXY(ox - 4, oy + 0); printf("(B)");

    // 심지 출력
    gotoXY(ox, oy + 0); printf("----+");
    gotoXY(ox, oy + 1); printf("+--+|");
    gotoXY(ox, oy + 2); printf("|+*||");
    gotoXY(ox, oy + 3); printf("|+-+|");
    gotoXY(ox, oy + 4); printf("+---+");

    int x = ox + 2; // * 시작 위치
    int y = oy + 2;

    // 심지 이동 (단계만 시뮬레이션)
    // 1단계: 왼쪽
    gotoXY(x, y); printf(" "); x--; gotoXY(x, y); printf("*"); Sleep(150);
    // 2단계: 아래
    gotoXY(x, y); printf(" "); y++; gotoXY(x, y); printf("*"); Sleep(150);
    // 3단계: 오른쪽 2
    for (int i = 0;i < 2;i++) { gotoXY(x, y); printf(" "); x++; gotoXY(x, y); printf("*"); Sleep(150); }
    // 4단계: 위 2
    for (int i = 0;i < 2;i++) { gotoXY(x, y); printf(" "); y--; gotoXY(x, y); printf("*"); Sleep(150); }
    // 5단계: 왼쪽 3
    for (int i = 0;i < 3;i++) { gotoXY(x, y); printf(" "); x--; gotoXY(x, y); printf("*"); Sleep(150); }
    // 6단계: 아래 3
    for (int i = 0;i < 3;i++) { gotoXY(x, y); printf(" "); y++; gotoXY(x, y); printf("*"); Sleep(150); }
    // 7단계: 오른쪽 4
    for (int i = 0;i < 4;i++) { gotoXY(x, y); printf(" "); x++; gotoXY(x, y); printf("*"); Sleep(150); }
    // 8단계: 위 4
    for (int i = 0;i < 4;i++) { gotoXY(x, y); printf(" "); y--; gotoXY(x, y); printf("*"); Sleep(150); }
    // 9단계: 왼쪽 4 → 마지막은 (B)에 닿음
    for (int i = 0;i < 4;i++) { gotoXY(x, y); printf(" "); x--; gotoXY(x, y); printf("*"); Sleep(150); }

    // (B)에 도착 → 모든 심지 삭제
    for (int row = 0; row < 5; row++) {
        gotoXY(ox, oy + row);
        printf("     "); // 심지 부분 지우기
    }

    // 폭발 애니메이션
    for (int k = 0; k < 5; k++) {
        system("cls"); // 화면 전체 지우기
        if (k % 2 == 0) {
            printf("\033[31;1m████████  BOOM!!!  ████████\033[0m\n");
            printf("\033[31;1m██████████████████████████\033[0m\n");
        }
        else {
            printf("\033[33;1m<<<<<<<<  BOOM!!!  >>>>>>>>\033[0m\n");
            printf("\033[33;1m***************************\033[0m\n");
        }
        Sleep(300);
    }

    gotoXY(0, 20);
    return 0;
}
