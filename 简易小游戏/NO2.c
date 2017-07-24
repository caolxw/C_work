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
    int x = 5;
    int y = 10;
    char input;

    int isFire = 0;
    int isKill = 0;

    int ny = 5;//设立目标
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
