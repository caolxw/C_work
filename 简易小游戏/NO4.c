/*
C����С��Ϸ4��flappy bird
ʵ�ֲ��裺
1.С������䡣���ո��������
2.�����ϰ��ﲢʹ֮���������ơ�
3.������Ϸ�÷��������
4.�����µ��ϰ���������֡�
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int width, high;//��Ϸ��Ļ�Ĵ�С
int bird_x, bird_y;//���λ��
int bird_v;//��������ٶ�
int bar_y, bar_top, bar_bottom;//�ϰ����λ��
int bar_v;//�ϰ�����ƶ��ٶ�
int score;//��Ϸ�÷�

void gotoxy(int x,int y)//��������������
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void starup()
{
    width = 20;
    high = 15;

    bird_x = high / 2;
    bird_y = 1;

    bar_y = width / 2;
    bar_top = high / 4;
    bar_bottom = high / 2;

    bird_v = 1;
    bar_v = 1;
    score = 0;
}

void show()
{
    gotoxy(0,0);
    int i, j;

    for (i = 0; i < high; i ++){
        for (j = 0; j < width; j ++){
            if(i == bird_x && j == bird_y)
                printf("@");
            else if (j == bar_y && (i <= bar_top || i >= bar_bottom))
                printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    printf("�÷֣�%d\n",score);

}

void updateWithoutInput()
{
    bird_x += bird_v;
    bar_y -= bar_v;

    if (bird_y == bar_y){
        if (bird_x < bar_bottom && bird_x > bar_top)
            score ++;
        else {
            printf("��Ϸʧ�ܣ�\n");
            exit(0);
        }
    }

    if (bird_x >= high || bird_x <= 0){
        printf("��Ϸʧ�ܣ�\n");
        exit(0);
    }

    if (bar_y < 0){
        bar_y = width;
        int flag = 1;
        int temp = 0;

        while (flag){
            temp = rand()%(int)(high*0.8);
            if (temp > 2)
                flag = 0;
        }
        if (score <= 7){
            bar_top = temp - 2;
            bar_bottom = temp + 2;
        }
        else if (score > 15){
            bar_top = temp - 2;
            bar_bottom = temp;
        }
        else {
            bar_top = temp - 2;
            bar_bottom = temp - 1;
        }
    }

    Sleep(150);
}

void updateWithInput()
{
    while(kbhit()){
        char input = getch();

        if (input == ' ')
            bird_x -= 2;
    }

}

int main(void)
{
    starup();

    while (1){
        show();

        updateWithoutInput();
        updateWithInput();
    }
}
