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
    int x = 5;
    int y = 10;
    char input;

    int isFire = 0;
    int isKill = 0;

    int ny = 5;//����Ŀ��
    int nx = 2;

    while(1){
        system("cls");

        if (!isKill){
            for (i = 0; i < nx; i ++)
                printf("\n");
            for (j = 0; j < ny; j ++)
                printf(" ");
            printf("+\n");
        }

        if(isFire == 0){
            for (i = 0; i < x; i ++)
                printf("\n");
        }
        else {
            for (i = 0; i < x; i ++){
                for (j = 0; j < y; j ++)
                    printf(" ");
                printf("  |\n");
            }
            isFire = 0;
            if (y + 2 == ny)
                isKill = 1;
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
