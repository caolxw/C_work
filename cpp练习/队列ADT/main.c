/*����ģ�����

�������˿���ѯʱ�����1��2��3����
      ��ѯ�������ֻ����10���Ŷ�
      ��Ҫ��ѯ���˵ĳ���ʱ���������
�������ѯ̨ƽ��ÿСʱ�Ӵ��Ŀ���
      ÿλ����ƽ���ȴ�ʱ��
      ����ƽ������
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

#define HOUR_TO_MIN 60.0

//�ֲ�����
int newCustomer(double x)//����Ƿ����µĹ˿͡�����з���1��û�з���0
{
    if (rand() * x / RAND_MAX < 1)
        return 1;
    else return 0;
}

Item BuildCustomer(long time)//�����µĹ˿���Ϣ
{
    Item newCust;
    newCust.arrive = time;
    newCust.processtime = rand() % 3 + 1;

    return newCust;
}


int main()
{
    Queue line;
    Item customer;//�˿͵�����
    int hours;//ģ���ʱ��
    int perhour;//ÿСʱ�˿���
    long cycle, cyclelimit;
    int away = 0;//������������ܾ��Ĺ˿���
    int customers = 0;//������еĹ˿���
    long saved = 0;//�����񵽵Ĺ˿���
    long linesum;//�ۼƶ��г���
    double permin;//�˿͵���ƽ�����ʱ��
    int wait = 0;//�ӵ�ǰ����ѯ̨��������Ҫ��ʱ��
    long sum_wait = 0;//�ۼƵȴ�ʱ��


    InitializerQueue(&line);//��ʼ������

    //���л�������
    puts("Case Study:Sigmund Lander's Advice Booth\n");
    puts("Enter the number of simulation hours:");
    scanf("%d",&hours);
    cyclelimit = hours * HOUR_TO_MIN;
    puts("Enter the average number customers per hour:");
    scanf("%d",&perhour);
    permin = HOUR_TO_MIN / perhour;

    for(cycle = 0; cycle < cyclelimit; cycle ++){
        //��ÿ������鿴�Ƿ����µĹ˿�����
        if(newCustomer(permin)){
            //���¹˿�����
            if(QueueisFull(&line)){
                //��������
                away ++;
            }
            else{
                customers ++;
                customer = BuildCustomer(cycle);
                if(QueueAdd(&line, customer)){}
                    //printf("A new customer joined.\n");
            }
        }
        //��ÿ���Ӳ鿴�Ƿ��й˿���ѯ��ɣ��뿪����
        if(wait <= 0 && !QueueisEmpty(&line)){
            //�˿���ѯ���
            if(QueueDelete(&line)){}
                //printf("Next customer.\n");
            wait = customer.processtime;//���õȴ�ʱ��
            saved ++;
            sum_wait += cycle - customer.arrive;
        }

        if(wait > 0)
            wait --;
        linesum += QueueCount(&line);
    }

    //���
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
