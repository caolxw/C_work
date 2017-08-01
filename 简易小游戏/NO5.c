/*
C语言小游戏5：生命游戏

游戏规则：
每个矩阵方格可以包含一个有机体，不在边上的有机体有8个相邻方格。
1． 如果一个细胞周围有3个细胞为生，则该细胞为生（即该细胞若原先为死，则转为生，若原先为生，则保持不变）
2． 如果一个细胞周围有2个细胞为生，则该细胞的生死状态保持不变
3． 在其它情况下，该细胞为死（即该细胞若原先为生，则转为死，若原先为死，则保持不变）

实现步骤：
1.进行游戏初始化。
2.让细胞进行繁衍和死亡，得到不断变化的图案。
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define HIGH 25//设定屏幕大小
#define WIDTH 50

int cell[HIGH][WIDTH];

void gotoxy (int x, int y)//清屏
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void HideCursor()//隐藏光标
{
     CONSOLE_CURSOR_INFO cursor_info = {1, 0};
     SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void startup()//随机初始化
{
    int i, j;

    for (i = 0; i < HIGH; i ++){
        for (j = 0; j < WIDTH; j ++){
            cell[i][j] = rand()%2;
        }
    }

}

void show()
{
    gotoxy(0, 0);
    //HideCursor();

    int i, j;
    for (i = 0; i < HIGH; i ++){
        for (j = 0; j < WIDTH; j ++){
            if(cell[i][j] == 1)
                printf("*");
            else printf(" ");
        }

        printf("\n");
    }
    Sleep(100);
}

void updateWithoutinput(){
    int neibour[8] = {0};
    int neibourNum = 0;
    int nextCell[HIGH][WIDTH];

    int i, j, k;

    for (i = 0; i < HIGH; i ++){

        for (j =0 ; j < WIDTH; j ++){
                if (i == 0){
                    if(j == 0){
                        neibour[4] = cell[i][j+1];
                        neibour[6] = cell[i+1][j];
                        neibour[7] = cell[i+1][j+1];
                    }
                    else if (j == WIDTH-1){
                        neibour[3] = cell[i][j-1];
                        neibour[5] = cell[i+1][j-1];
                        neibour[6] = cell[i+1][j];
                    }
                    else{
                        neibour[3] = cell[i][j-1];
                        neibour[4] = cell[i][j+1];

                        neibour[5] = cell[i+1][j-1];
                        neibour[6] = cell[i+1][j];
                        neibour[7] = cell[i+1][j+1];
                    }

                }

                else if (i == HIGH-1){
                    if(j == 0){
                        neibour[1] = cell[i-1][j];
                        neibour[2] = cell[i-1][j+1];
                        neibour[4] = cell[i][j+1];
                    }
                    else if (j == WIDTH-1){
                        neibour[0] = cell[i-1][j-1];
                        neibour[1] = cell[i-1][j];
                        neibour[3] = cell[i][j-1];
                    }
                    else{
                        neibour[0] = cell[i-1][j-1];
                        neibour[1] = cell[i-1][j];
                        neibour[2] = cell[i-1][j+1];

                        neibour[3] = cell[i][j-1];
                        neibour[4] = cell[i][j+1];
                    }
                }
                else if (j == 0){
                        if(i == 0){
                            neibour[4] = cell[i][j+1];

                            neibour[6] = cell[i+1][j];
                            neibour[7] = cell[i+1][j+1];
                        }
                        else if (i == HIGH-1){
                            neibour[1] = cell[i-1][j];
                            neibour[2] = cell[i-1][j+1];

                            neibour[4] = cell[i][j+1];
                        }
                        else {
                            neibour[1] = cell[i-1][j];
                            neibour[2] = cell[i-1][j+1];

                            neibour[4] = cell[i][j+1];

                            neibour[6] = cell[i+1][j];
                            neibour[7] = cell[i+1][j+1];
                        }
                }
                else if(j == WIDTH-1){
                        if (i == 0){
                            neibour[3] = cell[i][j-1];

                            neibour[5] = cell[i+1][j-1];
                            neibour[6] = cell[i+1][j];
                        }
                        else if (i == HIGH-1){
                            neibour[0] = cell[i-1][j-1];
                            neibour[1] = cell[i-1][j];

                            neibour[3] = cell[i][j-1];
                        }
                        else {
                        neibour[0] = cell[i-1][j-1];
                        neibour[1] = cell[i-1][j];

                        neibour[3] = cell[i][j-1];

                        neibour[5] = cell[i+1][j-1];
                        neibour[6] = cell[i+1][j];}
                }

                else{
                    neibour[0] = cell[i-1][j-1];
                    neibour[1] = cell[i-1][j];
                    neibour[2] = cell[i-1][j+1];

                    neibour[3] = cell[i][j-1];
                    neibour[4] = cell[i][j+1];

                    neibour[5] = cell[i+1][j-1];
                    neibour[6] = cell[i+1][j];
                    neibour[7] = cell[i+1][j+1];
                }

            for (k = 0; k < 8; k ++){
                neibourNum += neibour[k];
            }

            if(neibourNum == 3)
                nextCell[i][j] = 1;
            else if (neibourNum == 2)
                nextCell[i][j] = cell[i][j];
            else nextCell[i][j] = 0;

            neibourNum = 0;
        }
    }

    for (i = 0; i < HIGH; i ++){
        for (j = 0; j < WIDTH; j ++){
            cell[i][j] = nextCell[i][j];
        }
    }
}

void updateWithinput(){

}

int main(void)
{
    startup();

    while (1){
        show();

        updateWithoutinput();
        updateWithinput();
    }
}
