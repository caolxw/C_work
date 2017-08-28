#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


/*---局部函数---*/
void CopyItem(Item item, Node * pn)
{
    pn -> item = item;
}

//初始化队列，是队列为空
void InitializerQueue(Queue * pq)
{
    pq -> items = 0;
    pq -> front = NULL;
    pq -> rear = NULL;
}

//检查队列是否为空
//若为空返回1，否则返回0
int QueueisEmpty(const Queue * pq)
{
    if(pq -> items == 0)
        return 1;
    else return 0;
}

//检查队列是否已满
//若已满返回1，否则返回0
int QueueisFull(const Queue * pq)
{
    if(pq -> items >= MAX)
        return 1;
    else return 0;
}

//确定队列中的项目数
int QueueCount(const Queue * pq)
{
    return (pq -> items);
}

//向队列尾部添加项目
int QueueAdd(Queue * pq, Item item)
{
    Node * pnew;

    if(QueueisFull(pq)){
        fprintf(stderr,"Queue is fulled!\n");
        return 0;
    }

    pnew = (Node *)malloc(sizeof(Node));
    if(pnew == NULL){
        fprintf(stderr,"Unable to allocate memory!\n");
        return 0;
    }
    CopyItem(item, pnew);
    pnew -> next = NULL;
    if (QueueisEmpty(pq)){
        //空队列
        pq -> front = pnew;
    }
    else{
        //非空队列
        pq -> rear -> next = pnew;
    }
    pq -> rear = pnew;
    pq -> items ++ ;
    return 1;
}

//删除队列头部项目
int QueueDelete(Queue * pq)
{
    Node * pt;
    if(QueueisEmpty(pq)){
        fprintf(stderr, "Nothing to delete.");
        return 0;
    }
    pt = pq ->front;
    pq ->front = pq ->front ->next;
    free(pt);

    if(pq->items == 1){
        //队列只有一个项目
        pq ->rear = NULL;
    }
    pq ->items --;

    return 1;
}

//清空队列
void QueueFree(Queue * pq)
{
    if(pq ->items != 0)
        QueueDelete(pq);
}
