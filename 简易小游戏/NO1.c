/*
C语言小游戏1：实现弹跳小球。
实现步骤：
1.在屏幕上输出小球
2.改变小球的位置。（运用清屏函数 System("cls");)
3.使小球弹跳。（在x,y两个方向上增加速度变量）
4.控制小球弹跳的速度。（使用sleep函数）
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
    int i, j;
    int x = 0;
    int y = 5;

    int high = 10;//小球弹跳的边界
    int bottom = 0;
    int right = 10;
    int left =0;

    int v_x = 1;//小球的速度
    int v_y = 1;

    while(1){
        x = x + v_x;
        y = y + v_y;
        system("cls");//清屏函数

        //输出小球上方的空行
        for (i = 0; i < x; i++)
            printf("\n");
        //输出小球左边的空格
        for (j = 0; j < y; j ++)
            printf(" ");
        printf ("o");//输出小球
        //printf ("\n");
        Sleep(500);//等待若干秒

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
