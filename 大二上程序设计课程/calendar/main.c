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

//�ж��Ƿ������꣬����ǣ��Ѷ��·�����Ϊ29��
void isLeapYear(int year)
{
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        Mon[2] = 29;
}

//��ȡ��ǰʱ�䣬�����浽������
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

//��������������
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

//�û�����
void user_input1(date da)
{
    char input;
    if((scanf("%c", &input)) != NULL){
        while(getchar() != '\n'){
            continue;//���������
        }
        if (input == 'a')//��һ����
        {
            if(da.month == 1){
                da.year --;
                da.month = 12;
            }
            else da.month --;
            show(da);
        }

        if (input == 'd')//��һ����
        {
            if(da.month == 12){
                da.month = 1;
                da.year ++;
            }
            else da.month ++;
            show(da);
        }

        if (input == 'm')//�˵�
            show_menu();
    }

}
void user_input2()
{
    char input;

    if((scanf("%c", &input)) != NULL){
        while(getchar() != '\n'){
            continue;//���������
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
    system("cls");//��������
    date seek_date;
    int i;
    for(i = 0; i < 20; i ++)
        printf("=");
    do{
        printf("\n����������£���-�����:\n");
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
        printf("\n\n�����������գ���-�����:\n");
        scanf("%d-%d-%d", &seek_date.year, &seek_date.month, &seek_date.day);
        while(getchar() != '\n'){
            continue;
        }
    }while(!check_input(seek_date));

    int week = CaculateWeekDay(seek_date);
    switch(week)
    {
        case 0: printf("����һ\n"); break;
        case 1: printf("���ڶ�\n"); break;
        case 2: printf("������\n"); break;
        case 3: printf("������\n"); break;
        case 4: printf("������\n"); break;
        case 5: printf("������\n"); break;
        case 6: printf("������\n"); break;
    }

    printf("\"m\"���ز˵�\n");
    char input;
    if((scanf("%c",&input)) != NULL){
        while(getchar() != '\n'){
            continue;
        }

        if (input == 'm')
            show_menu();
    }
}

//��ӡ����
void show(date da)
{
    system("cls");
    da.day = 1;
    int week = CaculateWeekDay(da);//ȷ�����µ�һ�������ڼ�
    //��ӡע��
    printf("ע����a��d������������m��ʾ�˵�\n");
    //����ʽ��ӡĳ��ĳ��
    printf("\n%d�� %d�� \n",da.year,da.month);
    printf("\n");
    //����ʽ��ӡ����
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
    isLeapYear(da.year);//�ж��Ƿ�������
    for(i = 0; i < Mon[da.month]; i ++){
        int weekday = (week + i)%7;
        printf("%-6d",i+1);

        if(weekday == 5)
            printf("\n");//����ʱ����
    }
    printf("\n");
    user_input1(da);
}

//��ӡ�˵�
void show_menu()
{
    system("cls");
    int i;
    for(i = 0; i < 8; i ++)
        printf("-");
    printf("���˵�");
    for(i = 0; i < 8; i ++)
        printf("-");
    printf("\n");

    printf("\n�������ʾѡ��\n\n");

    printf("a.������ѯ\n");
    printf("b.���ڲ�ѯ\n");
    printf("q.�˳�\n");

    user_input2();
}

//����û�����
int check_input(date d)
{

    if(d.month > 12 || d.month < 1){
        printf("Input Error:�·���Ч\n");
        return 0;
    }
    if(d.day < 1 || d.day > Mon[d.month]){
        printf("Input Error:������Ч\n");
        return 0;
    }

    return 1;
}

int main()
{
    date today = get_date();
    show(today);
}
