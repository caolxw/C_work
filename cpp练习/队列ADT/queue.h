/*队列模拟市场顾客排队咨询
    queue.h头文件
    构建接口
*/

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define MAX 10

typedef struct item
{
    long arrive;//顾客到达时间
    int processtime;//资讯时间
} Item;

typedef struct node
{
    Item item;
    struct node *next;
} Node;

typedef struct queue
{
    Node * front;//指向队列列首的指针
    Node * rear;//只想队列列尾的指针
    int items;//队列中的项目数
} Queue;

//初始化队列
void InitializerQueue(Queue * pq);

//检查队列是否为空
int QueueisEmpty(const Queue * pq);

//检查队列是否已满
int QueueisFull(const Queue * pq);

//确定队列中的项目数
int QueueCount(const Queue * pq);

//向队列尾部添加项目
int QueueAdd(Queue * pq, Item item);

//把队列头部删除
int QueueDelete(Queue * pq);

//清空队列
void QueueFree(Queue * pq);

#endif // QUEUE_H_INCLUDED
