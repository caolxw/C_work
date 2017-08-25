/*
C语言小游戏6；飞机游戏再构

*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int top, bottom, left, right;
int screen[100][100];
int player_x, player_y;
int enemy_num;//敌人数量
float s_time, e_time;
int enemy_x[20], enemy_y[20];//敌机位置
int result = 1;
int enemy_time1, enemy_time2;
int speed;

void start_time()//开始时间
{
    s_time = clock();
    enemy_time1 = clock();
}

void end_time()//当前时间
{
    e_time = clock();
    enemy_time2 = clock();
}

void WinorLose()//判断输赢
{
    float Time = e_time - s_time;

    if(Time / 1000.0 >= 100){
        system("cls");
        printf("You Win!!!\n");
        int w;
        for (w = 0; w < 5; w ++)
            system("pause");
    }
    else {
        printf("YOU LOSE!!!\n");
        int l;
        for (l = 0; l < 3; l ++)
            system("pause");
    }
}

void Lose()//判断结束时间
{
    int i;
    for (i = 0; i < enemy_num; i ++){
        if(screen[enemy_x[i]][enemy_y[i]] == 1 || screen[player_x][player_y] == 2){
            result = 0;
            WinorLose();
        }
    }
}

void never_concide()//防止随机敌机位置重复
{
    int a,b;
    for(a = 0; a < enemy_num; a ++){

        for (b = 0; b < enemy_num; b ++){
            if(a != b){

                if(enemy_x[a] == enemy_x[b] && enemy_y[a] == enemy_y[b]){

                    enemy_x[b] = rand()%2 - 1;
                    enemy_y[b] = rand()%2 - 1;
                }
            }
        }
    }
}


void gotoxy(int x, int y)//清屏函数
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void HideCursor()//清除光标的函数
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//隐藏输入符号
}

void chase()//敌机对玩家的追逐
{
    int i;
    for (i = 0; i < enemy_num; i++){
        if(enemy_x[i] < player_x)
            enemy_x[i] += speed;
        if(enemy_x[i] > player_x)
            enemy_x[i] -= speed;
        if(enemy_y[i] < player_y)
            enemy_y[i] += speed;
        if(enemy_y[i] > player_y)
            enemy_y[i] -= speed;
    }
}
void startup()
{
    screen[100][100] = 0;
    //设定屏幕大小
    top = 0;
    left = 0;
    printf("请设定地图大小。\n长：");
    scanf("%d",&bottom);
    printf("宽：");
    scanf("%d",&right);
    printf("请设定敌机数量：");
    scanf("%d",&enemy_num);
    printf("请设定敌机的速度：");
    scanf("%d",&speed);

    if(speed >= 4)
        speed = 3;

    int i, j;

    for (i = 0; i < bottom; i ++){
        for (j = 0; j < right; j ++){
            if(i == top || i == bottom-1){
                screen[i][j] = 3;
            }
            else {
                if(j == left || j == right-1)
                    screen[i][j] = 4;
            }
        }
    }

    for (i = 0; i < enemy_num; i ++){//随机初始化敌机位置
        enemy_x[i] = (rand()%(bottom-top)) + top;
        enemy_y[i] = (rand()%(right-left)) + left;
    }
    player_x = bottom - 2;//确定飞机位置
    player_y = right / 2;

    HideCursor();
    system("cls");

    start_time();
}

void updateWithoutinput()
{
    int i,j;
    for (i = top+1; i < bottom-1; i ++){
        for (j = left+1; j < right-1; j ++){
            screen[i][j] = 0;
        }
    }

    screen[player_x][player_y] = 1;
    for (i = 0; i < enemy_num; i ++){
        screen[enemy_x[i]][enemy_y[i]] = 2;
    }

    if((enemy_time2 - enemy_time1) % speed == 0){
        chase();
    }

    never_concide();
}

void updateWithinput()
{
    char input;
    if (kbhit())
    {
        input = getch();
        if ('w' == input)
            player_x -= 2;
        if ('a' == input)
            player_y -= 2;
        if ('d' == input)
            player_y += 2;
        if ('s' == input)
            player_x += 2;
    }

    if(player_x <= top){
        player_x = top - 1;
        printf("\a");
    }
    if(player_x >= bottom){
        player_x = bottom - 1;
        printf("\a");
    }
    if(player_y <= left){
        player_y = left-1;
        printf("\a");
    }
    if(player_y >= right){
        player_y = right - 1;
        printf("\a");
    }
}

void show()
{
    HideCursor();
    gotoxy(0,0);
   int i, j;

   for(i = 0; i < bottom; i ++){
    for (j = 0; j < right; j ++){
        if(screen[i][j] == 3)
            printf("-");
        if(screen[i][j] == 1)
            printf("@");
        if(screen[i][j] == 0)
            printf(" ");
        if(screen[i][j] == 4)
            printf("|");
        if(screen[i][j] == 2)
            printf("*");
    }
    printf("\n");
   }
   Lose();
   end_time();


   printf("%.2f\n",(e_time - s_time)/1000.0);
}

int main(void)
{
    startup();

    while (result){
        show();

        updateWithoutinput();
        updateWithinput();
    }
     return 0;
}
