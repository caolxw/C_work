/*
C����С��Ϸ2�����׷ɻ���Ϸ��
ʵ�ֲ��裺
1.ͨ������swad�����Ʒɻ����ƶ���
2.�������뺯��������ʱ���ûس���������ֱ�ӵ��ú�������ʹ��getch()������
3.�ñ�����¼�ɻ��Ƿ������
4.����Ŀ�꣬���Ʒɻ����С�
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void)
{
    int i, j;
    int x = 15;
    int y = 5;
    char input;

    int isFire = 0;
    int isKill = 0;
    int scores = 0;

    int ny = 1;//����Ŀ��
    int nx = 1;

    int v_x = 1;
    int v_y = 1;

    int right = 20;
    int left = 0;

    while(1){
        system("cls");

        //�жϵ÷�
        if(isKill == 1) {
                scores += 1;
                isKill = 0;
                ny = 1 + (int)(10.0 * rand()/(RAND_MAX + 1.0));//�����������Ŀ��
                nx = 1 + (int)(10.0 * rand()/(RAND_MAX + 1.0));
        }

        if(nx == x + 2){
            ny = 1 + (int)(10.0 * rand()/(RAND_MAX + 1.0));//�����������Ŀ��
            nx = 1 + (int)(10.0 * rand()/(RAND_MAX + 1.0));
        }

        printf("�÷֣�%d",scores);

        ny = ny + v_y;
        nx = nx + v_x;

        //��ʾĿ��
        for (i = 0; i < nx; i ++)
            printf("\n");
        for (j = 0; j < ny; j ++)
            printf(" ");
        printf("+\n");

        if (nx == left || nx == right)
            v_y = -v_y;

        if(isFire == 0){
            for (i = 0; i < (x-nx); i ++)
                printf("\n");
        }
        else {
            for (i = 0; i < (x-nx); i++){
                for (j = 0; j < y; j++)
                    printf(" ");
                printf("  |\n");
            }
            isFire = 0;
            if (ny == y + 2){
                printf("\a");
                isKill = 1;
            }

        }

        //�ж���Ϸʧ��
        if(nx == x && ny == y + 2){
            printf("��Ϸ����\a");
            exit(0);
        }
        if (nx == x + 1 && ny >= y && ny <= y + 4){
            printf("��Ϸ����\a");
            exit(0);

        }

        //�ɻ�����̬
        for (j = 0; j < y; j ++)
            printf(" ");
        printf("  *\n");
        for (j = 0; j < y; j ++)
            printf(" ");
        printf("*****\n");
        for (j = 0; j < y; j ++)
            printf(" ");
        printf(" * * ");

        //��������swad�������ƶ�
        //if (kbhit()){  //�ж��Ƿ�������

            input = getch();
            if (input == 's')
                x = x + 1;
            if (input == 'w')
                x = x - 1;
            if (input == 'a')
                y = y - 1;
            if (input == 'd')
                y = y + 1;
            if (input == ' ')
                isFire = 1;
        //}
    }
    return 0;
}
