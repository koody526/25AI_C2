#include <stdio.h>
#include <windows.h>

int drawPoint(int x, int y) {
    printf("\x1B[%d;%dH*", y, x);
    return 0;
}

int main() {
    int posx = 3, posy = 3;      // ������
    int dir = 0;                  // 0:��, 1:��, 2:��, 3:��
    int steps[4] = { 10, 5, 10, 5 };
    int dx[4] = { 1, 0,-1, 0 };
    int dy[4] = { 0, 1, 0,-1 };

    system("cls");

    while (dir < 4) {
        int len = 0;
        // ������ 10ĭ, ������ 5ĭ
        // (�𼭸� �ߺ��� ���ϰ� ������ ����/�� �ε����� ����)
        while (len < steps[dir]) {
            posx += dx[dir];
            posy += dy[dir];
            drawPoint(posx, posy);
            Sleep(100);
            len = len + 1;
        }
        dir = dir + 1;
    }

    // Ŀ�� �Ʒ���
    printf("\x1B[%d;%dH", posy + 2, 0);
    return 0;
}
