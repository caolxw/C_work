/*
C����С��Ϸ5��������Ϸ

��Ϸ����
ÿ�����󷽸���԰���һ���л��壬���ڱ��ϵ��л�����8�����ڷ���
1�� ���һ��ϸ����Χ��3��ϸ��Ϊ�������ϸ��Ϊ��������ϸ����ԭ��Ϊ������תΪ������ԭ��Ϊ�����򱣳ֲ��䣩
2�� ���һ��ϸ����Χ��2��ϸ��Ϊ�������ϸ��������״̬���ֲ���
3�� ����������£���ϸ��Ϊ��������ϸ����ԭ��Ϊ������תΪ������ԭ��Ϊ�����򱣳ֲ��䣩

ʵ�ֲ��裺
1.������Ϸ��ʼ����
2.��ϸ�����з��ܺ��������õ����ϱ仯��ͼ����
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define HIGH 25//�趨��Ļ��С
#define WIDTH 50

int cell[HIGH][WIDTH];

void gotoxy (int x, int y)//����
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

void startup()//�����ʼ��
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
