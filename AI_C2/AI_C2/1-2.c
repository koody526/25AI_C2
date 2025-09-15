#include <stdio.h>
#include <windows.h>
#include <math.h>

// Ŀ�� �̵� �Լ�
void gotoXY(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

int main() {
    int x0 = 40;  // ���� �߽� x ��ǥ
    int y0 = 12;  // ���� �߽� y ��ǥ
    int r = 5;    // ������
    double angle = 0;  // �ʱ� ����

    while (1) {
        // ���� ȭ�� �����
        gotoXY(0, 0);
        printf("\033[2J"); // ��ü ȭ�� ����� (���û���)

        // ȸ���ϴ� ���� ��ġ ���
        int x = (int)(x0 + r * cos(angle));
        int y = (int)(y0 + r * sin(angle));

        // �� ���
        gotoXY(x, y);
        printf("*");

        // ��� ���
        Sleep(100);

        // ���� ����
        angle += 0.1;

        // �ʹ� Ŀ���� �ʰ� angle �� ����
        if (angle > 6.28) { // 2�� �Ѿ�� ����
            angle = 0;
        }
    }

    return 0;
}
