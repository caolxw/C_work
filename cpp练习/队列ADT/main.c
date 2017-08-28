/*队伍模拟程序

条件：顾客咨询时间随机1，2，3分钟
      咨询队伍最多只能有10人排队
      需要咨询的人的出现时间是随机的
输出：咨询台平均每小时接待的客人
      每位客人平均等待时间
      队伍平均长度
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

#define HOUR_TO_MIN 60.0

//局部函数
int newCustomer(double x)//检查是否有新的顾客。如果有返回1，没有返回0
{
    if (rand() * x / RAND_MAX < 1)
        return 1;
    else return 0;
}

Item BuildCustomer(long time)//建立新的顾客信息
{
    Item newCust;
    newCust.arrive = time;
    newCust.processtime = rand() % 3 + 1;

    return newCust;
}


int main()
{
    Queue line;
    Item customer;//顾客的属性
    int hours;//模拟的时间
    int perhour;//每小时顾客数
    long cycle, cyclelimit;
    int away = 0;//因队列已满被拒绝的顾客数
    int customers = 0;//加入队列的顾客数
    long saved = 0;//被服务到的顾客数
    long linesum;//累计队列长度
    double permin;//顾客到来平均间隔时间
    int wait = 0;//从当前到咨询台空闲所需要的时间
    long sum_wait = 0;//累计等待时间


    InitializerQueue(&line);//初始化队列

    //队列基本设置
    puts("Case Study:Sigmund Lander's Advice Booth\n");
    puts("Enter the number of simulation hours:");
    scanf("%d",&hours);
    cyclelimit = hours * HOUR_TO_MIN;
    puts("Enter the average number customers per hour:");
    scanf("%d",&perhour);
    permin = HOUR_TO_MIN / perhour;

    for(cycle = 0; cycle < cyclelimit; cycle ++){
        //在每分钟里查看是否有新的顾客增加
        if(newCustomer(permin)){
            //有新顾客增加
            if(QueueisFull(&line)){
                //队列已满
                away ++;
            }
            else{
                customers ++;
                customer = BuildCustomer(cycle);
                if(QueueAdd(&line, customer)){}
                    //printf("A new customer joined.\n");
            }
        }
        //在每分钟查看是否有顾客咨询完成，离开队列
        if(wait <= 0 && !QueueisEmpty(&line)){
            //顾客咨询完成
            if(QueueDelete(&line)){}
                //printf("Next customer.\n");
            wait = customer.processtime;//重置等待时间
            saved ++;
            sum_wait += cycle - customer.arrive;
        }

        if(wait > 0)
            wait --;
        linesum += QueueCount(&line);
    }

    //输出
    if (customers > 0){
        printf("customers accept : %d\n",customers);
        printf("Customers saved : %ld\n",saved);
        printf("turnaways : %d\n",away);
        printf("average queue sizes : %lf\n",(double)linesum / cyclelimit);
        printf("average wait time : %.2lf minutes.\n",(double)sum_wait / saved);
    }
    else printf("No customer.\n");

    QueueFree(&line);
    printf("Done!");

    return 0;


}
