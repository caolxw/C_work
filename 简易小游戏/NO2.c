/*
C语言小游戏2：简易飞机游戏。
实现步骤：
1.通过输入swad来控制飞机的移动。
2.改善输入函数，输入时不用回车，输入能直接调用函数。（使用getch()函数）
3.用变量记录飞机是否射击。
4.设立目标，控制飞机击中。
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

    int ny = 1;//设立目标
    int nx = 1;

    int v_x = 1;
    int v_y = 1;

    int right = 20;
    int left = 0;

    while(1){
        system("cls");

        //判断得分
        if(isKill == 1) {
                scores += 1;
                isKill = 0;
                ny = 1 + (int)(10.0 * rand()/(RAND_MAX + 1.0));//重新生成随机目标
                nx = 1 + (int)(10.0 * rand()/(RAND_MAX + 1.0));
        }

        if(nx == x + 2){
            ny = 1 + (int)(10.0 * rand()/(RAND_MAX + 1.0));//重新生成随机目标
            nx = 1 + (int)(10.0 * rand()/(RAND_MAX + 1.0));
        }

        printf("得分：%d",scores);

        ny = ny + v_y;
        nx = nx + v_x;

        //显示目标
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

        //判断游戏失败
        if(nx == x && ny == y + 2){
            printf("游戏结束\a");
            exit(0);
        }
        if (nx == x + 1 && ny >= y && ny <= y + 4){
            printf("游戏结束\a");
            exit(0);

        }

        //飞机的形态
        for (j = 0; j < y; j ++)
            printf(" ");
        printf("  *\n");
        for (j = 0; j < y; j ++)
            printf(" ");
        printf("*****\n");
        for (j = 0; j < y; j ++)
            printf(" ");
        printf(" * * ");

        //根据输入swad来控制移动
        //if (kbhit()){  //判断是否有输入

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
