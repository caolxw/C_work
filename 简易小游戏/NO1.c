/*
C����С��Ϸ1��ʵ�ֵ���С��
ʵ�ֲ��裺
1.����Ļ�����С��
2.�ı�С���λ�á��������������� System("cls");)
3.ʹС����������x,y���������������ٶȱ�����
4.����С�������ٶȡ���ʹ��sleep������
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
    int i, j;
    int x = 0;
    int y = 5;

    int high = 10;//С�����ı߽�
    int bottom = 0;
    int right = 10;
    int left =0;

    int v_x = 1;//С����ٶ�
    int v_y = 1;

    while(1){
        x = x + v_x;
        y = y + v_y;
        system("cls");//��������

        //���С���Ϸ��Ŀ���
        for (i = 0; i < x; i++)
            printf("\n");
        //���С����ߵĿո�
        for (j = 0; j < y; j ++)
            printf(" ");
        printf ("o");//���С��
        //printf ("\n");
        Sleep(500);//�ȴ�������

        if(x == high || x == 0){
            v_x = -v_x;
            printf("\a");
        }
        if(y == 0 || y ==right){
            v_y = -v_y;
            printf("\a");
        }
    }

    return 0;
}
