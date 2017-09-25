#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int Mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef struct Date
{
    int year;
    int month;
    int day;
} date;

void isLeapYear(int year);
date get_date();
int CaculateWeekDay(date da);
void user_input1(date da);
void user_input2();
void user_input3();
void user_input4();
void show(date da);
void show_menu();
int check_input(date d);

//判断是否是闰年，如果是，把二月份设置为29天
void isLeapYear(int year)
{
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        Mon[2] = 29;
}

//获取当前时间，并保存到变量中
date get_date()
{
    time_t tp;
    struct tm * p;
    time(&tp);
    p = localtime(&tp);

    date today;
    today.year = p ->tm_year + 1900;
    today.month = p ->tm_mon + 1;
    today.day = p ->tm_mday;

    return today;
}

//换算日期与星期
int CaculateWeekDay(date da)
{
    int y = da.year;
    int m = da.month;
    int d = da.day;

    if(m == 1||m == 2) {
        m += 12;
        y --;
    }
    int Week =(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;

    return Week;
}

//用户输入
void user_input1(date da)
{
    char input;
    if((scanf("%c", &input)) != NULL){
        while(getchar() != '\n'){
            continue;//清空输入行
        }
        if (input == 'a')//上一个月
        {
            if(da.month == 1){
                da.year --;
                da.month = 12;
            }
            else da.month --;
            show(da);
        }

        if (input == 'd')//下一个月
        {
            if(da.month == 12){
                da.month = 1;
                da.year ++;
            }
            else da.month ++;
            show(da);
        }

        if (input == 'm')//菜单
            show_menu();
    }

}
void user_input2()
{
    char input;

    if((scanf("%c", &input)) != NULL){
        while(getchar() != '\n'){
            continue;//清空输入行
        }
        if (input == 'q')
            exit(0);
        if (input == 'a')
            user_input3();
        if (input == 'b')
            user_input4();
    }
}

void user_input3()
{
    system("cls");//清屏函数
    date seek_date;
    int i;
    for(i = 0; i < 20; i ++)
        printf("=");
    do{
        printf("\n请输入年和月（用-相隔）:\n");
        scanf("%d-%d", &seek_date.year, &seek_date.month);
        seek_date.day = 1;
        while(getchar() != '\n'){
            continue;
        }
    }while(!check_input(seek_date));

    show(seek_date);
}

void user_input4()
{
    system("cls");
    date seek_date;
    int i;
    for(i = 0; i < 20; i ++)
        printf("=");
    do{
        printf("\n\n请输入年月日（用-相隔）:\n");
        scanf("%d-%d-%d", &seek_date.year, &seek_date.month, &seek_date.day);
        while(getchar() != '\n'){
            continue;
        }
    }while(!check_input(seek_date));

    int week = CaculateWeekDay(seek_date);
    switch(week)
    {
        case 0: printf("星期一\n"); break;
        case 1: printf("星期二\n"); break;
        case 2: printf("星期三\n"); break;
        case 3: printf("星期四\n"); break;
        case 4: printf("星期五\n"); break;
        case 5: printf("星期六\n"); break;
        case 6: printf("星期日\n"); break;
    }

    printf("\"m\"返回菜单\n");
    char input;
    if((scanf("%c",&input)) != NULL){
        while(getchar() != '\n'){
            continue;
        }

        if (input == 'm')
            show_menu();
    }
}

//打印日历
void show(date da)
{
    system("cls");
    da.day = 1;
    int week = CaculateWeekDay(da);//确定当月第一天是星期几
    //打印注释
    printf("注：按a和d翻动日历，按m显示菜单\n");
    //按格式打印某年某月
    printf("\n%d年 %d月 \n",da.year,da.month);
    printf("\n");
    //按格式打印星期
    printf("%-6s%-6s%-6s%-6s%-6s%-6s%-6s\n","Sun.", "Mon.", "Tues.", "Wed.", "Thur.", "Fri.", "Sat.");

    switch (week)
    {
        case 0: printf("%-6s","");break;
        case 1: printf("%-12s",""); break;
        case 2: printf("%-18s",""); break;
        case 3: printf("%-24s",""); break;
        case 4: printf("%-30s",""); break;
        case 5: printf("%-36s",""); break;
        case 6: break;
    }

    int i;
    isLeapYear(da.year);//判断是否是闰年
    for(i = 0; i < Mon[da.month]; i ++){
        int weekday = (week + i)%7;
        printf("%-6d",i+1);

        if(weekday == 5)
            printf("\n");//周六时换行
    }
    printf("\n");
    user_input1(da);
}

//打印菜单
void show_menu()
{
    system("cls");
    int i;
    for(i = 0; i < 8; i ++)
        printf("-");
    printf("主菜单");
    for(i = 0; i < 8; i ++)
        printf("-");
    printf("\n");

    printf("\n请根据提示选择：\n\n");

    printf("a.日历查询\n");
    printf("b.日期查询\n");
    printf("q.退出\n");

    user_input2();
}

//检查用户输入
int check_input(date d)
{

    if(d.month > 12 || d.month < 1){
        printf("Input Error:月份无效\n");
        return 0;
    }
    if(d.day < 1 || d.day > Mon[d.month]){
        printf("Input Error:日期无效\n");
        return 0;
    }

    return 1;
}

int main()
{
    date today = get_date();
    show(today);
}
