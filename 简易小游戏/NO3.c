/*
C����С��Ϸ3���ع��ɻ���Ϸ

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int high, width;//��Ϸ����ߴ�
int position_x, position_y;//�ɻ���λ��
int bullet_x, bullet_y;//�ӵ���λ��
int enemy_x[2], enemy_y[2];//�л���λ��
int score;//�÷�


void gotoxy(int x,int y)//��������������������ƶ���ԭ��λ�ý����ػ�
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void HideCursor()//���ع��
{
     CONSOLE_CURSOR_INFO cursor_info = {1, 0};
     SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


void startup()
{
    high = 20;
    width = 20;

    position_x = high - 2;
    position_y = width / 2;

    bullet_x = -1;
    bullet_y = position_y;

    int i;
    for (i = 0; i < 2; i ++){
        enemy_x[i] = 0;
        enemy_y[i] = rand()%width;
    }

    score = 0;
}

void show()
{
    HideCursor();
    gotoxy(0,0);

    int i, j, k;

    for (i = 0; i < high; i ++){
        for (j = 0; j < width; j ++){
            if (i == position_x && j == position_y)
                printf("*");
            else if (i == bullet_x && j == bullet_y)
                printf("|");
            else if (i == enemy_x[1] && j == enemy_y[1])
                printf("@");
            else if (i == enemy_x[0] && j == enemy_y[0])
                printf("@");
            else printf(" ");
        }
        printf("\n");
    }

    printf("�÷֣�%d\n",score);
}

void updateWithoutInput()
{
    //�ӵ��ƶ�
    static int speed1 = 0;
    if (speed1 == 10){
        bullet_x --;
        speed1 = 0;
    }
    else speed1 ++;

    //�жϵ÷�
    int j;
    for (j = 0; j < 2; j ++){
        if (bullet_x == enemy_x[j] && bullet_y == enemy_y[j]){
            score ++;
            enemy_x[j] = 0;
            enemy_y[j] = rand()%width;
            bullet_x = -1;
        }
        if(enemy_x[j] > high){
            enemy_x[j] = 0;
            enemy_y[j] = rand()%width;
        }

        if (position_x == enemy_x[j] && position_y == enemy_y[j]){
            printf("��Ϸ����\n");
            exit(0);
        }
    }

    //�л��ƶ�
    static int speed = 0;
    int i;
    if (speed == 15){
        for (i = 0; i < 2; i ++){
            enemy_x[i] ++;
        }
        speed = 0;
    }
    else speed ++;
}

void updateWithInput()
{
    char input;

    if(kbhit()){
        input = getch();

        if(input == 'w')
            position_x --;
        if(input == 's')
            position_x ++;
        if(input == 'a')
            position_y --;
        if(input == 'd')
            position_y ++;
        if (input == ' '){
            bullet_x = position_x - 1;
            bullet_y = position_y;
        }
        if(input == 'q'){
            printf("��Ϸ����\n");
            exit(0);
        }

        //���Ʒɻ�������
        if (position_y <= 0){
            printf("\a");
            position_y = 0;
        }
        if (position_y > width){
            printf("\a");
            position_y = width - 1;
        }
        if (position_x > high){
            printf("\a");
            position_x = high - 1;
        }
    }
}


int main (void)
{
    startup();//���ݳ�ʼ��

    while (1){
        show();//��ʾ�ɻ�

        updateWithoutInput();
        updateWithInput();
    }
}
