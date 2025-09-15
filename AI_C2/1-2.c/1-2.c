#include <stdio.h>
#include <windows.h>
#include <math.h>

// Ŀ�� �̵�
void gotoXY(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

int main() {
    int cx = 20;   // �߽� x
    int cy = 10;   // �߽� y
    int w = 10;    // ���α���
    int h = 5;     // ���α���

    double angle = 0.0;

    // 0 ~ 2�� ���� 0.1�� ����
    while (angle < 2 * 3.14) {
        int x, y;

        // ������ 90�� ������ ������ �簢�� �׵θ� ��ǥ�� ����
        if (angle < 3.14 / 2) {
            // ���� (���� �� ������)
            x = cx + (int)(w * cos(angle));
            y = cy;
        }
        else if (angle < 3.14) {
            // ������ (���� �� �Ʒ���)
            x = cx + w;
            y = cy + (int)(h * sin(angle - 3.14 / 2));
        }
        else if (angle < 3 * 3.14 / 2) {
            // �Ʒ��� (������ �� ����)
            x = cx + (int)(w * cos(angle - 3.14));
            y = cy + h;
        }
        else {
            // ���� (�Ʒ��� �� ����)
            x = cx;
            y = cy + (int)(h * sin(angle - 3 * 3.14 / 2));
        }

        gotoXY(x, y);
        printf("*");
        Sleep(100);

        angle += 0.2; // ���� ���ݾ� ����
    }

    gotoXY(0, cy + h + 3);
    return 0;
}

