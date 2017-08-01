/*
C语言小游戏4：flappy bird
实现步骤：
1.小鸟简单下落。按空格键上升。
2.设置障碍物并使之从右向左移。
3.设置游戏得分与结束。
4.设置新的障碍物随机出现。
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int width, high;//游戏屏幕的大小
int bird_x, bird_y;//鸟的位置
int bird_v;//鸟的下落速度
int bar_y, bar_top, bar_bottom;//障碍物的位置
int bar_v;//障碍物的移动速度
int score;//游戏得分

void gotoxy(int x,int y)//类似于清屏函数
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
    printf("得分：%d\n",score);

}

void updateWithoutInput()
{
    bird_x += bird_v;
    bar_y -= bar_v;

    if (bird_y == bar_y){
        if (bird_x < bar_bottom && bird_x > bar_top)
            score ++;
        else {
            printf("游戏失败！\n");
            exit(0);
        }
    }

    if (bird_x >= high || bird_x <= 0){
        printf("游戏失败！\n");
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
